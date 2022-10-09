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

	template<class T>
	modint operator^= (T arg) {
		return *this = *this ^ arg;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

mint f[30];

int n;
ll a[24];

mint cnt1(ll x) {
	// daj prvu polovinu
	int h = n/2;
	map<ll, map<int, int>> mp;

	for (int mask=0; mask<(1<<h); mask++) {
		ll zbir = 0;
		for (int i=0; i<h; i++)
			if (mask & (1 << i))
				zbir += a[i];
		mp[zbir][__builtin_popcount(mask)] += 1;
	}

	mint z = 0;

	for (int mask=0; mask<(1<<n); mask+=(1<<h)) {
		ll zbir = 0;
		for (int i=h; i<n; i++)
			if (mask & (1 << i))
				zbir += a[i];
		auto it = mp.find(x - zbir);
		if (it == mp.end())
			continue;

		for (auto& p : it->second) {
			int c1 = __builtin_popcount(mask) + p.first;
			z += f[c1] * f[n-c1] * p.second;
		}
	}

	return z;
}

template<class T>
void rek1(T& mp, ll z1, ll z2, int c1, int c2, int i, int h) {
	if (i == h) {
		mp[{z1, z2}][{c1, c2}] += 1;
		return;
	}

	rek1(mp, z1, z2, c1, c2, i+1, h);
	rek1(mp, z1+a[i], z2, c1+1, c2, i+1, h);
	rek1(mp, z1, z2+a[i], c1, c2+1, i+1, h);
}

template<class T>
void rek2(T& mp, ll z1, ll z2, int c1, int c2, int i, int h, mint& z) {
	if (i == h) {
		auto it = mp.find({z1, z2});
		if (it == mp.end())
			return;
		for (auto& p : it->second) {
			int d1 = c1 + p.first.first;
			int d2 = c2 + p.first.second;
			int d3 = n-d1-d2;
			z += f[d1] * f[d2] * f[d3] * p.second;
		}
		return;
	}

	rek2(mp, z1     , z2     , c1  ,   c2, i+1, h, z);
	rek2(mp, z1-a[i], z2     , c1+1,   c2, i+1, h, z);
	rek2(mp, z1     , z2-a[i], c1  , c2+1, i+1, h, z);
}

mint cnt2(ll x1, ll x2) {
	// daj prvu polovinu
	int h = n/2;
	map<pair<ll, ll>, map<pair<int, int>, int>> mp;
	rek1(mp, 0, 0, 0, 0, 0, h);
	mint z = 0;
	rek2(mp, x1, x2, 0, 0, h, n, z);
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = 1;
	for (int i=1; i<30; i++)
		f[i] = f[i-1] * i;

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	int k;
	cin >> k;
	basic_string<int> b(k, 0);
	for (int& x : b)
		cin >> x;
	sort(b.begin(), b.end());

	mint sol = f[n];
	if (k == 1) {
		sol -= cnt1(b[0]);
	} else if (k == 2) {
		sol -= cnt1(b[0]);
		sol -= cnt1(b[1]);
		sol += cnt2(b[0], b[1]-b[0]);
	}

	cout << (int)sol << '\n';
}