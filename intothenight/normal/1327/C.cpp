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
	for(int i = 0; i < 2 * k; ++ i){
		int x, y;
		cin >> x >> y;
	}
	string res = string(n - 1, 'D') + string(m - 1, 'L');
	for(int i = 0; i < n; ++ i){
		if(i % 2){
			res += string(m - 1, 'L') + 'U';
		}
		else{
			res += string(m - 1, 'R') + 'U';
		}
	}
	cout << int(res.size()) << "\n" << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////