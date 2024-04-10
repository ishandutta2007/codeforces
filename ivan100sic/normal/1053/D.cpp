#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 2000005;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
		}			
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}


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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

int n;
int a[200005];
int maxv[2000005], maxc[2000005];
int added[2000005];
int c[2000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	int dod = 0;

	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a, a+n);
	reverse(a, a+n);

	for (int i=0; i<n; i++) {
		int& x = a[i];

		if (added[x]) {
			x--;

			if (added[x]) {
				dod = 1;
			} else {

				added[x] = 1;

				auto v = factor_small(x);
				for (auto p : v) {
					added[p.first] = 1;
					if (p.second > maxv[p.first]) {
						maxv[p.first] = p.second;
						maxc[p.first] = 1;
					} else if (p.second == maxv[p.first]) {
						maxc[p.first]++;
					}
				}

			}
		} else {

			added[x] = 1;

			// dodaj
			if (1 > maxv[x]) {
				maxv[x] = 1;
				maxc[x] = 1;
			} else if (1 == maxv[x]) {
				maxc[x]++;
			}

		}
	}

	// nadji broj bez koga se moze
	for (int i=0; i<n; i++) {
		int x = a[i];

		auto v = factor_small(x);
		bool mozda = true;

		for (auto p : v) {
			if (maxv[p.first] > p.second || (maxv[p.first] == p.second && maxc[p.first] > 1)) {
				//
			} else {
				mozda = false;
			}
		}

		if (mozda)
			dod = 1;
	}

	mint q = 1;
	for (int i=0; i<2000005; i++)
		if (maxv[i])
			q *= mint(i) ^ maxv[i];

	q += dod;

	cout << (int)q << '\n';
}

/*
18
163 191 179 139 149 109 137 137 127 113 131 167 197 103 179 103 193 151

103 103 109 113 127 131 137 137 139 149 151 163 167 179 179 191 193 197
*/