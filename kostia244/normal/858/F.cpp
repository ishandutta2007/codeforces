//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 2e5 + 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ld = long double;
int n, m;
vector<vi> g;
vi h;
vector<pair<int, pair<int, int>>> ans;
int dfs(int v, int p) {
	vi t;
	for(auto i : g[v]) {
		if(i==p) continue;
		if(h[i]>h[v]) continue;
		if(!h[i]) {
			h[i] = h[v]+1;
			if(dfs(i, v))
				t.pb(i);
		} else
			t.pb(i);
	}
	while(t.size()>1) {
		ans.pb({v, {t[t.size()-1], t[t.size()-2]}});
		t.pop_back(), t.pop_back();
	}
	if(p!=-1&&t.size()) {
		ans.pb({v, {t[t.size()-1], p}});
		t.pop_back();
		return 0;
	}
//	cout << v << ")v " << g[v].size() << "\n";
// 	assert(t.empty());
	return 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
// 	if(m&1) return cout << "No solution", 0;
	g.resize(n+1);
	h.resize(n+1);
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
//	for(int i = 1; i <= n; i++)
//		shuffle(all(g[i]), rng);
	for(int i = 1; i <= n; i++)
		if(!h[i])
			h[i] = 1,dfs(i, -1);
	cout << ans.size() << "\n";
	for(auto i : ans)
		cout << i.second.first << " " << i.first << " " << i.second.second << "\n";
}