#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 3005;
const int mod = 1e9 + 7;


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
	int ang = ipow(prr, (mod - 1) / n);
	if(inv) ang = ipow(ang, mod - 2);
	for(int i=0; i<n/2; i++){
		roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
	}
	XOR Convolution : set roots[*] = 1.
	OR Convolution : set roots[*] = 1, and do following:
    if (!inv) {
        a[j + k] = u + v;
        a[j + k + i/2] = u;
    } else {
        a[j + k] = v;
        a[j + k + i/2] = u - v;
    }
	*/
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
	if(inv) for(int i=0; i<n; i++) a[i] /= n; // skip for OR convolution.
}

vector<lint> multiply(vector<lint> &v, vector<lint> &w){
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2; while(n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0); fft(fw, 0);
	for(int i=0; i<n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<lint> ret(n);
	for(int i=0; i<n; i++) ret[i] = (lint)round(fv[i].real());
	return ret;
}
vector<lint> multiply(vector<lint> &v, vector<lint> &w, lint mod){
	int n = 2; while(n < v.size() + w.size()) n <<= 1;
	vector<base> v1(n), v2(n), r1(n), r2(n);
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


lint bit[MAXN];
lint fact[MAXN], invf[MAXN];

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

int n, d, p[MAXN];
lint dp[MAXN][MAXN];

int main(){
	cin >> n >> d;
	for(int i=1; i<n; i++){
		cin >> p[i];
		p[i]--;
	}
	for(int i=0; i<n; i++) fill(dp[i] + 1, dp[i] + MAXN, 1);
	for(int i=n-1; i; i--){
		int sum = 0;
		for(int j=1; j<MAXN; j++){
			sum += dp[i][j];
			sum %= mod;
			dp[p[i]][j] *= sum;
			dp[p[i]][j] %= mod;
		}
	}
	for(int i=2; i<MAXN; i++) dp[0][i] = (dp[0][i-1] + dp[0][i]) % mod;
	vector<lint> a(dp[0] + 1, dp[0] + MAXN);
	d--;
	if(d < a.size()){
		cout << a[d] << endl;
		return 0;
	}
	n = a.size() - 1;
	bit[0] = 1;
	for(int i=1; i<=n; i++) bit[i] = bit[i-1] * (d + 1 - i) % mod;
	fact[0] = invf[0] = 1;
	for(int i=1; i<=n; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod - 2);
	}
	lint ret = 0;
	for(int i=0; i<=n; i++){
		a[i] = a[i] * invf[i] % mod;
		if(i % 2 == 1) invf[i] = mod - invf[i];
	}
	vector<lint> x(invf, invf + n + 1);
	vector<lint> y = a;
	auto z = multiply(x, y, mod);
	for(int i=0; i<=n; i++){
		ret += bit[i] * z[i] % mod;
	}
	ret %= mod;
	cout << ret << endl;
}