#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int mod = 998244353;
using lint = long long;

lint ipow(lint a, lint b, lint m = mod)
{
	lint ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ret;
}


namespace fft{
	typedef lint base;
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
		int prr = 3;
		int ang = ipow(prr, (mod - 1) / n);
		if(inv) ang = ipow(ang, mod - 2);
		for(int i=0; i<n/2; i++){
			roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
		}
		for(int i=2; i<=n; i<<=1){
			int step = n / i;
			for(int j=0; j<n; j+=i){
				for(int k=0; k<i/2; k++){
					base u = a[j+k], v = a[j+k+i/2] * roots[step * k] % mod;
					a[j+k] = (u+v+mod)% mod;
					a[j+k+i/2] = (u-v+mod)%mod;
				}
			}
		}
		if(inv) for(int i=0; i<n; i++) a[i] *= ipow(n, mod-2), a[i] %= mod;
	}

	vector<lint> multiply(vector<lint> &v, vector<lint> &w){
		vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
		int n = 2; while(n < v.size() + w.size()) n <<= 1;
		fv.resize(n); fw.resize(n);
		fft(fv, 0); fft(fw, 0);
		for(int i=0; i<n; i++) fv[i] *= fw[i];
		fft(fv, 1);
		vector<lint> ret(n);
		for(int i=0; i<n; i++) ret[i] = fv[i];
		return ret;
	}
}

lint S[MAXN];
lint fact[MAXN], invf[MAXN];

lint bino(int x, int y){
	return fact[x] * (invf[y] * invf[x-y] % mod) % mod;
}

vector<lint> solve(int s, int e){
	if(e - s < 20){
		vector<lint> v(1);
		v[0] = 1;
		for(int i=s; i<=e; i++){
			v.push_back(0);
			for(int j=v.size()-1; j>=0; j--){
				v[j] = v[j] * (mod - i) + (j ? v[j-1] : 0);
				v[j] %= mod;
			}
		}
		return v;
	}
	int m = (s+e)/2;
	auto l = solve(s, m);
	auto r = solve(m+1, e);
	return fft::multiply(l, r);
}

lint getS(int n, int m){
	if(n < m) return 0;
	if(n == 0) return m == 0;
	auto poly = solve(0, n-1);
	if(n % 2 != m % 2) return mod - poly[m];
	return poly[m];
}

int main(){
	fact[0] = invf[0] = 1;
	for(int i=1; i<MAXN; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod - 2);
	}
	int n, a, b;
	cin >> n >> a >> b;
	cout << getS(n-1, a+b-2) * bino(a+b-2, a-1) % mod << endl;
}