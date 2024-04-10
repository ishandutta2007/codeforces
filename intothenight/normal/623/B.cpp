#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, c1, c2;
	cin >> n >> c1 >> c2;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	long long res = numeric_limits<long long>::max();
	vector<int> primes;
	auto get_primes = [&](int x){
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
	};
	get_primes(a.front() - 1), get_primes(a.front()), get_primes(a.front() + 1);
	get_primes(a.back() - 1), get_primes(a.back()), get_primes(a.back() + 1);
	sort(primes.begin(), primes.end());
	primes.erase(unique(primes.begin(), primes.end()), primes.end());
	for(auto p: primes){
		array<long long, 3> dp{};
		for(auto x: a){
			array<long long, 3> dp_next{};
			dp_next.fill(numeric_limits<long long>::max() / 2);
			if(x % p == 0){
				ctmin(dp_next[0], dp[0]);
				ctmin(dp_next[2], min(dp[1], dp[2]));
			}
			ctmin(dp_next[1], min(dp[0], dp[1]) + c1);
			if((x + 1) % p == 0 || (x - 1) % p == 0){
				ctmin(dp_next[0], dp[0] + c2);
				ctmin(dp_next[2], min(dp[1], dp[2]) + c2);
			}
			swap(dp, dp_next);
		}
		ctmin(res, *min_element(dp.begin(), dp.end()));
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