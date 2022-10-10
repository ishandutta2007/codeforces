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
	int n, len, k;
	cin >> n >> len >> k;
	vector<int> pos(n), lim(n);
	for(auto i = 0; i < n; ++ i){
		cin >> pos[i];
	}
	pos.push_back(len);
	for(auto i = 0; i < n; ++ i){
		cin >> lim[i];
	}
	const int inf = numeric_limits<int>::max() / 2;
	vector dp(n, vector(k + 1, inf));
	vector dp_next(n, vector<int>(k + 1));
	dp[0][0] = (pos[1] - pos[0]) * lim[0];
	for(auto i = 1; i < n; ++ i){
		ranges::fill(dp_next | ranges::views::join, inf);
		for(auto last = 0; last < i; ++ last){
			for(auto rem = 0; rem <= min(i - 1, k); ++ rem){
				ctmin(dp_next[i][rem], dp[last][rem] + (pos[i + 1] - pos[i]) * lim[i]);
				if(rem + 1 <= k){
					ctmin(dp_next[last][rem + 1], dp[last][rem] + (pos[i + 1] - pos[i]) * lim[last]);
				}
			}
		}
		swap(dp, dp_next);
	}
	cout << ranges::min(dp | ranges::views::join) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////