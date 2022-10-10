#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct binary_lift: vector<vector<int>>{
	int N, root, lg;
	vector<vector<int>> up;
	vector<int> depth;
	binary_lift(int N, int root): N(N), root(root), lg(ceil(log2(N))), depth(N), up(N, vector<int>(lg + 1)){
		this->resize(N);
	}
	void insert(int u, int v){ (*this)[u].push_back(v), (*this)[v].push_back(u); }
	void init(){ dfs(root, root); }
	void dfs(int u, int p){
		up[u][0] = p;
		for(int i = 1; i <= lg; ++ i) up[u][i] = up[up[u][i - 1]][i - 1];
		for(auto &v: (*this)[u]) if(v != p){
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	}
	int lca(int u, int v){
		if(depth[u] < depth[v]) std::swap(u, v);
		u = trace_up(u, depth[u] - depth[v]);
		for(int d = lg; d >= 0; -- d) if(up[u][d] != up[v][d]) u = up[u][d], v = up[v][d];
		return u == v ? u : up[u][0];
	}
	int dist(int u, int v){
		return depth[u] + depth[v] - 2 * depth[lca(u, v)];
	}
	int trace_up(int u, int dist){
		if(dist >= depth[u] - depth[root]) return root;
		for(int d = lg; d >= 0; -- d) if(dist & (1 << d)) u = up[u][d];
		return u;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, qq;
	cin >> n >> qq;
	binary_lift lift(n, 0);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		lift.insert(u, v);
	}
	lift.init();
	while(qq --){
		int k;
		cin >> k;
		vector<int> a(k);
		copy_n(istream_iterator<int>(cin), k, a.begin());
		for(auto &x: a){
			-- x;
			x = lift.up[x][0];
		}
		sort(a.begin(), a.end(), [&](int u, int v){ return lift.depth[u] < lift.depth[v]; });
		bool ok = true;
		for(int i = 1; i < k; ++ i){
			int u = a[i - 1], v = a[i];
			if(u != lift.lca(u, v)){
				ok = false;
				break;
			}
		}
		ok ? cout << "YES\n" : cout << "NO\n";
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