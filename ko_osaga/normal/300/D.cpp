#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

const int mod = (7 << 20) + 1;

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

namespace nt_fft{
	const int prr = 3;
	void fft(vector<int> &v, bool inv){
		vector<int> w(v.size());
		for(int i=2; i<=v.size(); i<<=1){
			int bsz = v.size() / i;
			int ang = ipow(prr, (mod - 1) / i);
			if(inv) ang = ipow(ang, mod-2);
			for(int j=0; j<bsz; j++){
				for(int k=0; k<i; k++){
					w[k] = v[j + k * bsz];
				}
				lint cur = 1;
				for(int k=0; k<i/2; k++){
					lint a = w[2*k], b = cur * w[2*k+1] % mod;
					v[j + k * bsz] = (a + b) % mod;
					v[j + k * bsz + v.size()/2] = (a - b + mod) % mod;
					cur = (cur * ang) % mod;
				}
			}
		}
		if(inv){
			lint mul = ipow(v.size(), mod-2);
			for(int i=0; i<v.size(); i++){
				v[i] = (mul * v[i]) % mod;
			}
		}
	}
	vector<int> multiply(vector<int> a, vector<int> b){
		int w = 1;
		while(w < max(a.size(), b.size())) w <<= 1;
		w <<= 1;
		a.resize(w);
		b.resize(w);
		fft(a, 0); 
		fft(b, 0);
		for(int i=0; i<w; i++) a[i] = (1ll * a[i] * b[i]) % mod;
		fft(a, 1);
		return a;
	}
	vector<int> power(vector<int> a){
		int w = 1;
		while(w < a.size()) w <<= 1;
		w <<= 1;
		a.resize(w);
		fft(a, 0);
		for(int i=0; i<w; i++) a[i] = (1ll * a[i] * a[i]) % mod;
		fft(a, 1);
		return a;
	}
}

int d1[33][1005], d2[33][1005];

int main(){
	d1[0][0] = d2[0][0] = 1;
	for(int i=1; i<=32; i++){
		vector<int> poly(1000);
		for(int j=0; j<1000; j++){
			poly[j] = d2[i-1][j];
		}
		poly = nt_fft::power(poly);
		poly.resize(1000);
		reverse(poly.begin(), poly.end());
		poly.push_back(1);
		reverse(poly.begin(), poly.end());
		for(int j=0; j<=1000; j++){
			d1[i][j] = poly[j];
		}
		poly = nt_fft::power(poly);
		for(int j=0; j<=1000; j++){
			d2[i][j] = poly[j];
		}
	}
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >> n >> k;
		int cnt = 0;
		while(n%2 && n != 1){
			n /= 2;
			cnt++;
		}
		printf("%d\n", d1[cnt][k]);
	}
}