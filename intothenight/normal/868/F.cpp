#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	auto C = [&](int l, int r){
		static int cl = 0, cr = 0;
		static long long val = 0;
		static vector<int> cnt(n);
		while(cr < r){
			val += cnt[a[cr]];
			++ cnt[a[cr]];
			++ cr;
		}
		while(l < cl){
			-- cl;
			val += cnt[a[cl]];
			++ cnt[a[cl]];
		}
		while(r < cr){
			-- cr;
			-- cnt[a[cr]];
			val -= cnt[a[cr]];
		}
		while(cl < l){
			-- cnt[a[cl]];
			val -= cnt[a[cl]];
			++ cl;
		}
		return val;
	};
	vector<long long> dp(n + 1, numeric_limits<long long>::max() / 2);
	dp[0] = 0;
	for(auto rep = 0; rep < k; ++ rep){
		vector<long long> dp_next(n + 1, numeric_limits<long long>::max() / 2);
		function<void(int, int, int, int)> dnc = [&](int l, int r, int optl, int optr){
			if(l >= r) return;
			int opt = -1, m = l + (r - l >> 1);
			for(auto i = optl; i <= min(optr - 1, m); ++ i){
				if(dp_next[m] > dp[i] + C(i, m)){
					opt = i;
					dp_next[m] = dp[i] + C(i, m);
				}
			}
			dnc(l, m, optl, opt + 1), dnc(m + 1, r, opt, optr);
		};
		dnc(0, n + 1, 0, n + 1);
		swap(dp, dp_next);
	}
	cout << dp[n] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////