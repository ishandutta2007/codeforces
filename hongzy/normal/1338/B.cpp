#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, ans, d[N];
vector<int> G[N];
bool use[2], uf[N];
void dfs(int u, int fa = 0) {
	d[u] = fa ? (d[fa] ^ 1) : 0;
	if(G[u].size() == 1) {
		use[d[u]] = 1;
		if(uf[fa]) ans --;
		uf[fa] = 1;
	}
	for(int v : G[u]) if(v ^ fa) {
		dfs(v, u);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v); G[v].pb(u);
	}
	int rt = 1;
	for(int i = 1; i <= n; i ++)
		if(G[i].size() != 1) rt = i;
	ans = n - 1; dfs(rt);
	printf("%d %d\n", use[0] && use[1] ? 3 : 1, ans);
	return 0;
}