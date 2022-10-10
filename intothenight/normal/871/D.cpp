#include <bits/stdc++.h>
using namespace std;



struct number_theory{
	int SZ;
	vector<int> lpf, prime, mu, phi; // least prime factor, primes, mobius function, totient function, number of multiples
	number_theory(int SZ): SZ(SZ), lpf(SZ + 1), mu(SZ + 1, 1), phi(SZ + 1, 1){ // O(SZ)
		lpf[0] = lpf[1] = numeric_limits<int>::max() / 2;
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
	template<class T> // O(n log n)
	vector<T> convolute(const vector<T> &a, const vector<T> &b){
		int n = (int)a.size();
		assert(n == (int)b.size());
		vector<T> res(n);
		for(int x = 1; x < n; ++ x) for(int y = 1; x * y < n; ++ y) res[x * y] += a[x] * b[y];
		return res;
	}
	template<class T> // O(n log n log k)
	vector<T> conv_exp(const vector<T> &a, long long e){
		int n = (int)a.size();
		vector<T> res(n), p(a.begin(), a.end());
		res[1] = 1;
		for(; e; e >>= 1, p = convolute(a, a)) if(e & 1) res = convolute(res, p);
		return res;
	}
	template<class T> // O(n log n)
	vector<T> mobius_transform(const vector<T> &a){
		int n = (int)a.size();
		vector<T> res(n);
		for(int x = 1; x < n; ++ x) for(int mx = x; mx < n; mx += x) res[mx] += a[x];
		return res;
	}
	template<class T> // O(n log n)
	vector<T> inverse_transform(vector<T> &a){
		int n = (int)a.size();
		vector<T> res(n);
		for(int x = 1; x < n; ++ x) for(int y = 1; x * y < n; ++ y) res[x * y] += a[x] * mu[y];
		return res;
	}
	vector<int> mul_cnt;
	bool mul_cnt_ready = false;
	template<class T> // O(SZ log SZ)
	void init_mul_cnt(const vector<int> &a){
		mul_cnt_ready = true;
		vector<int> cnt(SZ + 1);
		mul_cnt.assign(SZ + 1, 0);
		for(auto x: a) ++ cnt[x];
		for(int x = 1; x <= SZ; ++ x) for(int mx = x; mx <= SZ; mx += x) mul_cnt[x] += cnt[mx];
	}
	template<class T> // Requires Z_p, O((SZ / g) log k)
	T count_tuples_with_gcd(int k, int g = 1){
		assert(mul_cnt_ready);
		T res = 0;
		for(int x = SZ / g; x >= 1; -- x) res += mu[x] * (T(mul_cnt[x * g]) ^ k);
		return res;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	number_theory nt(n);
	nt.lpf[1] = numeric_limits<int>::max() / 2;
	long long one = 1LL * n * (n - 1) / 2, two = 0, three = 0;
	vector<int> cur(n + 1), cur2(n + 1);
	int it1, it2;
	for(auto x = 1; x <= n; ++ x){
		if(nt.mu[x]){
			one -= nt.mu[x] * 1LL * (n / x) * (n / x - 1) / 2;
			it1 = it2 = 0;
			long long two_cur = 0, three_cur = 0;
			for(auto y = x; y <= n; y += x){
				cur[it1 ++] = nt.lpf[y];
				if(1LL * nt.lpf[y] * nt.lpf[y] <= n){
					-- two_cur;
				}
				if(2 * nt.lpf[y] <= n){
					cur2[it2 ++] = nt.lpf[y];
					if(1LL * nt.lpf[y] * nt.lpf[y] > n){
						-- three_cur;
					}
				}
			}
			sort(cur.begin(), cur.begin() + it1);
			sort(cur2.begin(), cur2.begin() + it2);
			for(auto i = 0, j = it1; i < it1; ++ i){
				while(j > 0 && 1LL * cur[i] * cur[j - 1] > n){
					-- j;
				}
				two_cur += j;
			}
			two += nt.mu[x] * (two_cur / 2);
			for(auto i = 0, j = it2; i < it2; ++ i){
				while(j > 0 && 1LL * cur2[i] * cur2[j - 1] > n){
					-- j;
				}
				three_cur += it2 - j;
			}
			three += nt.mu[x] * (three_cur / 2);
		}
	}
	cout << one + 2 * two + 3 * three << "\n";
	return 0;
}

/*
{{3, 5}, {3, 7}, {5, 7}, {5, 9}, {7, 9}}
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////