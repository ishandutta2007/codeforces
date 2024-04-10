#include<bits/stdc++.h>
#define maxn 200000
#define int ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, k;
vvi g;
int now = 0;
vi l, r;
vi par;
vector<bool> used;
int t[maxn * 4 + 7], lp[maxn * 4 + 7];
vi vers;

void update(int now, int l, int r, int l1, int r1, int val) {
	if(l > r1 || l1 > r) {
		return;
	}
	if(l1 <= l && r <= r1) {
		t[now] += val;
		lp[now] += val;
		return;
	}
	int mid = (l + r) / 2;
	update(now * 2, l, mid, l1, r1, val);
	update(now * 2 + 1, mid + 1, r, l1, r1, val);
	t[now] = max(t[now * 2], t[now * 2 + 1]) + lp[now];
}

int get_max(int now, int l, int r) {
	if(l == r) return l;
	int mid = (l + r) / 2;
	if(t[now * 2] >= t[now * 2 + 1]) {
		return get_max(now * 2, l, mid);
	} else {
		return get_max(now * 2 + 1, mid + 1, r);
	}
}

void dfs(int v, int p) {
	par[v] = p;
	l[v] = n + 1;
	r[v] = -1;
	for(int u : g[v]) {
		if(u == p) continue;
		dfs(u, v);
		l[v] = min(l[v], l[u]);
		r[v] = max(r[v], r[u]);
	}
	if(r[v] == -1) {
		l[v] = r[v] = now++;
		vers.push_back(v);
	}
}




signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> k;
    g.resize(n);
    for(int i = 0; i < n - 1; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    l.resize(n);
    r.resize(n);
    par.resize(n);
    dfs(0, -1);
    used.assign(n, false);
    for(int i = 0; i < n; i++) {
    	update(1, 0, now - 1, l[i], r[i], 1);
    }
    ll ans = -(ll)(n / 2) * (n - n / 2);
    int painted = 0;
    for(int i = 0; i < min(now, k); i++) {
    	int id1 = get_max(1, 0, now - 1);
    	int v = vers[id1];
    	while(v != -1 && !used[v]) {
    		used[v] = true;
    		++painted;
    		update(1, 0, now - 1, l[v], r[v], -1);
    		v = par[v];
    	}
    	int r = i + 1;
    	int b = min(n / 2, n - painted);
    	//cout << r << ' ' << b << endl;
    	ans = max(ans, (ll)(r - b) * (n - r - b));
    }
    if(k > now && n / 2 > now) {
    	ans = max(ans, (ll)(min(n / 2, k)) * (n - min(n / 2, k)));
    }
    cout << ans;
}