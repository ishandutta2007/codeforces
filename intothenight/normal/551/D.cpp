#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long long modexp(long long b, long long e, const long long &mod){
	long long res = 1;
	for(; e; b = b * b % mod, e >>= 1) if(e & 1) res = res * b % mod;
	return res;
}
long long modinv(long long a, const long long &mod){
	return modexp(a, mod - 2, mod);
}
struct recurrence{
	int N;
	vector<long long> init, coef;
	const long long mod;
	recurrence(const vector<long long> &init, const vector<long long> &coef, long long mod): N(coef.size()), init(init), coef(coef), mod(mod){ }
	// Berlekamp Massey Algorithm
	recurrence(const vector<long long> &s, long long mod): mod(mod){
		int n = int(s.size());
		N = 0;
		vector<long long> B(n), T;
		coef.resize(n);
		coef[0] = B[0] = 1;
		long long b = 1;
		for(int i = 0, m = 0; i < n; ++ i){
			++ m;
			long long d = s[i] % mod;
			for(int j = 1; j <= N; ++ j) d = (d + coef[j] * s[i - j]) % mod;
			if(!d) continue;
			T = coef;
			long long c = d * modinv(b, mod) % mod;
			for(int j = m; j < n; ++ j) coef[j] = (coef[j] - c * B[j - m]) % mod;
			if(2 * N > i) continue;
			N = i + 1 - N, B = T, b = d, m = 0;
		}
		coef.resize(N + 1), coef.erase(coef.begin());
		for(auto &x: coef) x = (mod - x) % mod;
		reverse(coef.begin(), coef.end());
		init.resize(N);
		for(int i = 0; i < N; ++ i) init[i] = s[i] % mod;
	}
	long long operator[](long long n) const{
		auto combine = [&](vector<long long> a, vector<long long> b){
			vector<long long> res(2 * N + 1);
			for(int i = 0; i <= N; ++ i) for(int j = 0; j <= N; ++ j) res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
			for(int i = N << 1; i > N; -- i) for(int j = 0; j < N; ++ j) res[i - 1 - j] = (res[i - 1 - j] + res[i] * coef[N - 1 - j]) % mod;
			res.resize(N + 1);
			return res;
		};
		vector<long long> pol(N + 1), e(pol);
		pol[0] = e[1] = 1;
		for(++ n; n; n >>= 1, e = combine(e, e)) if(n & 1) pol = combine(pol, e);
		long long res = 0;
		for(int i = 0; i < N; ++ i) res = (res + pol[i + 1] * init[i]) % mod;
		return res;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	long long n, k, l, m;
	cin >> n >> k >> l >> m;
	if(l != 64 && 1ull << l <= k){
		cout << 0;
		return 0;
	}
	recurrence f({1, 2}, {1, 1}, m);
	long long res = 1, f0 = f[n], f1 = (modexp(2, n, m) - f0 + m) % m;
	for(int bit = 0; bit < l; ++ bit){
		if(1LL << bit & k){
			res = res * f1 % m;
		}
		else{
			res = res * f0 % m;
		}
	}
	cout << res % m;
	return 0;
}

/*
2 3 5 

An = A(n-1) + A(n-2)
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////