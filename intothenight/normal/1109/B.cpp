#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = int(s.size());
	string t = s.substr(0, n / 2);
	if(t == string(n / 2, t[0])){
		cout << "Impossible\n";
	}
	else if(n & 1){
		cout << "2\n";
	}
	else{
		function<bool(int, int)> test = [&](int l, int r){
			string c = s.substr(l, r - l), rc = c;
			reverse(rc.begin(), rc.end());
			if(c != rc){
				return true;
			}
			if(r - l & 1){
				return false;
			}
			return test(l + (r - l >> 1), r);
		};
		test(n / 2, n) ? cout << "1\n" : cout << "2\n";
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