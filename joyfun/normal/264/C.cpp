#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int N = 100005;
const long long INF = 1000000000000000000LL;

int n, q, v[N], c[N];
long long dp[N];
pair<long long, int> tot[2];

long long solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    long long sum = 0, ans = 0;
    for (int i = 1; i <= n; i++)
        dp[i] = -INF;
    tot[0] = make_pair(0LL, 0);
    tot[1] = make_pair(-INF, 0);
    for (int i = 1; i <= n; i++) {
        long long tmp = dp[c[i]] + 1LL * v[i] * a;
        for (int j = 0; j < 2; j++) {
            if (tot[j].second != c[i])
                tmp = max(tmp, tot[j].first + 1LL * v[i] * b);
        }
        int f = 0;
        for (int j = 0; j < 2; j++) {
            if (tot[j].second == c[i]) {
                tot[j].first = max(tot[j].first, tmp);
                f = 1;
            }
        }
        if (!f) {
            if (tmp > tot[0].first) {
                tot[1] = tot[0];
                tot[0].first = tmp;
                tot[0].second = c[i];
            } else if (tmp > tot[1].first) {
                tot[1].first = tmp;
                tot[1].second = c[i];
            }
        }
        if (tot[0].first < tot[1].first) swap(tot[0], tot[1]);
        dp[c[i]] = max(dp[c[i]], tmp);
        ans = max(ans, dp[c[i]]);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    while (q--) printf("%lld\n", solve());
    return 0;
}