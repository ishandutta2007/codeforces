#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
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
	int n;
	cin >> n;
	vector<int> deg(n);
	vector<pair<int, int>> edge;
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		++ deg[u], ++ deg[v];
		edge.emplace_back(u, v);
	}
	vector<int> leaf;
	for(int u = 0; u < n; ++ u){
		if(deg[u] == 1){
			leaf.push_back(u);
		}
	}
	auto query = [&](int u, int v){
		cout << "? " << u + 1 << " " << v + 1 << endl;
		int resp;
		cin >> resp;
		return resp - 1;
	};
	auto ans = [&](int r){
		cout << "! " << r + 1;
		exit(0);
	};
	vector<tuple<int, int, int>> t;
	for(int i = 0; i + 1 < int(leaf.size()); i += 2){
		t.push_back({leaf[i], leaf[i + 1], query(leaf[i], leaf[i + 1])});
	}
	if(int(leaf.size()) % 2){
		t.push_back({get<2>(t.front()), leaf.back(), query(get<2>(t.front()), leaf.back())});
	}
	for(auto [_, __, r]: t){
		binary_lift lift(n, r);
		for(auto [u, v]: edge){
			lift.insert(u, v);
		}
		lift.init();
		bool ok = true;
		for(auto [q1, q2, res]: t){
			if(lift.lca(q1, q2) != res){
				ok = false;
				break;
			}
		}
		if(ok){
			ans(r);
		}
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