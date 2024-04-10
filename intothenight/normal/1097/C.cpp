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
	int n;
	cin >> n;
	int zcnt = 0;
	const int mx = 500001;
	vector<array<int, 2>> cnt(mx, {0, 0});
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		int m = 0, tot = 0;
		for(auto c: s){
			tot += (c == '(' ? 1 : -1);
			ctmin(m, tot);
		}
		if(!m && !tot){
			++ zcnt;
		}
		else if(!m){
			++ cnt[tot][0];
		}
		else if(m == tot){
			++ cnt[-m][1];
		}
	}
	cout << zcnt / 2 + accumulate(cnt.begin(), cnt.end(), 0, [&](int x, auto y){ return x + min(y[0], y[1]); });
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////