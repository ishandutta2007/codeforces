#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 1e9 + 7, MAXN = 1e5;
vector<int> g[MAXN];
int used[MAXN];

int cnt;
void dfs(int v) {
    cnt++;
    used[v] = 1;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int binpow (int a, int n) {
	int res = 1;
	while (n)
		if (n & 1) {
			res *= a;
			res %= MOD;
			--n;
		}
		else {
			a *= a;
			a %= MOD;
			n >>= 1;
		}
	return res;
}

main() {
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for (int i = 0; i < k; ++i) {
        ans *= n;
        ans %= MOD;
    }
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        if (w == 0) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cnt = 0;
            dfs(i);
            ans -= binpow(cnt, k);
            ans = ((ans % MOD) + MOD) % MOD;
        }
    }
    cout << ans;
    return 0;
}