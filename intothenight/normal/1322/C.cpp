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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n, m;
		cin >> n >> m;
		vector<long long> a(n);
		copy_n(istream_iterator<long long>(cin), n, a.begin());
		vector<vector<int>> adj(n);
		for(int i = 0; i < m; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			adj[v].push_back(u);
		}
		for(int u = 0; u < n; ++ u){
			sort(adj[u].begin(), adj[u].end());
		}
		vector<int> temp(n);
		iota(temp.begin(), temp.end(), 0);
		sort(temp.begin(), temp.end(), [&](int u, int v){ return adj[u] < adj[v]; });
		long long res = 0;
		for(int i = 0; i < n; ){
			int j = i;
			long long sum = 0;
			while(j < n && adj[temp[i]] == adj[temp[j]]){
				if(adj[temp[j]].size()) sum += a[temp[j]];
				++ j;
			}
			res = gcd(res, sum);
			i = j;
		}
		cout << res << "\n";
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