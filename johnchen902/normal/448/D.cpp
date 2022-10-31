#include <cstdio>
#include <algorithm>
using namespace std;

#define int // either signed or long long

signed n, m;

long long rankof(long long x) {
    long long rnk = 0;
    for(signed i = 1; i <= n; i++)
        rnk += min(x / i, (long long) m);
    return rnk;
}

signed main(){
    long long k;
    while(scanf("%d %d %I64d", &n, &m, &k) == 3) {
        long long l = 0, r = (long long) n * m; // (l, r]
        while(l + 1 < r) {
            long long mid = (l + r) / 2;
            (rankof(mid) >= k ? r : l) = mid;
        }
        printf("%I64d\n", r);
    }
}