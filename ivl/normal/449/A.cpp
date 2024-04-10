#include <cstdio>
#include <algorithm>

using namespace std;

long long n, m, k;

long long attempt(long long a, long long b){
     //printf("%I64d %I64d\n", a, b);
     if (a >= n || b >= m) return 0;
     if (a < 0) a = 0;
     if (b < 0) b = 0;
     return (n / (a + 1)) * (m / (b + 1));
}

long long bin(long long x){
     long long lo = 1, hi = 2000000000, mid = (lo + hi) / 2;
     while (lo != hi){
           if (n / mid < x) hi = mid - 1;
           else lo = mid;
           mid = (lo + hi + 1) / 2;
     }
     return lo - 1;
}

int main(){
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    if (n - 1 + m - 1 < k){printf("-1\n"); return 0;}
    long long r = 0;
    for (int i = 1; (i - 1) * (i - 1) <= n; ++i){
        r = max(r, attempt(i - 1, k - i + 1));
        long long x = bin(i);
        r = max(r, attempt(x, k - x));
    }
    for (int i = 1; (i - 1) * (i - 1) <= m; ++i){
        r = max(r, attempt(k - i + 1, i - 1));
        swap(n, m);
        long long x = bin(i);
        swap(n, m);
        r = max(r, attempt(k - x, x));
    }
    printf("%I64d\n", r);
    return 0;
}