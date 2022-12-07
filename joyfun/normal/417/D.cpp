#include <stdio.h>
#include <string.h>
#include <algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

__int64 one = 1;
const int N = 105;
const int M = (1<<20) + 5;
const __int64 INF = (one<<62);
__int64 b, dp[M];
int i, j, n, m;
struct F {
    __int64 x, k, s;
} f[N];

bool cmp(F a, F b) {
    return a.k < b.k;
}

int main() {
    __int64 ans = INF;
    scanf("%d%d%I64d", &n, &m, &b);
    for (i = 1; i <= n; i++) {
        int num, ss;
        scanf("%I64d%I64d%d", &f[i].x, &f[i].k, &num);
        while (num--) {
            scanf("%d", &ss);
            f[i].s |= (1<<(ss-1));
        }
    }
    int smax = (1<<m);
    sort(f + 1, f + n + 1, cmp);
    for (i = 1; i < smax; i++)
        dp[i] = INF;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < smax; j++) {
            int ss = (j|f[i].s);
            dp[ss] = min(dp[ss], dp[j] + f[i].x);
        }
        ans = min(ans, dp[smax - 1] + f[i].k * b);
    }
    if (ans == INF) ans = -1;
    printf("%I64d\n", ans);
    return 0;
}