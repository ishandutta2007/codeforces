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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

mint f[1000005], finv[1000005];

mint bk(int n, int k) {
	if (n < 0 || k < 0 || n-k < 0)
		return 0;
	return f[n] * finv[k] * finv[n-k];
}

const int SITO_MAX = 1000005;

int fa[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (fa[i] == 0) {
				fa[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > fa[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				fa[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = fa[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

void divs_rek(unsigned x, int k, vector<pair<int, int>>& a, vector<int>& b) {
	if (k == (int)a.size()) {
		b.push_back(x);
		return;
	}
	for (int i=0; i<=a[k].second; i++) {
		divs_rek(x, k+1, a, b);
		x *= a[k].first;
	}
}

vector<int> divs(int x) {
	auto v = factor_small(x);
	vector<int> a;
	divs_rek(1, 0, v, a);
	// nebitan redosled
	return a;
}

int mob[SITO_MAX], n, k, q;
int c[SITO_MAX];
mint val;

void dod(int x) {
	auto a = divs(x);
	for (int y : a) {
		val -= bk(c[y], k) * mob[y];
		c[y]++;
		val += bk(c[y], k) * mob[y];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	iota(mob+1, mob+SITO_MAX, 1);
	for (int i=1; i<SITO_MAX; i++)
		for (int j=2*i; j<SITO_MAX; j+=i)
			mob[j] -= mob[i];
	f[0] = finv[0] = 1;
	for (int i=1; i<SITO_MAX; i++)
		f[i] = f[i-1] * i, finv[i] = f[i].inv();

	cin >> n >> k >> q;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		dod(x);
	}

	for (int i=0; i<q; i++) {
		int x;
		cin >> x;
		dod(x);
		cout << (int)val << '\n';
	}
}

// I will still practice daily...