#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

pair<vector<int>, vector<int>> euler_walk(const vector<vector<pair<int, int>>> &adj, int m, int source = 0){
	int n = int(adj.size());
	vector<int> deg(n), its(n), used(m), res_v, res_e;
	vector<pair<int, int>> q = {{source, -1}};
	++ deg[source]; // to allow Euler paths, not just cycles
	while(!q.empty()){
		auto [u, e] = q.back();
		int &it = its[u], end = int(adj[u].size());
		if(it == end){ res_v.push_back(u); res_e.push_back(e); q.pop_back(); continue; }
		auto [v, f] = adj[u][it ++];
		if(!used[f]){
			-- deg[u], ++ deg[v];
			used[f] = 1; q.emplace_back(v, f);
		}
	}
	for(auto d: deg) if(d < 0 || int(res_v.size()) != m + 1) return {};
	return {{res_v.rbegin(), res_v.rend()}, {res_e.rbegin() + 1, res_e.rend()}};
}

template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, const bool &is_left = true){
	assert(low < high);
	while(high - low > 1){
		auto mid = low + (high - low >> 1);
		(p(mid) == is_left ? low : high) = mid;
	}
	return is_left ? low : high;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < 2; ++ j){
			cin >> a[i][j];
		}
	}
	if(n == 1){
		cout << (a[0][0] == a[0][1] ? 20 : __builtin_ctz(a[0][0] ^ a[0][1])) << "\n1 2";
		return 0;
	}
	vector<int> res_v, res_e;
	auto pred = [&](int bit){
		vector<vector<pair<int, int>>> adj(1 << bit);
		int source = -1;
		for(auto i = 0; i < n; ++ i){
			int u = a[i][0] & (1 << bit) - 1, v = a[i][1] & (1 << bit) - 1;
			source = u;
			adj[u].emplace_back(v, i);
			if(u != v) adj[v].emplace_back(u, i);
		}
		tie(res_v, res_e) = euler_walk(adj, n, source);
		return !res_v.empty() && res_v.front() == res_v.back();
	};
	int bit = custom_binary_search(0, 21, pred);
	pred(bit);
	cout << bit << "\n";
	for(int i = 0; i < n; ++ i){
		if(res_v[i] == (a[res_e[i]][0] & (1 << bit) - 1)){
			cout << 2 * res_e[i] + 1 << " " << 2 * res_e[i] + 2 << " ";
		}
		else{
			cout << 2 * res_e[i] + 2 << " " << 2 * res_e[i] + 1 << " ";
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