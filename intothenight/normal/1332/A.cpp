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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		bool ok = true;
		if(a + b > 0){
			if(a > b){
				if(x - (a - b) < x1){
					ok = false;
				}
			}
			else if(a < b){
				if(x + (b - a) > x2){
					ok = false;
				}
			}
			else{
				if(x == x1 && x == x2){
					ok = false;
				}
			}
		}
		if(c + d > 0){
			if(c > d){
				if(y - (c - d) < y1){
					ok = false;
				}
			}
			else if(c < d){
				if(y + (d - c) > y2){
					ok = false;
				}
			}
			else{
				if(y == y1 && y == y2){
					ok = false;
				}
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