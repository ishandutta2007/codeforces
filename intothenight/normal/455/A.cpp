#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	const int mx = 1e5;
	vector<long long> a(mx + 1);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		a[x] += x;
	}
	array<long long, 2> dp{};
	for(auto x = 1; x <= mx; ++ x){
		dp = {max(dp[0], dp[1]), dp[0] + a[x]};
	}
	cout << max(dp[0], dp[1]) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////