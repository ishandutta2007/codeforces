#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const double M_PI = acos(-1);

namespace fft{
	typedef complex<double> base;
	void fft(vector<base> &v, bool inv){
		vector<base> w(v.size());
		for(int i=2; i<=v.size(); i<<=1){
			int bsz = v.size() / i;
			base ang(cos(2 * M_PI / i), sin(2 * M_PI / i));
			if(inv) ang = base(1, 0) / ang;
			for(int j=0; j<bsz; j++){
				for(int k=0; k<i; k++){
					w[k] = v[bsz * k + j];
				}
				base pw(1, 0);
				for(int k=0; k<i/2; k++){
					base a = w[2*k], b = w[2*k+1] * pw;
					v[bsz * k + j] = a + b;
					v[bsz * k + j + v.size()/2] = a - b;
					pw *= ang;
				}
			}
		}
		if(inv){
			for(int i=0; i<v.size(); i++){
				v[i] /= v.size();
			}
		}
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
		for(int i=0; i<n; i++) ret[i] = (round(fv[i].real()) > 0);
		return ret;
	}
	vector<lint> power(vector<lint> &v){
		vector<base> fv(v.begin(), v.end());
		int n = 1;
		while(n < v.size()) n <<= 1;
		n <<= 1;
		fv.resize(n);
		fft(fv, 0);
		for(int i=0; i<n; i++) fv[i] *= fv[i];
		fft(fv, 1);
		vector<lint> ret(n);
		for(int i=0; i<n; i++) ret[i] = (round(fv[i].real()) > 0);
		return ret;
	}
}

int main(){
	vector<lint> piv(1001);
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		piv[t] = 1;
	}
	vector<lint> ret(1001);
	ret[0] = 1;
	while(k){
		if(k&1) ret = fft::multiply(ret, piv);
		piv = fft::power(piv);
		k >>= 1;
	}
	for(int i=0; i<ret.size(); i++){
		if(ret[i]) printf("%d ", i);
	}
}