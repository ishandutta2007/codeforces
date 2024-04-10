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
	cout << fixed << setprecision(3);
	int n;
	cin >> n;
	int d = 0, cnt = 0;
	for(int i = 0; i < 2 * n; ++ i){
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		int t = (s[0] - '0') + (s[1] - '0') * 10 + (s[2] - '0') * 100;
		if(t){
			d += t;
		}
		else{
			++ cnt;
		}
	}
	int res = 2e9;
	for(int x = n - cnt; x <= n; ++ x){
		ctmin(res, abs(d - 1000 * x));
	}
	cout << res / 1000.0;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////