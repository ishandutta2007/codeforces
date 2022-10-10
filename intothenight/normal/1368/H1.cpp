#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, qq;
	cin >> n >> m >> qq;
	string l, r, t, b;
	cin >> l >> r >> t >> b;
	int res = numeric_limits<int>::max();
	string color("RB");
	for(auto rep = 0; rep < 2; ++ rep){
		array<int, 2> dp{count(l.begin(), l.end(), color[1]), count(l.begin(), l.end(), color[0])};
		// 0: RED, 1: BLUE
		for(auto j = 0; j < m; ++ j){
			array<int, 2> dp_next{};
			for(auto c = 0; c < 2; ++ c){
				dp_next[c] = min(dp[c], dp[!c] + n) + (t[j] == color[!c]) + (b[j] == color[!c]);
			}
			swap(dp, dp_next);
		}
		ctmin(res, min(dp[0] + count(r.begin(), r.end(), color[1]), dp[1] + count(r.begin(), r.end(), color[0])));
		swap(n, m), swap(l, t), swap(r, b);
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////