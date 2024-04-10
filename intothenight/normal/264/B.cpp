#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int mx = 1e5;
	vector<int> good(mx + 1);
	int n;
	cin >> n;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		good[x] = true;
	}
	vector<vector<int>> div(mx + 1);
	for(auto x = 2; x <= mx; ++ x){
		for(auto y = 2 * x; y <= mx; y += x){
			div[y].push_back(x);
		}
	}
	vector<int> dp(mx + 1);
	for(auto x = 1; x <= mx; ++ x){
		if(good[x]){
			ctmax(dp[x], 1);
			for(auto d: div[x]){
				ctmax(dp[x], dp[d] + 1);
			}
			for(auto d: div[x]){
				ctmax(dp[d], dp[x]);
			}
		}
	}
	cout << ranges::max(dp) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////