#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
const int MOD = 1000000007;

char str[N];
int m, tp, n;
vector<pair<int, int> > g[N];

int dp[N], inv[N], ans[N];

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        k >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d", &m);
    scanf("%s", str);
    int pre = strlen(str);
    for (int i = 0; i < m; i++) {
        scanf("%d", &tp);
        if (tp == 2) {
            scanf("%d", &n);
            g[pre].push_back(make_pair(n, i));
        } else {
            scanf("%s", str);
            pre = strlen(str);
        }
    }
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= 100000; i++) inv[i] = pow_mod(i, MOD - 2);
    for (int i = 1; i <= 100000; i++) {
        if (g[i].size() == 0) continue;
        dp[i] = 1;
        int tmp = 1;
        for (int j = i + 1; j <= 100000; j++) {
            tmp = 1LL * tmp * (j - 1) % MOD * inv[j - i] % MOD * 25 % MOD;
            dp[j] = (1LL * dp[j - 1] * 26 % MOD + tmp) % MOD;
        }
        for (int j = 0; j < g[i].size(); j++) {
            ans[g[i][j].second] = g[i][j].first < i ? 0 : dp[g[i][j].first];
        }
    }
    for (int i = 0; i < m; i++) if (ans[i] != -1) printf("%d\n", ans[i]);
    return 0;
}