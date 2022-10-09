// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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
		x = (x * 1ull * other.x) % m;
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

const int MOD = 998244353;
typedef modint<MOD> mint;

struct cond {
	int l, r, x;
	bool operator< (const cond& b) const {
		return tie(l, r) < tie(b.l, b.r);
	}
};

int n, k, m;
cond a[500005];
int z[500005], id[500005];
mint dp[500005], zz[500005];
int ric[500005];

#define BRZO

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> m;
	for (int i=0; i<m; i++) {
		cin >> a[i].l >> a[i].r >> a[i].x;
		a[i].l--;
	}
	sort(a, a+m);

	mint p = 1;
	for (int b=0; b<k; b++) {
		memset(z, 0, sizeof z);
		memset(zz, 0, sizeof zz);
		memset(dp, 0, sizeof dp);
		for (int i=0; i<m; i++) {
			if (a[i].x & (1 << b)) {
				z[a[i].l]++;
				z[a[i].r]--;
			}
		}
		for (int i=1; i<=n; i++)
			z[i] += z[i-1];
		for (int i=0, cnt=0; i<=n; i++) {
			id[i] = cnt;
			cnt += z[i] == 0;
		}
		vector<pair<int, int>> v;
		for (int i=0; i<m; i++) {
			if (!(a[i].x & (1 << b))) {
				int lx = id[a[i].l] + 1;
				int rx = id[a[i].r];
				while (v.size() && v.back().first <= lx && rx <= v.back().second)
					v.pop_back();
				v.emplace_back(lx, rx);
			}
		}
		int f = id[n];

#ifndef BRZO
		cerr << "f = " << f << '\n';
		for (auto [x, y] : v)
			cerr << "[" << x << ", " << y << "] ";
		cerr << '\n';

		// dp[x] = broj nacina da zadnji koji stavimo bude jednak x
		dp[0] = 1;
		for (int x=1; x<=f; x++) {
			// sporo ali sigurno
			for (int y=0; y<x; y++) {
				bool ok = true;
				for (auto [l, r] : v) {
					if (y+1 <= l && r <= x-1)
						ok = false;
				}
				if (ok) {
					dp[x] += dp[y];
				}
			}
		}

		// resenje je svako x u zadnjem
		mint q;
		if (v.size() == 0) {
			q = 1;
		} else {
			auto [l, r] = v.back();
			q = 0;
			for (int x=l; x<=r; x++)
				q += dp[x];
		}

		cerr << (int)q << '\n';

		p *= q;
#else
		f++;
		v.emplace_back(f, f);

		dp[0] = 1;
		zz[1] = 1; // zz je exclusive prefix sum
		int lll = 0, id = 0;
		for (int x=1; x<=f; x++) {
			while (id < (int)v.size() && v[id].second < x) {
				lll = max(lll, v[id].first);
				id++;
			}
			// <=> mora y >= maxL
			dp[x] = zz[x] - zz[lll];
			zz[x+1] = zz[x] + dp[x];
		}

		p *= dp[f];
#endif
	}
	cout << (int)p << '\n';
}

// I will still practice daily...