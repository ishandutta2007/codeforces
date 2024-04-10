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

template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, bool is_left = true){
	assert(low < high);
	if(is_left){
		while(high - low > 1){
			long long mid = low + (high - low >> 1);
			p(mid) ? low = mid : high = mid;
		}
		return low;
	}
	else{
		while(high - low > 1){
			long long mid = low + (high - low >> 1);
			p(mid) ? high = mid : low = mid;
		}
		return high;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	for(int i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	}
	vector<vector<int>> block(n);
	const int inf = numeric_limits<int>::max() / 2;
	for(int i = 0; i < n - 1; ++ i){
		int k;
		cin >> k;
		while(k --){
			int t;
			cin >> t;
			block[i].push_back(t);
		}
		block[i].push_back(inf);
	}
	block[n - 1].push_back(inf);
	vector<int> dist(n, inf);
	dist[0] = 0;
	for(int i = 0; block[0][i] == i; ++ i){
		dist[0] = i + 1;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.emplace(dist[0], 0);
	while(!q.empty()){
		auto [d, u] = q.top();
		q.pop();
		if(dist[u] == d){
			for(auto [v, w]: adj[u]){
				int t = dist[u] + w;
				auto it = lower_bound(block[v].begin(), block[v].end(), t);
				if(t == *it){
					int index = it - block[v].begin();
					int p = custom_binary_search(index, int(block[v].size()), [&](int i){ return block[v][i] == *it + i - index; });
					t = block[v][p] + 1;
				}
				if(t < dist[v]){
					q.emplace(dist[v] = t, v);
				}
			}
		}
	}
	if(dist[n - 1] == inf){
		cout << -1;
	}
	else{
		cout << dist[n - 1];
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