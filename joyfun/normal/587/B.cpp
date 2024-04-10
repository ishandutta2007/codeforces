#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000005;
const int MOD = 1000000007;

int n, k, a[N];
long long l;
pair<int, int> p[N];
int pn;
int dp[N], sum[N];

int main() {
    scanf("%d%lld%d", &n, &l, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n * k; i++) p[pn++] = make_pair(a[i % n], i);
    sort(p, p + pn);
    int ans = 0;
    for (int i = 0; i < pn; i++) {
        if (p[i].second < n) dp[p[i].second] = 1;
        else dp[p[i].second] = sum[p[i].second / n - 1];
        sum[p[i].second / n] = (sum[p[i].second / n] + dp[p[i].second]) % MOD;
        if (p[i].second < l)
            ans = (ans + ((l - p[i].second - 1) / n + 1) % MOD * dp[p[i].second]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}