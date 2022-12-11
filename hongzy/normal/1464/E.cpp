#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
const int M = 512 + 10;
const int mod = 998244353;
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
		if(b & 1) ans = (ll)ans * a % mod;
	return ans;
}

int n, m, sg[N];
bool vis[N], oc[N];
vector<int> G[N];
void dfs(int u) {
	if(vis[u]) return ;
	vis[u] = 1;
	for(int v : G[u]) dfs(v);
	for(int v : G[u]) oc[sg[v]] = 1;
	for(sg[u] = 0; oc[sg[u]]; sg[u] ++) ;
	for(int v : G[u]) oc[sg[v]] = 0;
}
int a[M][M];
void gauss(int n) {
	static int inv[M];
	rep(i, 1, n) {
		int j = i;
		rep(k, i, n) if(a[k][i]) {
			j = k; break ;
		}
		assert(a[j][i]);
		if(j != i) {
			rep(k, i, n + 1) swap(a[i][k], a[j][k]);
		}
		inv[i] = qpow(a[i][i], mod - 2);
		for(j = i + 1; j <= n; j ++) {
			int t = (ll)a[j][i] * inv[i] % mod;
			rep(k, i, n + 1) {
				a[j][k] = (a[j][k] + (mod - t) * (ll)a[i][k]) % mod;
			}
		}
	}
	per(i, n, 1) {
		rep(j, i + 1, n) a[i][n + 1] = (a[i][n + 1] + (mod - a[i][j]) * (ll)a[j][n + 1]) % mod;
		a[i][n + 1] = (ll)a[i][n + 1] * inv[i] % mod;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	rep(i, 1, m) {
		scanf("%d%d", &u, &v);
		G[u].pb(v);
	}
	rep(i, 1, n) dfs(i);
	int k = 1, mx = *max_element(sg + 1, sg + n + 1);
	while(k <= mx) k <<= 1;
	int inv = qpow(n + 1, mod - 2);
	for(int i = 0; i < k; i ++) {
		a[i + 1][i + 1] = 1;
		if(!i) a[i + 1][k + 1] = inv;
		rep(j, 1, n) (a[i + 1][(i ^ sg[j]) + 1] += mod - inv) %= mod;
	}
	gauss(k);
	printf("%d\n", (mod + 1 - a[1][k + 1]) % mod);
	return 0;
}