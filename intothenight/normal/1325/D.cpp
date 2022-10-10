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
	long long x, s;
	cin >> x >> s;
	if(x > s || x % 2 != s % 2){
		cout << -1;
		return 0;
	}
	if(!x && !s){
		cout << 0;
		return 0;
	}
	if(x == s){
		cout << "1\n" << x;
		return 0;
	}
	long long d = s - x >> 1;
	if(d & x){
		cout << "3\n" << d << " " << d << " " << x;
		return 0;
	}
	cout << "2\n" << (d | x) << " " << d;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////