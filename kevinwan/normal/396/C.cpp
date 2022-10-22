#include<bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll seg[600000],pen[600000];
int n;
int id[300001],d[300001],s[300001],hd[300001],par[300001];
vector<int>g[300001];
void fff(int x) {
	s[x] = 1;
	for (int y : g[x]) {
		par[y] = x;
		d[y] = d[x] + 1;
		fff(y);
		s[x] += s[y];
	}
}
int cur=1,num;
void dfs(int x) {
	hd[x] = cur;
	id[x] = ++num;
	for (int y : g[x]) {
		if (s[y] * 2 >= s[x])dfs(y);
	}
	for (int y : g[x]) {
		cur = y;
		if (s[y] * 2 < s[x])dfs(y);
	}
}
void update(int x, ll s, ll p) { for (; x <= n; x += x & -x)seg[x] = (seg[x] + s) % mod, pen[x] = (pen[x] + p) % mod; }
ll squery(int x) { ll s = 0; for (; x; x -= x & -x)s = (s + seg[x]) % mod; return s; }
ll pquery(int x) { ll p = 0; for (; x; x -= x & -x)p = (p + pen[x]) % mod; return p; }
ll depth;
ll qu(int a, int b) {
	return squery(id[b]) - squery(id[a] - 1) - (depth)*(pquery(id[b]) - pquery(id[a] - 1))%mod;
}
ll query(int a) {
	ll ans = 0;
	depth = d[a];
	while (a) {
		ans += qu(hd[a], a);
		ans %= mod;
		a = par[hd[a]];
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	int q, i,a,b,c;
	for (i = 2; i <= n; i++)scanf("%d", &a), g[a].push_back(i);
	fff(1);
	dfs(1);
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d%d%d", &a, &b, &c);
			update(id[a], (b+1LL*c*d[a])%mod, c);
		}
		else {
			scanf("%d", &a);
			ll ans = (query(a) + mod) % mod;
			printf("%lld\n", ans);
		}
	}
}