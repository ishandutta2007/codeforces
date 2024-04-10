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

const int mod = 998'244'353;
typedef modint<mod> mint;

vector<int> expand(vector<int> a) {
	sort(begin(a), end(a), greater<int>());
	int c = 0;
	vector<int> r;
	for (int x : a) {
		c++;
		while (x--) {
			r.push_back(c);
		}
	}
	return r;
}


bool try_expand(vector<int> v, int k, int ub) {
	if (accumulate(begin(v), end(v), 0) > ub) return false;
	while (k--) {
		v = expand(v);
		if (accumulate(begin(v), end(v), 0) > ub) return false;
	}
	return true;
}

int rek_sol = 0;

bool rek(vector<int>& a, int k, int ub) {
	if (!try_expand(a, k, ub)) return false;
	// for (int x : a) cerr << x << ' ';
	// cerr << '\n';
	rek_sol++;
	for (int x=a.size()?a.back():1;; x++) {
		a.push_back(x);
		if (!rek(a, k, ub)) {
			a.pop_back();
			break;
		}
		a.pop_back();
	}
	return true;
}

int sd[2222];
mint p[2222];

void parts(int n) {
	memset(sd, 0, sizeof sd);
	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j+=i) {
			sd[j] += i;
		}
	}

	p[0] = 1;
	for (int x=1; x<=n; x++) {
		p[x] = 0;
		for (int k=0; k<x; k++) {
			p[x] += p[k] * sd[x-k];
		}
		p[x] *= mint(x).inv();
		// cerr << p[x]() << '\n';
	}
	cout << accumulate(p+1, p+n+1, mint(0))() << '\n';
}

mint dp[2][2022][2022];

void depe(int n) {
	for (int x=1; x<=n; x++) {
		dp[1][x][x] = 1;
	}

	mint sol = 0;

	for (int i=1; i<80; i++) {
		auto ol = dp[i%2];
		auto nu = dp[1-i%2];

		memset((void*)nu, 0, sizeof dp[0]);

		for (int u=1; u<=n; u++) {
			for (int v=1; v<=n; v++) {
				if (ol[u][v] == 0) continue;
				sol += ol[u][v];

				for (int z=u; z>=1; z--) {
					int k = v+(i+1)*z;
					if (k <= n) {
						nu[z][k] += ol[u][v];
					}
				}
			}
		}
	}

	cout << sol() << '\n';
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, k;
	cin >> n >> k;

	// {
	// 	cerr << "brute\n";
	// 	vector<int> a;
	// 	rek(a, k-1, n);
	// 	cerr << rek_sol-1 << '\n';
	// 	rek_sol = 0;
	// }

	if (k >= 3) {
		vector<int> a;
		rek(a, k-1, n);
		cout << rek_sol-1 << '\n';
	} else if (k == 1) {
		// sum of part nums
		parts(n);
	} else if (k == 2) {
		// dp
		depe(n);
	}


}