#include <bits/stdc++.h>
using namespace std;

struct hopcroft_karp{
	int n, m, flow = 0;
	vector<vector<int>> adj;
	vector<int> pu, pv, U, V, cur, next;
	hopcroft_karp(int n, int m): n(n), m(m), adj(n), pu(n, -1), pv(m, -1), U(n), V(m){ }
	int insert(int from, int to){
		adj[from].push_back(to);
		return int(adj[from].size()) - 1;
	}
	bool bfs(){
		fill(U.begin(), U.end(), 0), fill(V.begin(), V.end(), 0);
		cur.clear();
		// Find the starting nodes for VFS (i.e. layer 0).
		for(auto u: pv) if(u != -1) U[u] = -1;
		for(int u = 0; u < n; ++ u) if(!U[u]) cur.push_back(u);
		// Find all layers using bfs.
		for(int layer = 1; ; ++ layer){
			bool islast = 0;
			next.clear();
			for(auto u: cur) for(auto v: adj[u]){
				if(pv[v] == -1){
					V[v] = layer;
					islast = 1;
				}
				else if(pv[v] != u && !V[v]){
					V[v] = layer;
					next.push_back(pv[v]);
				}
			}
			if(islast) return true;
			if(next.empty()) return false;
			for(auto u: next) U[u] = layer;
			cur.swap(next);
		}
	}
	bool dfs(int u, int L){
		if(U[u] != L) return false;
		U[u] = -1;
		for(auto v: adj[u]) if(V[v] == L + 1){
			V[v] = 0;
			if(pv[v] == -1 || dfs(pv[v], L + 1)){
				pu[u] = v;
				pv[v] = u;
				return true;
			}
		}
		return false;
	}
	int solve(){
		while(bfs()) for(int u = 0; u < n; ++ u) flow += dfs(u, 0);
		return flow;
	}
	pair<vector<int>, vector<int>> minimum_vertex_cover(){
		solve();
		vector<int> L, R;
		for(int u = 0; u < n; ++ u) if(!~U[u]) L.push_back(u);
		for(int v = 0; v < m; ++ v) if(V[v]) R.push_back(v);
		return {L, R};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	int res = 0;
	for(auto &s: a){
		cin >> s;
		res += count(s.begin(), s.end(), '#');
	}
	int vsz = n * (m - 1), hsz = (n - 1) * m;
	auto ind_v = [&](int i, int j){
		return i * (m - 1) + j;
	};
	auto ind_h = [&](int i, int j){
		return i * m + j;
	};
	hopcroft_karp hk(vsz, hsz);
	int vcnt = 0;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m - 1; ++ j){
			if(a[i][j] == '#' && a[i][j + 1] == '#'){
				++ vcnt;
				int u = ind_v(i, j);
				if(i){
					if(a[i - 1][j] == '#'){
						hk.insert(u, ind_h(i - 1, j));
					}
					if(a[i - 1][j + 1] == '#'){
						hk.insert(u, ind_h(i - 1, j + 1));
					}
				}
				if(i < n - 1){
					if(a[i + 1][j] == '#'){
						hk.insert(u, ind_h(i, j));
					}
					if(a[i + 1][j + 1] == '#'){
						hk.insert(u, ind_h(i, j + 1));
					}
				}
			}
		}
	}
	for(auto i = 0; i < n - 1; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == '#' && a[i + 1][j] == '#'){
				++ vcnt;
			}
		}
	}
	cout << res - (vcnt - hk.solve()) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////