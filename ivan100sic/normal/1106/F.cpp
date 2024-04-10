#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int m>
struct modint {

	unsigned x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * 1ll * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator int () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	template<class T>
	modint operator^ (T arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

typedef modint<998244352> miq;
typedef modint<998244353> mip;

typedef vector<miq> vec;
typedef vector<vec> mat;

mip root = 3, rsh_inv = (mip(3) ^ 40000).inv();

const int SH = 40000;
pair<mip, int> small[SH];

bool cmp(pair<mip, int> a, pair<mip, int> b) {
	return (int)a.first < (int)b.first;
}

miq discrete_log(int y) {
	mip p = y;
	for (int i=0; i<30000; i++) {
		pair<mip, int> f = {p, -1};
		auto it = lower_bound(small, small+SH, f, cmp);
		if (it != small+SH && it->first == f.first) {
			return i*SH + it->second;
		}
		p *= rsh_inv;
	}
	return -1;
}

mat matmul(mat a, mat b) {
	mat c = a;
	int n = a.size();
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			miq z = 0;
			for (int k=0; k<n; k++) {
				z += a[i][k] * b[k][j];
			}
			c[i][j] = z;
		}
	return c;
}

mat eye(int k) {
	mat a(k, vec(k));
	for (int i=0; i<k; i++)
		a[i][i] = 1;
	return a;
}

mat matpow(mat a, int k) {
	if (k == 0)
		return eye(a.size());
	if (k == 1)
		return a;

	mat b = matpow(a, k >> 1);
	b = matmul(b, b);
	if (k & 1) {
		b = matmul(b, a);
	}
	return b;
}

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

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

int gmodinv(ll a, ll mod) {
	ll x, y;
	eea(a, mod, x, y);
	// x*a + y*mod = 1
	x %= mod;
	if (x < 0)
		x += mod;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	{
		mip p = 1;
		for (int i=0; i<SH; i++) {
			small[i] = {p, i};
			p *= root;
		}
		sort(small, small+SH, cmp);
		// cerr << (int)discrete_log(4) << '\n';
	}
	
	int k;
	cin >> k;
	vector<int> b(k);
	for (int i=0; i<k; i++)
		cin >> b[i];

	mat a(k, vec(k));
	for (int i=1; i<k; i++)
		a[i][i-1] += 1;
	for (int i=0; i<k; i++)
		a[0][i] += b[i];

	int n, m;
	cin >> n >> m;

	mat ap = matpow(a, n-k);

	int z = (int)ap[0][0];

	cerr << "z " << z << '\n';
	
	// sad treba resiti x^z = m
	// ili u dlog prostoru: tz = dlog(m), x = dexp(t)

	int g = gcd(z, 998244352);
	int dm = (int)discrete_log(m);
	if (dm % g) {
		cout << "-1\n";
	} else {
		dm /= g;
		int tmod = 998244352 / g;
		z /= g;
		int f = gmodinv(z, tmod);
		f = f * 1ll * dm % 998244352;
		cout << (int)(root ^ f) << '\n';
	}
}