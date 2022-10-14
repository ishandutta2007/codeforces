#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1000000007ll;

struct dsu {
	vi r, p;
	void init(int n) {
		r.assign(n+1, 1);
		p.assign(n+1, 0);
		for(int i = 0; i <= n; i++) p[i] = i;
	}
	int par(int i) {
		if(i == p[i]) return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i == j)return;
		if(r[i]<r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[i] == r[j];
	}
};

int n, m;
ll timer = 0, base = 0, dp[200200][18], mx[200200][18];
vi tin, tout;
vector<pair<int, ll>> t[200100];
vector<pair<ll, pair<ll, ll>>> el, oel;

void dfs(int v = 1, int p = 1, ll cst = 0) {
	tin[v] = timer++;
	dp[v][0] = p;
	mx[v][0] = cst;
	for(int i = 1; i < 18; i++) {
		dp[v][i] = dp[dp[v][i-1]][i-1];
		mx[v][i] = max(mx[v][i-1], mx[dp[v][i-1]][i-1]);
	}
	for(auto i : t[v]) if(i.first != p){dfs(i.first, v, i.second);}
	tout[v] = timer-1;
}

bool par(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

ll query(ll a, ll b) {
	ll ans = 0;
	for(int i = 17; i>=0; i--) {
		if(dp[a][i]&&!par(dp[a][i], b)) {
			ans = max(mx[a][i], ans);
			a = dp[a][i];
		}
	}
	for(int i = 17; i>=0; i--) {
		if(dp[b][i]&&!par(dp[b][i], a)) {
			ans = max(mx[b][i], ans);
			b = dp[b][i];
		}
	}
	if(!par(a, b))
		ans = max(ans, mx[a][0]);
	if(!par(b, a))
		ans = max(ans, mx[b][0]);
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	for(int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		el.pb({c, {f, t}});
		oel.pb({c, {f, t}});
	}
	sort(all(el));
	dsu d;
	d.init(n);
	for(auto i : el) {
		ll a, b, c;
		tie(a, b) = i.second;
		c = i.first;
		if(d.par(a) == d.par(b)) continue;
		d.unite(a, b);
		t[a].pb({b, c});
		t[b].pb({a, c});
		base += c;
	}
	tin.resize(n+1);
	tout.resize(n+1);
	dfs();
	for(auto i : oel) {
		ll a, b, c;
		tie(a, b) = i.second;
		c = i.first;
		cout << base-query(a, b)+c << "\n";
	}
}