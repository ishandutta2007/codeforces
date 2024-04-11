// Problem: E.  
// Contest: Codeforces - Codeforces Round #440 (Div. 1,     2  2018)
// URL: https://codeforces.com/contest/871/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
struct dsu {
	vector<int> e;
	dsu(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
void bad() {
	cout << "-1\n";
	exit(0);
}
dsu d(0);
const int N = 30300;
vector<int> g[N];
void add_edge(int u, int v) {
	if(!d.join(u, v)) return;
	g[u].push_back(v);
	g[v].push_back(u);
}
void dfs(int v, int p, vector<int> &dist) {
	for(auto i : g[v]) if(i != p) {
		dist[i] = dist[v]+1;
		dfs(i, v, dist);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, k;
	cin >> n >> k;
	d = dsu(n);
	vector<vector<int>> d(k, vector<int>(n));
	vector<vector<int>> s(n, vector<int>(k));
	vector<int> id(k), touch(n);
	for(auto &i : d) {
		for(auto &j : i)
			cin >> j;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < k; j++)
			s[i][j] = d[j][i];
	for(int i = 0; i < k; i++) {
		id[i] = find(all(d[i]), 0)-d[i].begin();
		if(id[i] == n) bad();
	}
	for(int v = 0; v < k; v++) {
		vector<int> ps(d[0][id[v]]+1, -1);
		for(int i = 0; i < n; i++) {
			if(d[0][i]+d[v][i] == d[0][id[v]])
				ps[d[0][i]] = i;
		}
		for(auto i : ps)
			if(i==-1) bad();
			else touch[i] = 1;
		for(int i = 1; i < ps.size(); i++)
			add_edge(ps[i-1], ps[i]);
	}
	map<vector<int>, vector<int>> unvis;
	queue<int> q;
	auto add = [&](vector<int> v, int p) {
		for(auto i : unvis[v]) {
			add_edge(p, i);
			q.push(i);
		}
		unvis[v].clear();
	};
	for(int i = 0; i < n; i++) {
		if(!touch[i]) unvis[s[i]].push_back(i);
		else q.push(i);
	};
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		auto t = s[v];
		for(auto &i : t) i++;
		add(t, v);
	}
	for(int i = 0; i < k; i++) {
		vector<int> D(n);
		dfs(id[i], -1, D);
		if(D != d[i])
			bad();
	}
	for(int i = 0; i < n; i++)
		for(auto j : g[i])
			if(j < i)
				cout << j+1 << " " << i+1 << '\n';	
}