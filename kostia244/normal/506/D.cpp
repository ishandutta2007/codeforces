#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 696969569;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct dsu {
	gp_hash_table<int, int> r, p;
	int par(int x) {
		if(p.find(x)==p.end()) return x;
		return p[x] = par(p[x]);
	}
	void unite(int x, int y) {
		x = par(x), y = par(y);
		if(x == y) return;
		if(r[x] < r[y]) swap(x, y);
		p[y] = x;
		r[x] += r[x] == r[y];
	}
	bool same(int x, int y) {
		return par(x) == par(y);
	}
};
const int C = 450;
int n, m;
dsu ds[100100];
vvi cols;
map<pair<int, int>, int> req;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cols.resize(n+1);
	for(int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		ds[c].unite(f, t);
		cols[t].pb(c);
		cols[f].pb(c);
	}
	for(int i = 1; i <= n; i++) {
		sort(all(cols[i]));
		cols[i].erase(unique(all(cols[i])), cols[i].end());
	}
	cin >> m;
	for(int x, y, i = 0; i < m; i++) {
		cin >> x >> y;
		if(pair<int, int>(cols[x].size(), x) > pair<int, int>(cols[y].size(), y))
			swap(x, y);
		if(!req.count({x, y})) {
			int ans = 0;
			for(auto i : cols[x]) ans += ds[i].same(x, y);
			req[{x, y}] = ans;
		}
		cout << req[{x, y}] << "\n";
	}
}