#include <bits/stdc++.h>
using namespace std;

struct number_theory{
	int SZ;
	vector<int> lpf, prime; // least prime factor, primes, mobius function, totient function, number of multiples
	number_theory(int SZ): SZ(SZ), lpf(SZ + 1){ // O(SZ)
		lpf[0] = lpf[1] = numeric_limits<int>::max() / 2;
		for(int i = 2; i <= SZ; ++ i){
			if(!lpf[i]) lpf[i] = i, prime.push_back(i);
			for(int j = 0; j < (int)prime.size() && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	uint32_t n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	uint32_t res = 0;
	auto add = [&](uint32_t p){
		uint32_t cnt = 0;
		for(uint32_t x = n; x; ) cnt += x /= p;
		res += cnt * (a * p * p * p + b * p * p + c * p + d);
	};
	const uint32_t block = 2e4;
	number_theory nt(block);
	for(auto i = 0u; i * block <= n; ++ i){
		uint32_t l = max(2u, i * block), r = min(n + 1, (i + 1) * block);
		bitset<block> isprime;
		isprime.set();
		for(auto p: nt.prime){
			for(auto x = max(2u * p, (l + p - 1) / p * p); x < r; x += p){
				isprime[x - l] = false;
			}
		}
		for(auto x = l; x < r; ++ x){
			if(isprime[x - l]){
				add(x);
			}
		}
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