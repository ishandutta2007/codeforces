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
	int n;
	cin >> n;
	vector<int> hero(n);
	for(auto i = 0; i < n; ++ i){
		cin >> hero[i];
	}
	ranges::sort(hero | ranges::views::reverse);
	cin >> n;
	hero.resize(n);
	vector<pair<char, int>> move(n);
	for(auto &[type, id]: move){
		cin >> type >> id;
	}
	vector<int> dp(1 << n);
	for(auto mask = (1 << n) - 2; mask >= 0; -- mask){
		auto [type, id] = move[__builtin_popcount(mask)];
		int coef = type == 'b' ? 0 : id == 1 ? 1 : -1;
		if(id == 1){
			dp[mask] = numeric_limits<int>::min();
			for(auto i = 0; i < n; ++ i){
				if(~mask & 1 << i){
					ctmax(dp[mask], dp[mask | 1 << i] + coef * hero[i]);
				}
			}
		}
		else{
			dp[mask] = numeric_limits<int>::max();
			for(auto i = 0; i < n; ++ i){
				if(~mask & 1 << i){
					ctmin(dp[mask], dp[mask | 1 << i] + coef * hero[i]);
				}
			}
		}
	}
	cout << dp[0] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////