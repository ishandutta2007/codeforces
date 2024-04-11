#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1<<17, mod = 1e9 + 7;
int n, m, k;
struct fr {
	ll x, y;
	fr(ll x = 0, ll y = 1) : x(x), y(y) {}
	friend bool operator<(const fr& a, const fr&b) {
		return a.x*b.y < b.x*a.y;
	}
};
set<pair<fr, int>> a;
int deg[maxn], rm[maxn], bad[maxn];
vector<int> g[maxn];
void add(int v) {
	rm[v] = 0;
	for(auto &i : g[v]) if(!rm[i]) {
		a.erase({fr(deg[i], g[i].size()), i});
		a.insert({fr(++deg[i], g[i].size()), i});
		deg[v]++;
	}
	a.insert({fr(deg[v], g[v].size()), v});
}
void rem(int v) {
	rm[v] = 1;
	a.erase({fr(deg[v], g[v].size()), v});
	for(auto &i : g[v]) if(!rm[i]) {
		a.erase({fr(deg[i], g[i].size()), i});
		a.insert({fr(--deg[i], g[i].size()), i});
		deg[v]--;
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int t, i = 0; i < k; i++) cin >> t, bad[t] = 1;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	memset(rm, 1, sizeof rm);
	for(int i = 1; i <= n; i++) if(!bad[i]) add(i);
	pair<fr, int> ans = {fr(0, 1), 0};
	int oa = a.size();
	for(int i = 0; i <= oa; i++) {
		ans = max(ans, {a.empty()?0:a.begin()->first, -i});
		if(!a.empty()) {
			rem(a.begin()->second);
		}
	}
	for(int i = 1; i <= n; i++) if(!bad[i]) add(i);
	for(int i = 0; i < -ans.second; i++) {
		rem(a.begin()->second);
	}
	cerr << ans.first.x << " " << ans.first.y << endl;
	vector<int> rs;
	for(int i = 1; i <= n; i++) if(!rm[i]) rs.push_back(i);
	cout << rs.size() << endl;
	for(auto &i : rs) cout << i << " "; cout << endl;
}