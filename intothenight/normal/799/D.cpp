#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int a, b, h, w, n;
	cin >> a >> b >> h >> w >> n;
	vector<int> m(n);
	for(auto i = 0; i < n; ++ i){
		cin >> m[i];
	}
	sort(m.rbegin(), m.rend());
	ctmin(n, 40);
	m.resize(n);
	if(a <= h && b <= w || a <= w && b <= h){
		cout << "0\n";
		return 0;
	}
	const int mx = 1e5;
	vector<int> dp(mx + 1, -1);
	dp[1] = 1;
	for(auto res = 1; res <= n; ++ res){
		int x = m[res - 1];
		vector<int> dp_next(mx + 1, -1);
		for(auto p = 1; p <= mx; ++ p){
			if(~dp[p]){
				ctmax(dp_next[p], min<long long>(1LL * dp[p] * x, mx));
				ctmax(dp_next[min<long long>(1LL * p * x, mx)], dp[p]);
			}
		}
		swap(dp, dp_next);
		for(auto rep = 0; rep < 2; ++ rep){
			for(auto p = (a + h - 1) / h; p <= mx; ++ p){
				if(b <= 1LL * w * dp[p]){
					cout << res << "\n";
					return 0;
				}
			}
			swap(h, w);
		}
	}
	cout << "-1\n";
	return 0;
}

/*
h * X >= a && w * Y >= b or reversed
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////