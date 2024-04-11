#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
const int MAXN = 30005;
const int mod = 1e9 + 7;

namespace fft{
	typedef complex<double> base;
	void fft(vector<base> &a, bool inv){
		int n = a.size(), j = 0;
		vector<base> roots(n/2);
		for(int i=1; i<n; i++){
			int bit = (n >> 1);
			while(j >= bit){
				j -= bit;
				bit >>= 1;
			}
			j += bit;
			if(i < j) swap(a[i], a[j]);
		}
		double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
		for(int i=0; i<n/2; i++){
			roots[i] = base(cos(ang * i), sin(ang * i));
		}
		/* In NTT, let prr = primitive root. Then,
		 * 		int ang = ipow(prr, (mod - 1) / n);
		 * 				if(inv) ang = ipow(ang, mod - 2);
		 * 						for(int i=0; i<n/2; i++){
		 * 									roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
		 * 											}
		 * 													Others are same. If there is /= n, do *= ipow(n, mod - 2).
		 * 															In XOR convolution, roots[*] = 1. 
		 * 																	*/
		for(int i=2; i<=n; i<<=1){
			int step = n / i;
			for(int j=0; j<n; j+=i){
				for(int k=0; k<i/2; k++){
					base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
					a[j+k] = u+v;
					a[j+k+i/2] = u-v;
				}
			}
		}
		if(inv) for(int i=0; i<n; i++) a[i] /= n;
	}

	vector<lint> multiply(vector<lint> &v, vector<lint> &w){
		vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
		int n = 1;
		while(n < max(v.size(), w.size())) n <<= 1;
		n <<= 1;
		fv.resize(n);
		fw.resize(n);
		fft(fv, 0);
		fft(fw, 0);
		for(int i=0; i<n; i++) fv[i] *= fw[i];
		fft(fv, 1);
		vector<lint> ret(n);
		for(int i=0; i<n; i++) ret[i] = (lint)round(fv[i].real());
		return ret;
	}
	vector<lint> multiply(vector<lint> &v, vector<lint> &w, lint mod){
		int n = 1;
		while(n < max(v.size(), w.size())) n <<= 1;
		n <<= 1;
		vector<base> v1(n), v2(n);
		vector<base> r1(n), r2(n);
		for(int i=0; i<v.size(); i++){
			v1[i] = base(v[i] >> 15, v[i] & 32767);
		}
		for(int i=0; i<w.size(); i++){
			v2[i] = base(w[i] >> 15, w[i] & 32767);
		}
		fft(v1, 0);
		fft(v2, 0);
		for(int i=0; i<n; i++){
			int j = (i ? (n - i) : i);
			base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
			base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
			base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
			base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
			r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
			r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
		}
		fft(r1, 1);
		fft(r2, 1);
		vector<lint> ret(n);
		for(int i=0; i<n; i++){
			lint av = (lint)round(r1[i].real());
			lint bv = (lint)round(r1[i].imag()) + (lint)round(r2[i].real());
			lint cv = (lint)round(r2[i].imag());
			av %= mod, bv %= mod, cv %= mod;
			ret[i] = (av << 30) + (bv << 15) + cv;
			ret[i] %= mod;
			ret[i] += mod;
			ret[i] %= mod;
		}
		return ret;
	}
}


lint ipow(lint x, lint p){
	lint ret = 1, piv = x % mod;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret % mod;
}

lint n, k;
lint fact[MAXN], invf[MAXN], pwr[MAXN];

lint bino(int x, int y){
	return fact[x] * (invf[y] * invf[x - y] % mod) % mod;
}

vector<lint> f(int x){
	if(x == 0){
		vector<lint> v = {1};
		v.resize(k + 1);
		return v;
	}
	if(x % 2 == 1){
		auto prv = f(x-1);
		vector<lint> ivf(k + 1);
		for(int i=0; i<=k; i++) prv[i] = (prv[i] * pwr[i] % mod) * invf[i] % mod;
		for(int i=0; i<=k; i++) ivf[i] = invf[i];
		auto ans = fft::multiply(prv, ivf, mod);
		ans.resize(k + 1);
		for(int i=0; i<=k; i++){
			ans[i] += mod - prv[i];
			ans[i] %= mod;
			ans[i] *= fact[i];
			ans[i] %= mod;
		}
		return ans;
	}
	else{
		auto p1 = f(x/2);
		auto p2 = p1;
		for(int i=0; i<p1.size(); i++){
			p1[i] = p1[i] * (invf[i] * ipow(2, i * (x/2)) % mod) % mod;
		}
		for(int i=0; i<p2.size(); i++){
			p2[i] = p2[i] * invf[i] % mod;
		}
		auto ans = fft::multiply(p1, p2, mod);
		ans.resize(k + 1);
		for(int i=0; i<=k; i++) ans[i] = (ans[i] * fact[i]) % mod;
		return ans;
	}
}

int main(){
	cin >> n >> k;
	if(n > k){
		puts("0");
		return 0;
	}
	fact[0] = invf[0] = pwr[0] = 1;
	for(int i=1; i<=k; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod-2);
		pwr[i] = (pwr[i-1] << 1) % mod;
	}
	auto solve = f(n);
	lint ret = 0;
	for(int i=1; i<=k; i++){
		ret += solve[i] * bino(k, i) % mod;
	}
	ret %= mod;
	cout << ret << endl;
}