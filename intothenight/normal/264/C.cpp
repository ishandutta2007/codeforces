#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n), c(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> c[i], -- c[i];
	}
	vector<long long> dp(n);
	for(auto qi = 0; qi < qn; ++ qi){
		int same, dif;
		cin >> same >> dif;
		array<pair<long long, int>, 2> opt{{{0, -1}, {numeric_limits<long long>::min() / 2, -1}}};
		ranges::fill(dp, numeric_limits<long long>::min() / 2);
		for(auto i = 0; i < n; ++ i){
			long long x = max(
				dp[c[i]] + 1LL * a[i] * same,
				(opt[0].second == c[i] ? opt[1].first : opt[0].first) + 1LL * a[i] * dif
			);
			dp[c[i]] = max(dp[c[i]], x);
			if(opt[0].second == c[i]){
				opt[0].first = dp[c[i]];
			}
			else if(opt[1].second == c[i]){
				opt[1].first = dp[c[i]];
				if(opt[0].first < opt[1].first){
					swap(opt[0], opt[1]);
				}
			}
			else if(opt[0].first < dp[c[i]]){
				opt[1] = opt[0];
				opt[0] = {dp[c[i]], c[i]};
			}
			else if(opt[1].first < dp[c[i]]){
				opt[1] = {dp[c[i]], c[i]};
			}
		}
		cout << opt[0].first << "\n";
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