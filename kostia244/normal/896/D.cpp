#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<18;
int n, l, r;
ll m;
int bp(int a, int p) {
	int r = 1;
	while(p) {
		if(p&1) r = r*1ll*a%m;
		a = a*1ll*a%m, p>>=1;
	}
	return r;
}

int phi, nop = 0;
int p[maxn];
struct number {
	int val;
	array<int, 30> pv;
	number(int x = 0) {
		if(x == 0) {
			val = 0;
			fill(all(pv), 0);
			return;
		}
		for(int j = 0; j < nop; j++) {
			pv[j] = 0;
			while(x % p[j] == 0)
				x /= p[j], pv[j]++;
		}
		val = x;
	}
	friend number operator*(const number &a, const number &b) {
		number c;
		c.val = a.val * 1ll * b.val % m;
		for(int i = 0; i < nop; i++) c.pv[i] = a.pv[i] + b.pv[i];
		return c;
	}
	number inv() {
		number r;
		for(int i = 0; i < nop; i++) r.pv[i] = -pv[i];
		r.val = bp(val, phi-1);
		return r;
	}
	int real() {
		int v = val;
		for(int i = 0; i < nop; i++) v  = v * 1ll * bp(p[i], pv[i]) % m;
		return v;
	}
};
number fact[maxn], inv[maxn];
void setup() {
	phi = m;
	int tm = m;
	for(int i = 2; i*i <= m; i++) {
		if(tm%i) continue;
		phi -= phi/i;
		while(tm%i == 0)
			tm /= i;
		p[nop++] = i;
	}
	if(tm > 1) phi -= phi/tm, p[nop++] = tm;
	fact[0] = inv[0] = 1;
	for(int i = 1; i < maxn; i++) {
		fact[i] = fact[i-1]*number(i);
		inv[i] = fact[i].inv();
	}
}
int C(int n, int k) {
	if(k < 0 || n < k) return 0;
	return (fact[n]*inv[n-k]*inv[k]).real();
}
struct bin_prefix {// sum_{i<z} (n choose i) | n++ | z++
	int sum = 0, n = 0, z = 0;
	void inc_n() {
		if(z)
			sum = (3ll*m + sum + sum - C(n, z-1))%m;
		n++;
	}
	void inc_z() {
		sum = (m + sum + C(n, z))%m;
		z++;
	}
	void dec_z() {
		if(!z) return;
		z--;
		sum = (m + sum - C(n, z))%m;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> l >> r;
	setup();
	int res = 0;
	{
	bin_prefix L, R;
	for(int t = n+3; t--;) L.inc_z(), R.inc_z();
	for(int nx = 0; nx <= n; nx++) {//n-x
		int Lb, Rb;
		Lb = max(0, (n - nx) - r);
		Rb = max(-1, (n - nx) - l);
		while(L.n < nx) L.inc_n(), R.inc_n();
		while(L.z > Lb) L.dec_z();
		while(R.z-1 > Rb) R.dec_z();
		int d = (m + R.sum - L.sum)%m;
		res = (res + d*1ll*C(n, nx))%m;
		//cout << n-nx << " " << Lb << " " << Rb << " " << d*1ll*C(n, nx) << endl;
	}
	}
	{
	bin_prefix L, R;
	for(int t = n+3; t--;) L.inc_z(), R.inc_z();
	for(int nx = 0; nx <= n; nx++) {//n-x
		int Lb, Rb;
		Lb = max(0, (n - nx) - r - 1);
		Rb = max(-1, (n - nx) - l - 1);
		while(L.n < nx-1) L.inc_n(), R.inc_n();
		while(L.z > Lb) L.dec_z();
		while(R.z-1 > Rb) R.dec_z();
		int d = (m + R.sum - L.sum)%m;
		res = (res - d*1ll*C(n, nx-1))%m;
		res += res<0?m:0;
	}
	}
	cout << res << '\n';
	
}