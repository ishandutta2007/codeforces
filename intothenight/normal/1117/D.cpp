#include "bits/stdc++.h"
using namespace std;

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
	const long long mod = 1e9 + 7;
	long long n;
	int m;
	cin >> n >> m;
	vector<long long> init(m, 1), coef(m);
	coef[0] = coef[m - 1] = 1;
	recurrence f(init, coef, mod);
	cout << f[n] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////