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
			for(int j = 0; j < (int)prime.size() && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
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
	vector<T> inverse_transform(const vector<T> &a){
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
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }


int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int mx = 1e6;
	number_theory nt(mx);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		map<int, int> cnt;
		for(auto i = 0; i < n; ++ i){
			int x, cur = 1;
			cin >> x;
			while(x > 1){
				if(x / nt.lpf[x] % nt.lpf[x]){
					cur *= nt.lpf[x];
					x /= nt.lpf[x];
				}
				else{
					x /= nt.lpf[x] * nt.lpf[x];
				}
			}
			++ cnt[cur];
		}
		int res0 = 0, res1 = 0;
		map<int, int> cnt2;
		for(auto [x, y]: cnt){
			ctmax(res0, y);
			if(y & 1){
				cnt2[x] += y;
			}
			else{
				cnt2[1] += y;
			}
		}
		for(auto [x, y]: cnt2){
			ctmax(res1, y);
		}
		int qn;
		cin >> qn;
		for(auto qi = 0; qi < qn; ++ qi){
			long long w;
			cin >> w;
			if(w){
				cout << res1 << "\n";
			}
			else{
				cout << res0 << "\n";
			}
		}
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