#define front         top
#define at            __AT
#define back          __BACK
#define begin         __BEGIN
#define end           __END
#define set           __SET
#define pop_back      __POP_BACK
#define wipe          __WIPE
#define clear         __CLEAR
#define fit           __FIT
#define reserve       __RESERVE
#define push_back     __PUSH_BACK
#define resize        __RESIZE
#define assign        __ASSIGN
#define shrink_to_fit __SHRINK_TO_FIT
#define data          __DATA
#define insert        __INSERT
#define erase         __ERASE
#define sort          __SORT
#define step          __STEP
#define range         __RANGE
#define each          __EACH
#define remove_if     __REMOVE_IF

#define vec pqu
#define HOLD
#include <vec.h>
#undef vec

#define A TEMP(T, pqu)

#define SWAP(x, y) { T temp = *x; *x = *y; *y = temp; }

static inline void
IMPL(A, up)(A* self, size_t n, int (*compare)(T*, T*))
{
    if(n > 0)
    {
        size_t p = (n - 1) / 2;
        T* x = &self->value[n];
        T* y = &self->value[p];
        if(compare(x, y))
        {
            SWAP(x, y);
            IMPL(A, up)(self, p, compare);
        }
    }
}

static inline void
IMPL(A, down)(A* self, size_t n, int (*compare)(T*, T*))
{
    size_t min = 2;
    if(self->size < min)
        return;
    else
    if(self->size == min)
    {
        T* a = &self->value[0];
        T* b = &self->value[1];
        if(!compare(a, b))
            SWAP(a, b);
    }
    else
    {
        size_t l = 2 * n + 1;
        size_t r = 2 * n + 2;
        if(r < self->size)
        {
            size_t index = compare(&self->value[r], &self->value[l]) ? r : l;
            T* x = &self->value[index];
            T* y = &self->value[n];
            if(compare(x, y))
            {
                SWAP(x, y);
                IMPL(A, down)(self, index, compare);
            }
        }
    }
}

static inline void
IMPL(A, push)(A* self, T value, int (*compare)(T*, T*))
{
    IMPL(A, push_back)(self, value);
    IMPL(A, up)(self, self->size - 1, compare);
}

static inline void
IMPL(A, pop)(A* self, int (*compare)(T*, T*))
{
    SWAP(IMPL(A, front)(self), IMPL(A, back)(self));
    IMPL(A, pop_back)(self);
    IMPL(A, down)(self, 0, compare);
}

#undef front
#undef at
#undef back
#undef begin
#undef end
#undef set
#undef pop_back
#undef wipe
#undef clear
#undef fit
#undef reserve
#undef push_back
#undef resize
#undef assign
#undef shrink_to_fit_fit
#undef data
#undef insert
#undef erase
#undef sort
#undef step
#undef range
#undef each
#undef remove_if

#undef T // SEE HOLD.
#undef A
#undef SWAP