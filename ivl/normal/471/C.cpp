#include <cstdio>

using namespace std;

long long f(long long x){
     return x * (x + 1) * 3 / 2 - x;
}

long long n;

int main(){
    scanf("%I64d", &n);
    long long lo = 0, hi = 10000000, mid = (lo + hi + 1) / 2;
    while (lo != hi){
          if (f(mid) > n) hi = mid - 1;
          else lo = mid;
          mid = (lo + hi + 1) / 2;
    }
    while ((lo * 2 - n) % 3) --lo;
    long long x = 1;
    while ((x * 2 - n) % 3) ++x;
    x = lo - x;
    if (x < 0) printf("0\n");
    else printf("%I64d\n", x / 3 + 1);
    return 0;
}