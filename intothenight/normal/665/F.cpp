#include "bits/stdc++.h"
using namespace std;

template<int SZ>
struct number_theory{
	vector<int> lpf, prime, mu, phi; // least prime factor, primes, mobius function, totient function, number of multiples
	number_theory(): lpf(SZ + 1), mu(SZ + 1, 1), phi(SZ + 1, 1){ // O(SZ)
		for(int i = 2; i <= SZ; ++ i){
			if(!lpf[i]) lpf[i] = i, prime.push_back(i);
			if(i / lpf[i] % lpf[i]) mu[i] = -mu[i / lpf[i]], phi[i] = phi[i / lpf[i]] * (lpf[i] - 1);
			else mu[i] = 0, phi[i] = phi[i / lpf[i]] * lpf[i];
			for(int j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
		}
	}
	int mu_large(long long x){ // O(sqrt(x))
		int res = 1;
		for(long long i = 2; i * i <= x; ++ i) if(x % i == 0){
			if(x / i % i) return 0;
			x /= i, res = -res;
		}
		if(x > 1) res = -res;
		return res;
	}
	long long phi_large(long long x){ // O(sqrt(x))
		long long res = x;
		for(long long i = 2; i * i <= x; ++ i) if(x % i == 0){
			while(x % i == 0) x /= i;
			res -= res / i;
		}
		if(x > 1) res -= res / x;
		return res;
	}
	template<typename IT> // O(n log n)
	auto convolute(IT begin0, IT end0, IT begin1, IT end1){
		int n = distance(begin0, end0);
		assert(n == distance(begin1, end1));
		vector<typename iterator_traits<IT>::value_type> res(n);
		for(int x = 1; x < n; ++ x) for(int y = 1; x * y < n; ++ y) res[x * y] += *(begin0 + x) * *(begin1 + y);
		return res;
	}
	template<typename IT> // O(n log n log k)
	auto conv_exp(IT begin, IT end, long long e){
		int n = distance(begin, end);
		vector<typename iterator_traits<IT>::value_type> res(n), p(begin, end);
		res[1] = 1;
		for(; e; e >>= 1, p = convolute(p.begin(), p.end(), p.begin(), p.end())) if(e & 1) res = convolute(res.begin(), res.end(), p.begin(), p.end());
		return res;
	}
	template<typename IT> // O(n log n)
	void mobius_transform(IT begin, IT end){
		int n = distance(begin, end);
		vector<typename iterator_traits<IT>::value_type> res(n);
		for(int x = 1; x < n; ++ x) for(int mx = x; mx < n; mx += x) res[mx] += *(begin + x);
		move(res.begin(), res.end(), begin);
	}
	template<typename IT> // O(n log n)
	void inverse_transform(IT begin, IT end){
		int n = distance(begin, end);
		vector<typename iterator_traits<IT>::value_type> res(n);
		for(int x = 1; x < n; ++ x) for(int y = 1; x * y < n; ++ y) res[x * y] += *(begin + x) * mu[y];
		move(res.begin(), res.end(), begin);
	}
	vector<int> mul_cnt;
	bool mul_cnt_ready = false;
	template<typename IT> // O(SZ log SZ)
	void init_mul_cnt(IT begin, IT end){
		mul_cnt_ready = true;
		vector<int> cnt(SZ + 1);
		mul_cnt.assign(SZ + 1, 0);
		for(; begin != end; ++ begin) ++ cnt[*begin];
		for(int x = 1; x <= SZ; ++ x) for(int mx = x; mx <= SZ; mx += x) mul_cnt[x] += cnt[mx];
	}
	template<typename T> // Requires Z_p, O((SZ / g) log k)
	T count_tuples_with_gcd(int k, int g = 1){
		assert(mul_cnt_ready);
		T res = 0;
		for(int x = 1; x <= SZ / g; ++ x) res += mu[x] * (T(mul_cnt[x * g]) ^ k);
		return res;
	}
};

long long pi(const long long N){
	if(N <= 1) return 0;
	if(N == 2) return 1;
	const int v = sqrtl(N);
	int s = (v + 1) / 2;
	vector<int> smalls(s), roughs(s);
	vector<long long> larges(s);
	for(int i = 0; i < s; ++ i) smalls[i] = i, roughs[i] = 2 * i + 1, larges[i] = (N / (2 * i + 1) - 1) / 2;
	vector<bool> skip(v + 1);
	const auto divide = [](long long n, long long d){ return int(n / d); };
	const auto half = [](int n){ return n - 1 >> 1; };
	int pc = 0;
	for(int p = 3; p <= v; p += 2) if(!skip[p]){
		int q = p * p;
		if((long long)(q) * q > N) break;
		skip[p] = true;
		for(int i = q; i <= v; i += 2 * p) skip[i] = true;
		int ns = 0;
		for(int k = 0; k < s; ++ k){
			int i = roughs[k];
			if(skip[i]) continue;
			long long d = (long long)(i) * p;
			larges[ns] = larges[k] - (d <= v ? larges[smalls[d >> 1] - pc] : smalls[half(divide(N, d))]) + pc;
			roughs[ns ++] = i;
		}
		s = ns;
		for(int i = half(v), j = v / p - 1 | 1; j >= p; j -= 2){
			int c = smalls[j >> 1] - pc;
			for(int e = j * p >> 1; i >= e; --i) smalls[i] -= c;
		}
		++ pc;
	}
	larges[0] += (long long)(s + 2 * (pc - 1)) * (s - 1) / 2;
	for(int k = 1; k < s; ++ k) larges[0] -= larges[k];
	for(int l = 1; l < s; ++ l){
		int q = roughs[l];
		long long M = N / q, t = 0;
		int e = smalls[half(M / q)] - pc;
		if(e < l + 1) break;
		for(int k = l + 1; k <= e; ++ k) t += smalls[half(divide(M, roughs[k]))];
		larges[0] += t - (long long)(e - l) * (pc + l - 1);
	}
	return larges[0] + 1;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	number_theory<316228> nt;
	long long n;
	cin >> n;
	long long res = 0;
	for(auto p: nt.prime){
		if(1LL * p * p * p > n){
			break;
		}
		++ res;
	}
	for(auto p: nt.prime){
		if(1LL * p * p >= n){ // q <= n / p , p < q
			break;
		}
		res += pi(n / p) - pi(p);
	}
	cout << res << "\n";
	return 0;
}

/*
p^3
pq
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////