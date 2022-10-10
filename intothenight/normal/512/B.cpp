#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> l(n), c(n);
	int g = 0;
	for(auto i = 0; i < n; ++ i){
		cin >> l[i];
		g = gcd(g, l[i]);
	}
	for(auto i = 0; i < n; ++ i){
		cin >> c[i];
	}
	if(g >= 2){
		cout << "-1\n";
		return 0;
	}
	int res = numeric_limits<int>::max();
	for(auto i = 0; i < n; ++ i){
		vector<int> primes;
		{
			int x = l[i];
			for(auto p = 2; p * p <= x; ++ p){
				if(x % p == 0){
					primes.push_back(p);
					while(x % p == 0){
						x /= p;
					}
				}
			}
			if(x >= 2){
				primes.push_back(x);
			}
		}
		int sz = (int)primes.size();
		vector<int> dp(1 << sz, numeric_limits<int>::max() / 2);
		dp.back() = c[i];
		for(auto j = 0; j < n; ++ j){
			if(j != i){
				vector<int> dp_next = dp;
				int mask = 0;
				for(auto t = 0; t < sz; ++ t){
					if(l[j] % primes[t] == 0){
						mask |= 1 << t;
					}
				}
				for(auto cmask = 0; cmask < 1 << sz; ++ cmask){
					ctmin(dp_next[cmask & mask], dp[cmask] + c[j]);
				}
				swap(dp, dp_next);
			}
		}
		ctmin(res, dp[0]);
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