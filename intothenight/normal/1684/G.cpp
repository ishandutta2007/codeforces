#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

struct maximum_bipartite_matching_dfs{
	int n, m, matching = 0;
	vector<vector<int>> adj;
	vector<int> pu, pv; // u is matched with pu[u] and v with pv[v], -1 if no match
	maximum_bipartite_matching_dfs(int n, int m): n(n), m(m), pu(n, -1), pv(m, -1), cur(n), adj(n){ }
	int insert(int from, int to){
		adj[from].push_back(to);
		return (int)adj[from].size() - 1;
	}
	int id = 0;
	vector<int> cur;
	bool dfs(int u){
		cur[u] = id;
		for(auto v: adj[u]) if(!~pv[v]){
			pu[u] = v, pv[v] = u;
			return true;
		}
		for(auto v: adj[u]) if(cur[pv[v]] != id && dfs(pv[v])){
			pu[u] = v, pv[v] = u;
			return true;
		}
		return false;
	}
	// O(VE)
	int maximum_matching(){
		mt19937 rng(1564);
		for(auto u = 0; u < n; ++ u) shuffle(adj[u].begin(), adj[u].end(), rng);
		while(true){
			int augment = 0;
			++ id;
			for(auto u = 0; u < n; ++ u) if(pu[u] == -1 && dfs(u)) ++ augment;
			if(!augment) break;
			matching += augment;
		}
		return matching;
	}
	int run_once(int v){
		if(pu[v] != -1) return 0;
		++ id;
		return dfs(v);
	}
	pair<vector<int>, vector<int>> minimum_vertex_cover(){
		maximum_matching();
		vector<int> L, R, visL(n), visR(m);
		auto dfs = [&](auto self, int u)->void{
			visL[u] = true;
			for(auto v: adj[u]) if(v != pu[u] && !visR[v]){
				visR[v] = true, R.push_back(v);
				if(~pv[v]) self(self, pv[v]);
			}
		};
		for(auto u = 0; u < n; ++ u) if(!visL[u] && pu[u] == -1) dfs(dfs, u);
		for(auto u = 0; u < n; ++ u) if(!visL[u]) L.push_back(u);
		return {L, R};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> left, right;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		if(3LL * x > m){
			left.push_back(x);
		}
		else{
			right.push_back(x);
		}
	}
	maximum_bipartite_matching_dfs M((int)left.size(), (int)right.size());
	for(auto i = 0; i < (int)left.size(); ++ i){
		for(auto j = 0; j < (int)right.size(); ++ j){
			if(left[i] % right[j] == 0 && left[i] * 2LL + right[j] <= m){
				M.insert(i, j);
			}
		}
	}
	if(M.maximum_matching() != (int)left.size()){
		cout << "-1\n";
		return 0;
	}
	vector<array<int, 2>> res;
	for(auto i = 0; i < (int)left.size(); ++ i){
		int j = M.pu[i];
		res.push_back({left[i] * 2 + right[j], left[i] + right[j]});
	}
	for(auto j = 0; j < (int)right.size(); ++ j){
		if(!~M.pv[j]){
			res.push_back({3 * right[j], 2 * right[j]});
		}
	}
	cout << (int)res.size() << "\n";
	for(auto [x, y]: res){
		cout << x << " " << y << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////