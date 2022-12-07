#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

const int N = 100005;
typedef long long ll;
const ll MOD = 1000000007;
int n, node[N];
vector<int> g[N];
ll dp[N][2];

ll pow_mod(ll x, ll k) {
    ll ans = 1; 
    while (k) {
        if (k&1) ans = ans * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return pow_mod(x, MOD - 2);
}

void init() {
    scanf("%d", &n);
    int u;
    for (int i = 1; i < n; i++) {
        scanf("%d", &u);
        g[u].push_back(i);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &node[i]);
}

void dfs(int u) {
    if (g[u].size() == 0) {
        dp[u][node[u]] = 1;
        return;
    }
    for (int i = 0; i < g[u].size(); i++)
        dfs(g[u][i]);
    dp[u][0] = dp[u][1] = 1;
    if (node[u]) {
        dp[u][0] = 0;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            dp[u][1] = dp[u][1] * (dp[v][0] + dp[v][1]) % MOD;
        }
    }
    else {
        ll cnt = 0;
        ll mul = 1;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % MOD;
            mul = mul * (dp[v][0] + dp[v][1]) % MOD;
        }
        dp[u][1] = 0;
        for (int i = 0; i < g[u].size(); i++){ 
            int v = g[u][i];
            dp[u][1] = (dp[u][1] + mul * inv((dp[v][0] + dp[v][1]) % MOD) % MOD * dp[v][1]) % MOD;
        }
    }
}

int main() {
    init();
    dfs(0);
    printf("%lld\n", dp[0][1] % MOD);
    //system("pause");
    return 0;
}