#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	const int inf = numeric_limits<int>::max() / 3, mxf = 9;
	using dptype = array<map<vector<int>, int>, mxf>;
	dptype dp{};
	for(auto f = 0; f < mxf; ++ f){
		dp[f][{}] = f;
	}
	for(auto i = 0; i < n; ++ i){
		int a, b;
		cin >> a >> b, -- a, -- b;
		dptype dp_next{};
		for(auto ss: dp[a]){
			vector<int> s = ss.first;
			s.insert(lower_bound(s.begin(), s.end(), b), b);
			for(auto f1 = 0; f1 < mxf; ++ f1){
				for(auto f2 = 0; f2 < mxf; ++ f2){
					auto ns = s;
					auto kill = [&](int x){
						return f1 <= x && x <= a || a <= x && x <= f1 || f1 <= x && x <= f2 || f2 <= x && x <= f1;
					};
					ns.erase(remove_if(ns.begin(), ns.end(), kill), ns.end());
					if((int)ns.size() < 4){
						if(dp_next[f2].count(ns)){
							ctmin(dp_next[f2][ns], ss.second + abs(a - f1) + abs(f1 - f2));
						}
						else{
							dp_next[f2][ns] = ss.second + abs(a - f1) + abs(f1 - f2);
						}
					}
				}
			}
		}
		swap(dp, dp_next);
	}
	int res = inf;
	for(auto f = 0; f < 9; ++ f){
		for(auto [s, mint]: dp[f]){
			if(s.empty()){
				ctmin(res, mint);
			}
		}
	}
	cout << res + 2 * n << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////