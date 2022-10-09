#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<ld> cd;
const ld pi = acos(ld(-1));
const int N = 65536;
const int LOGN = 16;
const int MOD = 1'000'000'007;

int bitinv(int x) {
	int y = 0;
	for (int i=0; i<LOGN; i++) {
		y = (y << 1) | (x & 1);
		x >>= 1;
	}
	return y;
}

void fft(vector<cd>& a, bool inv) {
	for (int i=0; i<N; i++) {
		int j = bitinv(i);
		if (j < i)
			swap(a[j], a[i]);
	}
	for (int h=1; h<N; h<<=1) {
		cd step = exp(cd(0, pi/h * (inv ? -1 : 1)));
		for (int j=0; j<N; j+=2*h) {
			cd w = 1;
			for (int k=j; k<j+h; k++) {
				cd u = a[k], v = a[k+h] * w;
				a[k] = u + v;
				a[k+h] = u - v;
				w *= step;
			}
		}
	}
	if (inv) {
		for (int i=0; i<N; i++)
			a[i] /= N;
	}
}

vector<int> poly_conv(vector<int> a, vector<int> b) {
	vector<cd> c(N), d(N), e(N);
	for (int i=0; i<N; i++) {
		c[i] = cd(a[i] & 0xffff, a[i] >> 16);
		d[i] = cd(b[i] & 0xffff);
		e[i] = cd(b[i] >> 16);
	}
	fft(c, false);
	fft(d, false);
	fft(e, false);
	for (int i=0; i<N; i++)
		d[i] *= c[i], e[i] *= c[i];
	fft(d, true);	
	fft(e, true);
	vector<int> f(N);
	for (int i=0; i<N; i++) {
		ll p = (ll)round(d[i].real()) % MOD;
		ll q = (ll)round(d[i].imag()) % MOD;
		ll r = (ll)round(e[i].real()) % MOD;
		ll s = (ll)round(e[i].imag()) % MOD;
		f[i] = (p + ((q+r) << 16) + (s << 32)) % MOD;
		f[i] += (f[i] < 0) * MOD;
	}
	return f;
}

vector<int> poly_mul(vector<int> a, vector<int> b) {
	int n = a.size(), m = b.size();
	a.resize(N);
	b.resize(N);
	auto c = poly_conv(a, b);
	c.resize(n+m-1);
	return c;
}

int pw(int x, int y) {
	if (!y)
		return 1;
	int z = pw(x, y >> 1);
	z = z*1ll*z % MOD;
	if (y & 1)
		z = z*1ll*x % MOD;
	return z;
}

int f[N], finv[N];
vector<int> f0;

void extend(vector<int>& v, int t) {
	int w = 1;
	for (int i=0; i<(int)v.size(); i++) {
		v[i] = v[i] * 1ll * w % MOD;
		w = w * 1ll * t % MOD;
	}
}

vector<int> g(int k) {
	if (k == 1)
		return f0;
	auto gh = g(k >> 1);
	auto g2h = gh;
	extend(g2h, pw(2, k >> 1));
	auto gg = poly_mul(gh, g2h);
	gg.resize(30005);
	if (k & 1) {
		extend(gg, 2);
		gg = poly_mul(gg, f0);
		gg.resize(30005);
	}
	return gg;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = 1;
	for (int i=1; i<N; i++) {
		f[i] = f[i-1] * 1ll * i % MOD;
		finv[i] = pw(f[i], MOD-2);
	}
	f0 = vector<int>(finv+0, finv+30005);
	f0[0] = 0;

	ll n, k;
	cin >> n >> k;
	if (n > k) {
		cout << "0\n";
		return 0;
	}

	auto v = g(n);
	int sol = 0;
	for (int x=1; x<=k; x++) {
		// cerr << "x = " << x << ", k = " << v[x] << '\n';
		sol = (sol + finv[k-x] * 1ll * v[x]) % MOD;
	}
	cout << (sol * 1ll * f[k] % MOD) << "\n";
}