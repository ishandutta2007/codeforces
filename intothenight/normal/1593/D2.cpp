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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int mx = 2e6;
	number_theory nt(mx);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, int> mp;
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			++ mp[a[i]];
		}
		for(auto [x, c]: mp){
			if(2 * c >= n){
				cout << "-1\n";
				return 0;
			}
		}
		vector<int> cand;
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				if(a[i] != a[j]){
					int x = abs(a[i] - a[j]);
					for(auto d = 1; d * d <= x; ++ d){
						if(x % d == 0){
							cand.push_back(d);
							cand.push_back(x / d);
						}
					}
				}
			}
		}
		sort(cand.rbegin(), cand.rend());
		cand.erase(unique(cand.begin(), cand.end()), cand.end());
		static vector<int> cnt(mx);
		fill(cnt.begin(), cnt.end(), 0);
		for(auto d: cand){
			for(auto x: a){
				x %= d;
				if(x < 0){
					x += d;
				}
				if(++ cnt[x] * 2 >= n){
					cout << d << "\n";
					return 0;
				}
			}
			for(auto x: a){
				x %= d;
				if(x < 0){
					x += d;
				}
				-- cnt[x];
			}
		}
		assert(false);
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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