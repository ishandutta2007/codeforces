// Hydro submission #62c5630f8672efa577bec026@1657103120203
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define scd second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int maxn = 150001;
const ll mod = 998244353;

ll n, m, a[maxn], pw[maxn], cnt[maxn << 5];
int ch[maxn << 5][2], tot;

void insert(ll x) {
	int p = 0;
	for (int i = 30; ~i; --i) {
		++cnt[p];
		int k = ((x >> i) & 1);
		if (ch[p][k] == -1) {
			ch[p][k] = ++tot;
		}
		p = ch[p][k];
	}
	++cnt[p];
}

ll dfs(int u, int v, int d) {
	if (u == -1 && v == -1) {
		return 1;
	}
	if (u == -1) {
		return pw[cnt[v]];
	}
	if (v == -1) {
		return pw[cnt[u]];
	}
	if (u == v) {
		if (d < 0) {
			return pw[cnt[u]];
		}
		if (m & (1LL << d)) {
			return dfs(ch[u][0], ch[u][1], d - 1);
		} else {
			return (dfs(ch[u][0], ch[u][0], d - 1) + dfs(ch[u][1], ch[u][1], d - 1) + mod - 1) % mod;
		}
	}
	if (d < 0) {
		return pw[cnt[u] + cnt[v]];
	}
	if (m & (1LL << d)) {
		return dfs(ch[u][0], ch[v][1], d - 1) * dfs(ch[u][1], ch[v][0], d - 1) % mod;
	} else {
		ll res = (dfs(ch[u][0], ch[v][0], d - 1) + dfs(ch[u][1], ch[v][1], d - 1) + mod - 1) % mod;
		if (ch[u][0] != -1 && ch[u][1] != -1) {
			res = (res + (pw[cnt[ch[u][0]]] - 1) * (pw[cnt[ch[u][1]]] - 1) % mod) % mod;
		}
		if (ch[v][0] != -1 && ch[v][1] != -1) {
			res = (res + (pw[cnt[ch[v][0]]] - 1) * (pw[cnt[ch[v][1]]] - 1) % mod) % mod;
		}
		return res;
	}
}

void solve() {
	memset(ch, -1, sizeof(ch));
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		insert(a[i]);
	}
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw[i] = pw[i - 1] * 2 % mod;
	}
	printf("%lld\n", (dfs(0, 0, 30) + mod - 1) % mod);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}