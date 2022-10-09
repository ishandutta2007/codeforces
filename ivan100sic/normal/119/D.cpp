#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

const int mod1 = 1478924341;
const int mod2 = 1678924327;
typedef modint<mod1> mint1;
typedef modint<mod2> mint2;
const int bs = 567295;

struct hval {
	mint1 a;
	mint2 b;
	hval(int x = 0) : a(x), b(x) {}
	hval(mint1 a, mint2 b) : a(a), b(b) {}
	hval operator* (const hval& c) const {
		return {a*c.a, b*c.b};
	}
	hval operator+ (const hval& c) const {
		return {a+c.a, b+c.b};
	}
	hval operator- (const hval& c) const {
		return {a-c.a, b-c.b};
	}
	explicit operator ll() const {
		return (int)a * ll(mod2) + (int)b;
	}
};

string a, b;
int n;

hval haf[1000005], har[1000005], p[1000005];
hval hbr[1000005];
hval f[256];

void ans(int x, int y) {
	cout << x << ' ' << y << '\n';
	exit(0);
}

mt19937 eng;
uniform_int_distribution<int> dis(0, 1e9);
gp_hash_table<ll, vector<int>> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	getline(cin, a);
	getline(cin, b);
	if (a.size() != b.size())
		ans(-1, -1);
	n = a.size();
	reverse(b.begin(), b.end());

	for (int i=0; i<256; i++)
		f[i] = {dis(eng), dis(eng)};
	
	p[0] = 1;
	for (int i=1; i<=n; i++) {
		p[i] = p[i-1] * bs;
		haf[i] = haf[i-1] * bs + f[(int)a[i-1]];
		har[i] = har[i-1] * bs + f[(int)a[n-i]];
		hbr[i] = hbr[i-1] * bs + f[(int)b[n-i]];
	}

	for (int j=1; j<n; j++) {
		auto w = haf[n] - haf[j] * p[n-j];
		w = w - har[n-j];
		mp[(ll)w].push_back(j);
	}

	int ii = -1, jj = -1;

	for (int i=1; i<n; i++) {
		if (a[i-1] != b[i-1])
			break;
		auto w = (haf[n] - haf[i] * p[n-i]) - hbr[n-i];
		auto it = mp.find((ll)w);
		if (it != mp.end()) {
			auto& v = it->second;
			auto xd = lower_bound(v.begin(), v.end(), i);
			if (xd != v.end()) {
				ii = i-1;
				jj = *xd;
			}
		}
	}

	ans(ii, jj);
}