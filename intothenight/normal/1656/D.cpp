#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

// Correctness proved in https://github.com/kth-competitive-programming/kactl/blob/master/doc/modmul-proof.pdf
// twice faster than (__int128_t)a * b % M
using ull = unsigned long long;
ull mod_mul(ull a, ull b, ull M){
	long long res = a * b - M * ull(1.L / M * a * b);
	return res + M * (res < 0) - M * (res >= (long long)M);
}
ull mod_pow(ull b, ull e, ull mod){
	ull res = 1;
	for(; e; b = mod_mul(b, b, mod), e >>= 1) if(e & 1) res = mod_mul(res, b, mod);
	return res;
}
// Millar Rabin Primality Test
// 7 times slower than a^b mod c
bool isprime(ull n){
	if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull s = __builtin_ctzll(n - 1), d = n >> s;
	for(ull a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
		ull p = mod_pow(a, d, n), i = s;
		while(p != 1 && p != n - 1 && a % n && i --) p = mod_mul(p, p, n);
		if(p != n - 1 && i != s) return false;
	}
	return true;
}
// Pollard rho algorithm
// O(n^1/4)
ull get_factor(ull n){
	auto f = [n](ull x){ return mod_mul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while(t ++ % 40 || gcd(prd, n) == 1){
		if(x == y) x = ++ i, y = f(x);
		if(q = mod_mul(prd, max(x, y) - min(x, y), n)) prd = q;
		x = f(x), y = f(f(y));
	}
	return gcd(prd, n);
}
// Returns the prime factors in arbitrary order
vector<ull> factorize(ull n){
	if(n == 1) return {};
	if(isprime(n)) return {n};
	ull x = get_factor(n);
	auto l = factorize(x), r = factorize(n / x);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		long long n;
		cin >> n;
		auto factor = factorize(n);
		ranges::sort(factor);
		int i = 0;
		long long p = 2;
		while(i < (int)factor.size() && factor[i] == 2){
			++ i;
			p <<= 1;
		}
		if(!__builtin_mul_overflow_p(p >> 1, p + 1, 0LL) && n >= (p >> 1) * (p + 1)){
			cout << p << "\n";
			return 0;
		}
		if(i < (int)factor.size()){
			auto p = factor[i];
			if(!__builtin_mul_overflow_p(p, p + 1 >> 1, 0LL) && n >= p * (p + 1 >> 1)){
				cout << p << "\n";
				return 0;
			}
		}
		cout << "-1\n";
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