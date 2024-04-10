#include <bits/stdc++.h>
using namespace std;

struct number_theory{
	int SZ;
	vector<int> lpf, prime; // least prime factor, primes, mobius function, totient function, number of multiples
	number_theory(int SZ): SZ(SZ), lpf(SZ + 1){ // O(SZ)
		lpf[0] = lpf[1] = numeric_limits<int>::max() / 2;
		for(auto i = 2; i <= SZ; ++ i){
			if(!lpf[i]) lpf[i] = i, prime.push_back(i);
			for(auto j = 0; j < (int)prime.size() && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
		}
	}
	vector<int> precalc_mobius() const{
		vector<int> mobius(SZ + 1, 1);
		for(auto i = 2; i <= SZ; ++ i){
			if(i / lpf[i] % lpf[i]) mobius[i] = -mobius[i / lpf[i]];
			else mobius[i] = 0;
		}
		return mobius;
	}
	vector<int> precalc_phi() const{
		vector<int> phi(SZ + 1, 1);
		for(auto i = 2; i <= SZ; ++ i){
			if(i / lpf[i] % lpf[i]) phi[i] = phi[i / lpf[i]] * (lpf[i] - 1);
			else phi[i] = phi[i / lpf[i]] * lpf[i];
		}
		return phi;
	}
	bool is_prime(int x) const{
		assert(0 <= x && x <= SZ);
		return lpf[x] == x;
	}
	int mu_large(long long x) const{ // O(sqrt(x))
		int res = 1;
		for(auto i = 2LL; i * i <= x; ++ i) if(x % i == 0){
			if(x / i % i) return 0;
			x /= i, res = -res;
		}
		if(x > 1) res = -res;
		return res;
	}
	long long phi_large(long long x) const{ // O(sqrt(x))
		long long res = x;
		for(auto i = 2LL; i * i <= x; ++ i) if(x % i == 0){
			while(x % i == 0) x /= i;
			res -= res / i;
		}
		if(x > 1) res -= res / x;
		return res;
	}
	// returns an array is_prime of length high-low where is_prime[i] = [low+i is a prime]
	vector<bool> sieve(long long low, long long high) const{
		assert(high - 1 <= 1LL * SZ * SZ);
		vector<bool> is_prime(high - low, true);
		for(auto p: prime) for(auto x = max(1LL * p, (low + p - 1) / p) * p; x < high; x += p) is_prime[x - low] = false;
		for(auto x = 1; x >= low; -- x) is_prime[x - low] = false;
		return is_prime;
	}
};
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j){ return a[i] < a[j]; });
	const int mx = 60, sz = 10;
	number_theory nt(mx);
	vector<int> pf(mx);
	for(auto x = 1; x < mx; ++ x){
		for(auto i = 0; i < sz; ++ i){
			if(x % nt.prime[i] == 0){
				pf[x] |= 1 << i;
			}
		}
	}
	vector dp(n + 1, vector(mx, vector<int>(1 << sz, numeric_limits<int>::max() / 2)));
	vector prev(n + 1, vector(mx, vector<pair<int, int>>(1 << sz, {-1, -1})));
	dp[0][1][0] = 0;
	for(auto i = 0; i < n; ++ i){
		for(auto x = 1; x < mx; ++ x){
			for(auto mask = 0; mask < 1 << sz; ++ mask){
				for(auto y = x == 1 ? 1 : x + 1; y < mx; ++ y){
					if(!(mask & pf[y]) && dp[i + 1][y][mask | pf[y]] > dp[i][x][mask] + abs(y - a[order[i]])){
						dp[i + 1][y][mask | pf[y]] = dp[i][x][mask] + abs(y - a[order[i]]);
						prev[i + 1][y][mask | pf[y]] = {x, mask};
					}
				}
			}
		}
	}
	array<int, 3> final{numeric_limits<int>::max() / 2, -1, -1};
	for(auto x = 1; x < mx; ++ x){
		for(auto mask = 0; mask < 1 << sz; ++ mask){
			if(final[0] > dp[n][x][mask]){
				final = {dp[n][x][mask], x, mask};
			}
		}
	}
	int x = final[1], mask = final[2];
	vector<int> res(n, -1);
	for(auto i = n - 1; i >= 0; -- i){
		res[order[i]] = x;
		tie(x, mask) = prev[i + 1][x][mask];
	}
	for(auto x: res){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////