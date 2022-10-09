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

const int mod = 1'000'000'007;
typedef modint<mod> mint;

int n, m;
basic_string<int> e[100005];
int s[100005], b[100005];
ll z[100005];

void dfs(int x, int p) {
	s[x] = 1;
	for (int j : e[x]) {
		if (j == p) continue;
		dfs(j, x);
		s[x] += s[j];
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n; i++) {
			e[i] = {};
		}

		int g = n-1;

		for (int i=1; i<n; i++) {
			int u, v;
			cin >> u >> v;
			e[u] += v;
			e[v] += u;
		}

		dfs(1, 1);
		for (int x=2; x<=n; x++) {
			z[x-2] = s[x] * 1ll * (n - s[x]);
		}
		sort(z, z+g, greater<ll>());

		int m;
		cin >> m;
		for (int i=0; i<m; i++) {
			cin >> b[i];
		}

		sort(b, b+m, greater<int>());

		mint sol = 0;

		if (m <= g) {
			// uzmi od kraja
			for (int i=0; i<g; i++) {
				sol += mint(z[i]) * (i < m ? b[i] : 1);
			}
		} else {
			// najveci sa proizvodom stavi
			mint pr = 1;
			for (int j=0; j<m-g+1; j++) {
				pr *= b[j];
			}
			sol += pr * z[0];
			for (int j=1; j<g; j++) {
				sol += mint(z[j]) * b[j+m-g];
			}
		}

		cout << sol() << "\n";
	}
}