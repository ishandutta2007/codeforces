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
	const int mx = 200;
	vector<vector<vector<vector<vector<int>>>>> dp(6, vector<vector<vector<vector<int>>>>(6, vector<vector<vector<int>>>(6, vector<vector<int>>(mx, vector<int>(3)))));
	vector<vector<vector<int>>> period(6, vector<vector<int>>(6, vector<int>(6)));
	for(int x = 1; x <= 5; ++ x){
		for(int y = 1; y <= 5; ++ y){
			for(int z = 1; z <= 5; ++ z){
				// Calculate nim value for the current x, y, z
				auto &nim = dp[x][y][z];
				for(int c = 1; c < mx; ++ c){
					vector<int> flag(10);

					flag[nim[max(c - x, 0)][0]] = true;
					flag[nim[max(c - y, 0)][1]] = true;
					flag[nim[max(c - z, 0)][2]] = true;
					for(int res = 0; res < 10; ++ res){
						if(!flag[res]){
							nim[c][0] = res;
							break;
						}
					}

					fill(flag.begin(), flag.end(), false);

					flag[nim[max(c - x, 0)][0]] = true;
					flag[nim[max(c - z, 0)][2]] = true;
					for(int res = 0; res < 10; ++ res){
						if(!flag[res]){
							nim[c][1] = res;
							break;
						}
					}

					fill(flag.begin(), flag.end(), false);

					flag[nim[max(c - x, 0)][0]] = true;
					flag[nim[max(c - y, 0)][1]] = true;
					for(int res = 0; res < 10; ++ res){
						if(!flag[res]){
							nim[c][2] = res;
							break;
						}
					}
				}
				for(int p = 20; p >= 1; ++ p){ // [60, 60 + p) ?== [60 + p, 60 + 2 * p)
					bool ok = true;
					for(int i = 60; i < 60 + p; ++ i){
						if(nim[i][0] != nim[i + p][0]){
							ok = false;
							break;
						}
					}
					if(ok){
						period[x][y][z] = p;
						break;
					}
				}
			}
		}
	}
	int tt;
	cin >> tt;
	while(tt --){
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		auto &nim = dp[x][y][z];
		int p = period[x][y][z];
		auto apply = [&](long long val){
			if(val <= 40){
				return val;
			}
			else{
				return (val - 40) % p + 40;
			}
		};
		vector<long long> a(n);
		copy_n(istream_iterator<long long>(cin), n, a.begin());
		int tot = 0;
		for(auto val: a){
			tot ^= nim[apply(val)][0];
		}
		int res = 0;
		for(int i = 0; i < n; ++ i){
			int cur = tot ^ nim[apply(a[i])][0];
			if(cur == nim[apply(max(a[i] - x, 0LL))][0]){
				++ res;
			}
			if(cur == nim[apply(max(a[i] - y, 0LL))][1]){
				++ res;
			}
			if(cur == nim[apply(max(a[i] - z, 0LL))][2]){
				++ res;
			}
		}
		cout << res << "\n";
	}
	return 0;
}

/*
1
2 2 1 4
8 5

-> 2
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////