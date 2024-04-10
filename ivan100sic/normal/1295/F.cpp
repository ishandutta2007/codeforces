// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 998244353;
typedef modint<mod> mint;

template<class T = mint>
struct binomial {
	vector<T> f, finv;

	binomial(int n) : f(n), finv(n) {
		f[0] = finv[0] = 1;
		for (int i=1; i<n; i++) {
			f[i] = f[i-1] * i;
			finv[i] = f[i].inv();
		}
	}

	mint choose(int n, int k) {
		mint w = 1;
		for (int i=n-k+1; i<=n; i++)
			w *= i;
		return w * finv[k];
	}
};

int n, m;
int l[55], r[55], u[105];

mint d[55][105][55];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	binomial b(555);
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> l[i] >> r[i], l[i] += 105, r[i] += 106;
	reverse(l, l+n);
	reverse(r, r+n);
	for (int i=0; i<n; i++)
		l[i] += i, r[i] += i;
	l[n] = 1012012012;
	r[n] = l[n] + 1;
	n++;
	for (int i=0; i<n; i++)
		u[m++] = l[i], u[m++] = r[i];
	sort(u, u+m);
	m = unique(u, u+m) - u;

	for (int i=0; i<n; i++) {
		l[i] = lower_bound(u, u+m, l[i]) - u;
		r[i] = lower_bound(u, u+m, r[i]) - u;
	}

	// d[i][j][k] = posle i-tog ulaza, j-to parce dobija na poziciji x vrednost binom(x, k) * d[i][j][k]

	for (int j=0; j<m; j++) {
		d[0][j][0] = 1;
	}

	for (int i=0; i<n-1; i++) {
		int l = ::l[i], r = ::r[i];
		for (int j=l; j<r; j++) {
			for (int k=0; k<=i; k++) {
				mint o = d[i][j][k];
				mint v1 = o * (b.choose(u[j+1], k+1) - b.choose(u[j], k+1));
				for (int t=j+1; t<m; t++) {
					d[i+1][t][0] += v1;
				}
				d[i+1][j][0] -= o * b.choose(u[j], k+1);
				d[i+1][j][k+1] += o;
			}
		}
	}

	mint z = d[n-1][m-1][0];
	for (int i=0; i<n; i++)
		z *= mint(u[r[i]] - u[l[i]]).inv();

	cout << z() << '\n';
}