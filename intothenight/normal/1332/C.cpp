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
	vector<int> p{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	int tt;
	cin >> tt;
	while(tt --){
		int n, k;
		string s;
		cin >> n >> k >> s;
		int res = 0;
		for(int i = 0, j = k - 1; i <= j; ++ i, -- j){
			vector<int> cnt(26);
			if(i == j){
				for(int q = 0; q < n / k; ++ q){
					++ cnt[s[i + q * k] - 'a'];
				}
			}
			else{
				for(int q = 0; q < n / k; ++ q){
					++ cnt[s[i + q * k] - 'a'], ++ cnt[s[j + q * k] - 'a'];
				}
			}
			int ind = max_element(cnt.begin(), cnt.end()) - cnt.begin();
			for(int it = 0; it < 26; ++ it){
				if(it != ind){
					res += cnt[it];
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