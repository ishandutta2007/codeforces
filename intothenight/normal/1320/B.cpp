#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[v].push_back(u);
	}
	int k;
	cin >> k;
	vector<int> p(k);
	for(int i = 0; i < k; ++ i){
		cin >> p[i], -- p[i];
	}
	int dest = p.back();
	const int inf = numeric_limits<int>::max();
	vector<int> dist(n, inf);
	deque<int> q{dest};
	dist[dest] = 0;
	vector<set<int>> t(n);
	while(!q.empty()){
		int u = q.front();
		q.pop_front();
		for(auto v: adj[u]){
			if(dist[v] == inf){
				dist[v] = dist[u] + 1;
				t[v].insert(u);
				q.push_back(v);
			}
			else if(dist[v] == dist[u] + 1){
				t[v].insert(u);
			}
		}
	}
	pair<int, int> res;
	for(int i = 0; i < k - 1; ++ i){
		int u = p[i], v = p[i + 1];
		if(t[u].count(v)){
			if(t[u].size() > 1){
				++ res.second;
			}
		}
		else{
			++ res.first;
			++ res.second;
		}
	}
	cout << res.first << " " << res.second;
	return 0;
}

/*
4 6
1 2
1 2
2 3
2 3
3 4
3 4
4
1 2 3 4
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////