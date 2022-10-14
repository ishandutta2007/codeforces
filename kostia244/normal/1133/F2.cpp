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
using ld = long double;
int n, m, col[maxn], tk[maxn], C = 0, D;
vector<pair<int, int>> ans, oa;
bitset<maxn> vis;
vector<vi> g;
void dfs(int v) {
	col[v] = C;
	for (auto i : g[v]) {
		if (col[i])
			continue;
		dfs(i);
	}
}
void add(int v) {
	vis.set(v);
	for (auto i : g[v]) {
		if (vis.test(i))
			continue;
		add(i);
		ans.pb( { v, i });
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> D;
	g.resize(n + 1);
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	col[1] = maxn;
	for(int i = 2; i <= n; i++) {
		if(!col[i]) {
			++C;
			dfs(i);
		}
	}
	if(C>D||g[1].size()<D) {
		return cout << "NO", 0;
	}
	D-=C;
	cout << "YES\n";
	vis.set(1);
	for(auto i : g[1]) {
		if(!tk[col[i]]) {
			tk[col[i]] = 1;
			ans.pb({1, i});
			vis.set(i);
		} else if(D>0) {
			ans.pb({1, i});
			vis.set(i);
			D--;
		}
	}
	oa = ans;
	for(auto i : oa) {
		add(i.second);
	}
	for (auto i : ans)
		cout << i.first << " " << i.second << "\n";
}