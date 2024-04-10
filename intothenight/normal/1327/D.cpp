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
		int n;
		cin >> n;
		vector<int> p(n), c(n);
		copy_n(istream_iterator<int>(cin), n, p.begin());
		copy_n(istream_iterator<int>(cin), n, c.begin());
		for(auto &x: p){
			-- x;
		}
		for(auto &x: c){
			-- x;
		}
		vector<vector<int>> cycle;
		vector<int> visited(n);
		for(int u = 0; u < n; ++ u){
			if(!visited[u]){
				cycle.emplace_back();
				int v = u;
				do{
					cycle.back().push_back(v);
					visited[v] = true;
					v = p[v];
				}while(v != u);
			}
		}
		int res = numeric_limits<int>::max();
		for(auto s: cycle){
			int m = int(s.size());
			for(int i = 1, j = 1; i <= m; i = j + 1){
				j = m / (m / i);
				if(m % j == 0){
					bool okk = false;
					for(int init = 0; init < j; ++ init){
						bool ok = true;
						for(int i = init; i < m; i += j){
							if(c[s[i]] != c[s[init]]){
								ok = false;
							}
						}
						if(ok){
							okk = true;
							break;
						}
					}
					if(okk){
						ctmin(res, j);
						break;
					}
				}
			}
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