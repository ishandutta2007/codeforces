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



int SOLVE(){
	string s;
	cin >> s;
	for(auto &c: s){
		-- c;
	}
	int n = int(s.size());
	vector<vector<int>> next(n + 1, vector<int>(3, n));
	for(auto i = n - 1; i >= 0; -- i){
		for(auto j = 0; j < 3; ++ j){
			if(s[i] == j + '0'){
				next[i][j] = i;
			}
			else{
				next[i][j] = next[i + 1][j];
			}
		}
	}
	vector<int> t{0, 1, 2};
	const int inf = numeric_limits<int>::max();
	int res = inf;
	do{
		for(auto init = 0; init < n; ++ init){
			int i = next[init][t[0]], j = next[i][t[1]], k = next[j][t[2]];
			if(k < n){
				ctmin(res, k - i + 1);
			}
		}
	}while(next_permutation(t.begin(), t.end()));
	res == inf ? cout << "0\n" : cout << res << "\n";
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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