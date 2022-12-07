#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 300005;
const ll inf = (1ll<<60);
int n, m, L[N], R[N], id[N], idx;
vi g[N], ad[N], de[N];
ll dp[N];

struct Q {
	int u, v, c;
	void read() {
		scanf("%d%d%d", &u, &v, &c);
	}
} q[N];

void go(int u, int p) {
	L[u] = idx + 1;
	for (int i = 0; i < sz(ad[u]); i++) id[ad[u][i]] = ++idx;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (v == p) continue;
		go(v, u);
	}
	R[u] = idx;
}

#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)

struct Node {
	ll Min, lazy;
	void gao(ll f) {
		lazy = min(inf, lazy + f);
		Min = min(inf, Min + f);
	}
} nd[N<<2];

void pu(int x) {
	nd[x].Min = min(nd[lson(x)].Min, nd[rson(x)].Min);
}

void pd(int x) {
	ll &f = nd[x].lazy;
	if (f) {
		nd[lson(x)].gao(f);
		nd[rson(x)].gao(f);
		f = 0;
	}
}

void build(int L, int R, int x = 1) {
	nd[x].Min = nd[x].lazy = 0;
	if (L == R) return;
	int mid = (L + R)>>1;
	build(L, mid, lson(x));
	build(mid + 1, R, rson(x));
}

void add(int l, int r, ll w, int L, int R, int x = 1) {
	if (l > r) return;
	if (L >= l && R <= r) {
		nd[x].gao(w);
		return;
	}
	int mid = (L + R)>>1;
	pd(x);
	if (l <= mid) add(l, r, w, L, mid, lson(x));
	if (r > mid) add(l, r, w, mid + 1, R, rson(x));
	pu(x);
}

ll get(int l, int r, int L, int R, int x = 1) {
	if (l > r) return inf;
	if (L >= l && R <= r) return nd[x].Min;
	int mid = (L + R)>>1;
	ll ans = inf;
	pd(x);
	if (l <= mid) ans = min(ans, get(l, r, L, mid, lson(x)));
	if (r > mid) ans = min(ans, get(l, r, mid + 1, R, rson(x)));
	pu(x);
	return ans;
}

int f = 1;

void dfs(int u, int p) {
	ll sum = 0;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (v == p) continue;
		dfs(v, u);
		sum += dp[v];
	}
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (v == p) continue;
		add(L[v], R[v], sum - dp[v], 1, idx);
	}
	if (u != 1) {
		for (int i = 0; i < sz(ad[u]); i++)
			add(id[ad[u][i]], id[ad[u][i]], sum + q[ad[u][i]].c, 1, idx);
		for (int i = 0; i < sz(de[u]); i++)
			add(id[de[u][i]], id[de[u][i]], inf, 1, idx);
		dp[u] = get(L[u], R[u], 1, idx);
	} else dp[u] = sum;
	if (dp[u] == inf) f = 0;
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		g[u].pb(v); g[v].pb(u);
	}
	for (int i = 1; i <= m; i++) {
		q[i].read();
		ad[q[i].u].pb(i); de[q[i].v].pb(i);
	}
	go(1, 1);
	build(1, idx);
	dfs(1, 1);
	if (!f) dp[1] = -1;
	printf("%lld\n", dp[1]);
	return 0;
}