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
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	const int B = sqrt(1e5);
	int res = 0;
	// 2 * B * n * log n
	for(auto d = -B - 2; d <= B + 2; ++ d){
		static vector<int> b(n);
		for(auto i = 0; i < n; ++ i){
			b[i] = a[i] - i * d;
		}
		ranges::sort(b);
		for(auto l = 0; l < n; ){
			int r = l;
			while(r < n && b[l] == b[r]){
				++ r;
			}
			ctmax(res, r - l);
			l = r;
		}
	}
	const int mx = 1e5;
	const int mxlen = (mx + B - 1) / B;
	vector<map<int, int>> dp(n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = max(0, i - mxlen); j < i; ++ j){
			if((a[i] - a[j]) % (i - j) == 0){
				auto q = (a[i] - a[j]) / (i - j);
				if(!dp[j].contains(q)){
					dp[j][q] = 1;
				}
				ctmax(res, ctmax(dp[i][q], dp[j][q] + 1));
			}
		}
		if(i - mxlen >= 0){
			dp[i - mxlen].clear();
		}
	}
	cout << n - res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////