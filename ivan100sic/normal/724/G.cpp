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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

int n, m;
ll xorpath[100005];
vector<pair<int, ll>> e[100005];

vector<int> vis;

int idx[100005], t;
vector<ll> machine;

void dfs(int x) {
	vis.push_back(x);
	idx[x] = ++t;
	for (auto p : e[x]) {
		int y = p.first;
		ll w = p.second;
		if (idx[y] == 0) {
			xorpath[y] = xorpath[x] ^ w;
			dfs(y);
		} else if (idx[y] < idx[x]) {
			machine.push_back(xorpath[x] ^ xorpath[y] ^ w);
		}
	}
}

int bc_nodes[60];
mint pw2[60];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int x, y;
		ll w;
		cin >> x >> y >> w;
		e[x].push_back({y, w});
		e[y].push_back({x, w});
	}

	pw2[0] = 1;
	for (int i=1; i<60; i++)
		pw2[i] = pw2[i-1] + pw2[i-1];

	mint sol = 0;

	for (int x=1; x<=n; x++) {
		if (idx[x] == 0) {
			machine = {};
			vis = {};
			dfs(x);

			auto& a = machine;

			ll basis = 0;
			for (ll x : a)
				basis |= x;

			int k = 0;
			for (int i=0; i<60; i++) {
				ll num = -1;
				for (int j=0; j<(int)a.size(); j++) {
					if (a[j] & (1ll << i)) {
						num = a[j];
						break;
					}
				}
				if (num != -1) {
					k++;
					for (int j=0; j<(int)a.size(); j++) {
						if (a[j] & (1ll << i)) {
							a[j] ^= num;
						}
					}
				}
			}

			// cerr << "k: " << k << '\n';

			// k - baza
			fill(bc_nodes, bc_nodes + 60, 0);
			for (int x : vis) {
				for (int i=0; i<60; i++) {
					if (xorpath[x] & (1ll << i)) {
						bc_nodes[i]++;
					}
				}
			}

			// svi zajedno
			for (int i=0; i<60; i++) {
				mint tmp = 0;
				if (basis & (1ll << i)) {
					tmp = pw2[k-1] * ((ll)vis.size() * ((ll)vis.size() - 1) / 2);
				} else {
					tmp = pw2[k] * mint(bc_nodes[i]) * ((int)vis.size() - bc_nodes[i]);
				}
				sol += tmp * pw2[i];
			}
		}
	}
	cout << (int)sol << '\n';
}