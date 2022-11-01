#include <cstdio>
#include <algorithm>

using namespace std;

long long n, m, k;

long long f(long long a){return min(m, a);}

long long cnt(long long x){
     long long r = 0;
     for (int i = 1; i <= n; ++i) r += f((x - 1) / i);
     return r;
}

int main(){
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    //printf("%I64d\n", cnt(6));
    long long lo = 1, hi = n * m, mid = (lo + hi + 1) / 2;
    while (lo != hi){
          if (cnt(mid) >= k) hi = mid - 1;
          else lo = mid;
          mid = (lo + hi + 1) / 2;
    }
    printf("%I64d\n", lo);
    return 0;
}