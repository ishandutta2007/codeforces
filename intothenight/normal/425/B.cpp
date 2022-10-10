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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < m; ++ j){
			cin >> a[i][j];
		}
	}
	int res = -1;
	if(n > k){
		for(int p = 0; p < n; ++ p){
			int cur = 0;
			for(int i = 0; i < n; ++ i){
				if(i != p){
					int cnt = 0;
					for(int j = 0; j < m; ++ j){
						cnt += a[p][j] == a[i][j];
					}
					cur += min(cnt, m - cnt);
					if(cur > k){
						break;
					}
				}
			}
			if(cur <= k && (res == -1 || res > cur)){
				res = cur;
			}
		}
	}
	else if(m > k){
		for(int p = 0; p < m; ++ p){
			int cur = 0;
			for(int j = 0; j < m; ++ j){
				if(p != j){
					int cnt = 0;
					for(int i = 0; i < n; ++ i){
						cnt += a[i][p] == a[i][j];
					}
					cur += min(cnt, n - cnt);
					if(cur > k){
						break;
					}
				}
			}
			if(cur <= k && (res == -1 || res > cur)){
				res = cur;
			}
		}
	}
	else{
		for(int mask = 0; mask < 1 << m; ++ mask){
			int cur = __builtin_popcount(mask);
			for(int i = 1; i < n; ++ i){
				int cnt = 0;
				for(int j = 0; j < m; ++ j){
					cnt += (a[0][j] ^ mask >> j & 1) == a[i][j];
				}
				cur += min(cnt, m - cnt);
				if(cur > k){
					break;
				}
			}
			if(cur <= k && (res == -1 || res > cur)){
				res = cur;
			}
		}
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////