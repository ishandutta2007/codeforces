#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod = 998244353;
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;
const int sz = 32768;

template<class T>
T eea(T a, T b, T& x, T& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T g = eea(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

int inverse(int n) {
	int x, y;
	eea(n, mod, x, y);
	x %= mod;
	if (x < 0)
		x += mod;
	return x;
}

int ad(int x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
	return x;
}

int sb(int x, int y) {
	x -= y;
	if (x < 0)
		x += mod;
	return x;
}

void fft(vector<int>& a, bool invert) {
	int n = a.size();

	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for (; j & bit; bit >>= 1)
			j ^= bit;
		j ^= bit;

		if (i < j)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		int wlen = invert ? root_1 : root;
		for (int i = len; i < root_pw; i <<= 1)
			wlen = 1LL * wlen * wlen % mod;

		for (int i = 0; i < n; i += len) {
			int w = 1;
			for (int j = 0; j < len / 2; j++) {
				int u = a[i+j], v = a[i+j+len/2] * 1ll * w % mod;
				a[i+j] = ad(u, v);
				a[i+j+len/2] = sb(u, v);
				w = w * 1ll * wlen % mod;
			}
		}
	}

	if (invert) {
		int n_1 = inverse(n);
		for (int& x : a)
			x = x * 1ll * n_1 % mod;
	}
}

int n, K, k, w;
int l[55], r[55], u[55], q[55], d[55];
int a[20005];

vector<int> dp(vector<int> a) {
	vector<int> d(sz);
	d[0] = 1;
	int k = 0;
	for (int x : a) {
		vector<int> tmp(sz);
		k++;
		for (int i=0; i<=k+1; i++) {
			tmp[i] = ad(tmp[i], d[i]);
			if (i > 0)
				tmp[i] = ad(tmp[i], d[i-1] * 1ll * x % mod);
		}
		swap(d, tmp);
	}
	return d;
}

vector<int> blok[55];

vector<int> spoji(vector<int> a, vector<int> b) {
	fft(a, false);
	fft(b, false);
	for (int i=0; i<sz; i++)
		a[i] = a[i] * 1ll * b[i] % mod;
	fft(a, true);
	return a;
}

int f[20005], finv[20005];

int bk(int n, int k) {
	if (n < 0 || k < 0 || n-k < 0)
		return 0;
	return f[n] * 1ll * finv[n-k] % mod * finv[k] % mod;
}

vector<int> igd_slow(vector<int> d, int n, int q) {
	vector<int> r(sz);
	for (int k=0; k<sz; k++) {
		int qi = 1;
		for (int i=k; i>=0; i--) {
			r[k] = ad(r[k], bk(n-i, k-i) * 1ll * qi % mod * d[i] % mod);
			qi = qi * 1ll * q % mod;
		}
	}

	return r;
}

vector<int> igd_fast(vector<int> d, int n, int q) {
	vector<int> alfa(sz), beta(sz);
	int qi = 1;
	for (int i=0; i<=n; i++) {
		alfa[i] = d[i] * 1ll * f[n-i] % mod;
		beta[i] = qi * 1ll * finv[i] % mod;
		qi = qi * 1ll * q % mod;
	}
	auto r = spoji(alfa, beta);
	for (int i=0; i<sz; i++)
		r[i] = i <= n ? r[i] * 1ll * finv[n-i] % mod : 0;
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);


	f[0] = finv[0] = 1;
	for (int i=1; i<20005; i++) {
		f[i] = f[i-1] * 1ll * i % mod;
		finv[i] = inverse(f[i]);
	}

	cin >> n >> K;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i] = ad(a[i], 0);
	}

	cin >> w;
	for (int i=0; i<w; i++) {
		int t;
		cin >> t;
		if (t == 2) {
			cin >> q[i] >> l[i] >> r[i] >> d[i];
			d[i] = ad(d[i], 0);
			q[i] = ad(q[i], 0);
		} else {
			int dd;
			cin >> q[i] >> l[i] >> dd;
			dd = ad(dd, 0);
			q[i] = ad(q[i], 0);
			r[i] = l[i];
			d[i] = sb(dd, a[l[i]-1]);
		}
		l[i]--;
	}
	k = copy(l, l+w, u) - u;
	k = copy(r, r+w, u+k) - u;
	u[k++] = 0;
	u[k++] = n;
	sort(u, u+k);
	k = unique(u, u+k) - u;
	k--;

	for (int i=0; i<k; i++) {
		blok[i] = dp(vector<int>(a+u[i], a+u[i+1]));
	}

	for (int i=0; i<w; i++) {
		vector<int> sol(sz);
		sol[0] = 1;
		int fr = lower_bound(u, u+k, l[i]) - u;
		int to = lower_bound(u, u+k, r[i]) - u;

		for (int j=0; j<k; j++) {
			sol = spoji(sol, igd_fast(blok[j], u[j+1]-u[j],
				 sb((fr <= j && j < to)*d[i], q[i])));
		}
		int t = sol[K];
		if (K & 1)
			t = sb(0, t);
		cout << t << '\n';
	}
}