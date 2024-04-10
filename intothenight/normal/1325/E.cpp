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

pair<vector<int>, vector<int>> linearsieve(int n){
	vector<int> lpf(n + 1), prime;
	prime.reserve(n + 1);
	for(int i = 2; i <= n; ++ i){
		if(!lpf[i]) lpf[i] = i, prime.push_back(i);
		for(int j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && i * prime[j] <= n; ++ j){
			lpf[i * prime[j]] = prime[j];
		}
	}
	return {lpf, prime};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	const int mx = 1e6;
	auto [lpf, prime] = linearsieve(mx);
	vector<int> ind(mx);
	int m = int(prime.size());
	for(int i = 0; i < m; ++ i){
		ind[prime[i]] = i;
	}
	int n;
	cin >> n;
	vector<int> cnt(m);
	vector<vector<int>> adj(m);
	bool finished = false;
	deque<pair<int, int>> q;
	set<pair<int, int>> log;
	for(int i = 0; i < n; ++ i){
		int x;
		cin >> x;
		vector<int> factor;
		while(x > 1){
			int cnt = 0, p = lpf[x];
			while(x % p == 0){
				++ cnt;
				x /= p;
			}
			if(cnt % 2){
				factor.push_back(p);
			}
		}
		if(!int(factor.size())){
			cout << 1;
			return 0;
		}
		if(int(factor.size()) == 2){
			int u = ind[factor[0]], v = ind[factor[1]];
			if(log.count({u, v})){
				finished = true;
			}
			else{
				adj[u].push_back(v), adj[v].push_back(u);
				log.insert({u, v}), log.insert({v, u});
			}
		}
		else{
			for(auto p: factor){
				++ cnt[ind[p]];
				if(cnt[ind[p]] == 2){
					finished = true;
				}
			}
			q.push_back({ind[factor[0]], -1});
		}
	}
	if(finished){
		cout << 2;
		return 0;
	}
	const int inf = numeric_limits<int>::max();
	int res = inf;
	vector<int> dist(m, inf);
	for(auto u: q){
		dist[u.first] = 0;
	}
	while(!q.empty()){
		auto [u, p] = q.front();
		q.pop_front();
		for(auto v: adj[u]){
			if(v != p){
				if(dist[v] == inf){
					dist[v] = dist[u] + 1;
					q.push_back({v, u});
				}
				else{
					ctmin(res, dist[u] + 3 + dist[v]);
				}
			}
		}
	}
	for(int s = 0; s < 1000; ++ s){
		deque<pair<int, int>> q{{s, -1}};
		vector<int> dist(m, inf);
		dist[s] = 0;
		while(!q.empty()){
			auto [u, p] = q.front();
			q.pop_front();
			for(auto v: adj[u]){
				if(v != p){
					if(dist[v] == inf){
						dist[v] = dist[u] + 1;
						q.push_back({v, u});
					}
					else{
						ctmin(res, dist[u] + 1 + dist[v]);
					}
				}
			}
		}
	}
	res == inf ? cout << -1 : cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////