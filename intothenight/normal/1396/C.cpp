#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, r1, r2, r3, len;
	cin >> n >> r1 >> r2 >> r3 >> len;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	const long long inf = numeric_limits<long long>::max() / 2;
	vector dp(n + 1, array{inf, inf, inf, inf, inf});
	dp[0][1] = 0;
	for(auto i = 0; i < n; ++ i){
		long long x = 1LL * a[i] * r1 + r3, y = min<long long>({x, r1 + r2, 1LL * r1 * (a[i] + 2)});
		auto &d = dp[i];
		dp[i + 1] = {
			min({d[1] + x, d[2] + x, d[3] + y, d[4] + y}),
			min({d[1] + x, d[3] + y}) + len,
			min({d[1], d[2], d[3], d[4]}) + y + 2LL * len,
			min({d[1], d[3], d[4]}) + y + 3LL * len,
			min({d[1], d[2], d[3], d[4]}) + y + 4LL * len
		};
	}
	cout << dp[n][0] << "\n";
	return 0;
}

/*
-> : <- = 0:0 (end on left), 1:0 (end on right), 1:1 (end on left), 2:1 (end on right), 2:2 (end on left)
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////