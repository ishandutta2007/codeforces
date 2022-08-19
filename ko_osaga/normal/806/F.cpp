#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
int n, m, mod;

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
}

vector<lint> f[30];
vector<lint> g[30];

vector<lint> add(vector<lint> a, vector<lint> b){
	vector<lint> ans(max(a.size(), b.size()));
	for(int i=0; i<a.size(); i++) ans[i] += a[i];
	for(int i=0; i<b.size(); i++) ans[i] += b[i];
	if(ans.size() > n) ans.resize(n);
	for(auto &i : ans) i %= mod;
	return ans;
}

vector<lint> mul(vector<lint> a, vector<lint> b){
	vector<lint> ans = fft::multiply(a, b);
	if(ans.size() > n) ans.resize(n);
	for(auto &i : ans) i %= mod;
	return ans;
}

map<int, vector<lint>> mp1, mp2;

vector<lint> fun(int x){
	if(x == 0){
		vector<lint> v = {1};
		return v;
	}
	if(mp1.find(x) != mp1.end()) return mp1[x];
	if(x % 2 == 1) return mp1[x] = mul(fun(x - 1), f[0]);
	auto l = fun(x / 2);
	return mp1[x] = mul(l, l);
}

vector<lint> sum(int x){
	if(x == 0) return vector<lint>();
	if(mp2.find(x) != mp2.end()) return mp2[x];
	if(x % 2 == 1) return mp2[x] = add(sum(x-1), fun(x-1));
	auto l = sum(x / 2);
	auto v = fun(x / 2);
	v[0]++;
	return mp2[x] = mul(l, v);
}

int solve(int m){	
	auto ret = sum((m+1) / 2);
	lint ans = 0;
	for(int j=0; j<ret.size(); j+=2) ans += ret[j];
	return ans % mod;
}

int main(){
	cin >> n >> m >> mod;
	f[0] = {1, 2, 1};
	int ans = 0;
	for(int i=1; (m >> i); i++){
		ans += solve(m >> i);
	}
	cout << ans % mod;
}