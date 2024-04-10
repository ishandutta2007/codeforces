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
	string s;
	cin >> s;
	int n = int(s.size());
	long long res = 0;
	for(int l = 0; l < n; ++ l){
		for(int r = l + 3; r <= n && r - l < 9; ++ r){
			bool ok = false;
			for(int x = l; x < r; ++ x){
				for(int y = x + 1, z = x + 2; z < r; ++ y, z += 2){
					if(s[x] == s[y] && s[y] == s[z]){
						ok = true;
						goto label;
					}
				}
			}
			label:;
			if(ok){
				++ res;
			}
		}
	}
	if(n >= 9){
		for(int l = 0; l < n, l + 9 <= n; ++ l){
			res += n - (l + 8);
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