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
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		vector<vector<int>> cnt(n + 1, vector<int>(n));
		for(int i = 0; i < n; ++ i){
			-- a[i];
			for(int x = 0; x < n; ++ x){
				if(x == a[i]){
					cnt[i + 1][x] = cnt[i][x] + 1;
				}
				else{
					cnt[i + 1][x] = cnt[i][x];
				}
			}
		}
		bool ok = false;
		for(int i = 0; i < n; ++ i){
			for(int x = 0; x < n; ++ x){
				if(cnt[i][x] && cnt[n][x] - cnt[i + 1][x]){
					ok = true;
				}
			}
			int k = 0;
			for(int x = 0; x < n - 1; ++ x){
				if(cnt[i][x] && cnt[n][x] - cnt[i][x]){
					++ k;
				}
			}
			if(k >= 2){
				ok = true;
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