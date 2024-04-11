#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdint>
#include <cstdlib>

using namespace std;
int n,m,a,b;

static inline int32_t __attribute__((always_inline)) popcnt1(uint32_t x){
    int32_t result;
    __asm__("popcnt %1, %0" : "=r" (result) : "r" (x));
    return result;
}

static inline int popcnt2(int x){
    return __builtin_popcount(x);
}

static inline int popcnt3(int x){
    int r = 0;
    while (x) {
        if(x&1) r++;
        x>>=1;
    }
    return r;
}

int main(){
    scanf("%d %d %d %d",&n,&m,&a,&b);
    int res = min(n*a, (n%m)*a + (n/m) * b);
    res = min(res, ((n+m-1)/m)*b);
    int px = 1;
    for (long long i=0; i<200000000; i++) {
        px *= popcnt1(n*m*a*b);
    }
    if(px == 123) return 0;
    printf("%d",res);
}