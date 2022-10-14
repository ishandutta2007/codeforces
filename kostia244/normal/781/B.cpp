#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19;
#define tr(u) ((u)*2)
#define ng(u) ((u)*2+1)
struct sat {
	int n, curid = 0;
	vector<vector<int>> g, gr;
	vector<int> topo, vis, compid;
	sat(int n) : n(n) {
		g.resize(2*n);
		gr.resize(2*n);
		vis.resize(2*n);
		compid.resize(2*n);
	}
	void add(int u, int v) {
		g[u^1].push_back(v);
		g[v^1].push_back(u);
		gr[v].push_back(u^1);
		gr[u].push_back(v^1);
	}
	void dfs(int v) {
		vis[v] = 1;
		for(auto i : g[v]) if(!vis[i]) dfs(i);
		topo.push_back(v);
	}
	void mark(int v) {
		compid[v] = curid;
		for(auto &i : gr[v]) if(!compid[i]) mark(i);
	}
	vector<int> solve() {
		for(int i = 0; i < 2*n; i++) if(!vis[i]) dfs(i);
		reverse(all(topo));
		for(auto i : topo) if(!compid[i]) {
			++curid;
			mark(i);
		}
		vector<int> sol(n);
		for(int i = 0; i < 2*n; i+=2) {
			if(compid[i] == compid[i+1]) return {};
			sol[i/2] = compid[i] < compid[i+1];
		}
		return sol;
	}
};
string get() {
	string x, y;
	cin >> x >> y;
	return x.substr(0, 3) + y.substr(0, 1);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<string> s(n);
	map<string, int> cnt;
	for(auto &i : s) {
		i = get();
		if(++cnt[i.substr(0, 2)] > 26) return cout << "NO\n", 0;
	}
	sat u(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(s[i][0] != s[j][0] || s[i][1] != s[j][1]) continue;
			if(s[i][2] == s[j][2]) {
				u.add(ng(i), ng(j));
				u.add(tr(i), ng(j));
				u.add(tr(j), ng(i));
			}
			if(s[i][3] == s[j][3]) {
				u.add(tr(i), tr(j));
			}
			if(s[i][2] == s[j][3]) {
				u.add(ng(i), tr(j));
			}
			if(s[i][3] == s[j][2]) {
				u.add(tr(i), ng(j));
			}
		}
	}
	auto x = u.solve();
	if(x.empty()) return cout << "NO\n", 0;
	cout << "YES\n";
	for(int i = 0; i < n; i++) {
		if(x[i]) swap(s[i][3], s[i][2]);
		s[i].pop_back();
		cout << s[i] << '\n';
	}
}