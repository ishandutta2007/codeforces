#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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
struct prava {
	T a, b, c;
	// ax + by + c == 0
	// normalizovano prema gcd
	// normalizovano da je (a, b, c) >= (0, 0, 0)

	void normalizuj() {
		T g = gcd(abs(a), gcd(abs(b), abs(c)));
		a /= g;
		b /= g;
		c /= g;
		if (vector<T>({a, b, c}) < vector<T>(3, 0)) {
			a *= -1;
			b *= -1;
			c *= -1;
		}
	}

	bool operator< (const prava& q) const {
		if (a != q.a) return a < q.a;
		if (b != q.b) return b < q.b;
		if (c != q.c) return c < q.c;
		return false;
	}
};

int n;
int x[1005], y[1005];

int k;
map<pair<int, int>, int> mp;

pair<int, int> normalizuj(int x, int y) {
	int g = gcd(abs(x), abs(y));
	x /= g;
	y /= g;
	if (make_pair(x, y) < make_pair(0, 0)) {
		x *= -1;
		y *= -1;
	}
	return {x, y};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> x[i] >> y[i];

	ll sol = n*(n-1) / 2;
	sol = sol*(sol-1) / 2;

	set<prava<int>> sp;

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			prava<int> p;
			p.a = y[j] - y[i];
			p.b = x[i] - x[j];
			p.c = x[i]*y[j] - x[j]*y[i];
			p.normalizuj();
			sp.insert(p);
		}
	}

	for (auto p : sp) {
		auto q = normalizuj(p.a, p.b);
		mp[q]++;
	}

	sol = sp.size() * (sp.size()-1ll) / 2;

	for (auto [x, y] : mp)
		sol -= y*(y-1ll) / 2;

	cout << sol << '\n';
}