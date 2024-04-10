#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

struct dfs_maximum_bipartite_matching{
	int n, m, matching = 0;
	vector<vector<int>> adj;
	vector<int> pu, pv; // u is matched with pu[u] and v with pv[v], -1 if no match
	dfs_maximum_bipartite_matching(int n, int m): n(n), m(m), pu(n, -1), pv(m, -1), cur(n), adj(n){ }
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
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		dfs_maximum_bipartite_matching M(n, n);
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			while(x){
				if(x <= n){
					M.insert(i, x - 1);
				}
				x >>= 1;
			}
		}
		M.maximum_matching() == n ? cout << "YES\n" : cout << "NO\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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