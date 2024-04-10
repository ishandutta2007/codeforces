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
const ll ZERO = 100*(MOD - 1ll);
typedef modint<MOD> mint;
const mint B = 43281;

int n, m;
ll a[600005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	m *= 2;
	for (int i=0; i<n; i++)
		cin >> a[i], a[i] <<= 1;
	for (int i=n; i<3*n; i++)
		a[i] = a[i-n] + m;

	vector<ll> sol;
	if (n % 2) {
		// namesti za i=0
		mint lh = 0, rh = 0;
		for (int j=n-n/2; j<n; j++)
			lh += B ^ (ZERO - a[j]);
		for (int j=n+1; j<=n+n/2; j++)
			rh += B ^ a[j];
		
		for (int i=n; i<2*n; i++) {
			mint x = lh * (B ^ a[i]);
			mint y = rh * (B ^ (ZERO - a[i]));
			if (x == y) {
				sol.push_back(a[i]);
			}

			lh -= B ^ (ZERO - a[i - n/2]);
			lh += B ^ (ZERO - a[i]);

			rh -= B ^ a[i + 1];
			rh += B ^ a[i + 1 + n/2];
		}
	} else {
		{
			mint lh = 0, rh = 0;
			for (int j=n-n/2; j<n; j++)
				lh += B ^ (ZERO - a[j]);
			for (int j=n; j<n+n/2; j++)
				rh += B ^ a[j];
			
			for (int i=n; i<2*n; i++) {
				ll mid = (a[i] + a[i-1]) / 2;
				mint x = lh * (B ^ mid);
				mint y = rh * (B ^ (ZERO - mid));
				if (x == y) {
					sol.push_back(mid);
				}

				lh -= B ^ (ZERO - a[i - n/2]);
				lh += B ^ (ZERO - a[i]);

				rh -= B ^ a[i];
				rh += B ^ a[i + n/2];
			}
		}

		{
			mint lh = 0, rh = 0;
			int h = n/2 - 1;
			for (int j=n-h; j<n; j++)
				lh += B ^ (ZERO - a[j]);
			for (int j=n+1; j<=n+h; j++)
				rh += B ^ a[j];
			
			for (int i=n; i<2*n; i++) {
				mint x = lh * (B ^ a[i]);
				mint y = rh * (B ^ (ZERO - a[i]));
				if (x == y && a[i+n/2] == a[i] + m/2) {
					sol.push_back(a[i]);
				}

				lh -= B ^ (ZERO - a[i - h]);
				lh += B ^ (ZERO - a[i]);

				rh -= B ^ a[i + 1];
				rh += B ^ a[i + 1 + h];
			}
		}
			
	}

	for (ll& x : sol)
		x %= m / 2;
	sort(begin(sol), end(sol));
	sol.erase(unique(begin(sol), end(sol)), end(sol));
	cout << sol.size() << '\n';
	for (ll x : sol)
		cout << x << ' ';
	cout << '\n';
}

// I will still practice daily...