#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ull x, y, v;
};

int n;
vector<ull> a, b;
pt c[200005];
vector<vector<ull>> d;

void sq(vector<ull>& v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

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

const ull MOD1 = 1000000007;
const ull MOD2 = 1000000009;

struct frac {
	ull p, q;

	bool operator== (const frac& b) const {
		ull v11 = (p % MOD1 * (b.q % MOD1)) % MOD1;
		ull v12 = (q % MOD1 * (b.p % MOD1)) % MOD1;
		if (v11 != v12)
			return false;
		ull v21 = (p % MOD2 * (b.q % MOD2)) % MOD2;
		ull v22 = (q % MOD2 * (b.p % MOD2)) % MOD2;
		if (v21 != v22)
			return false;

		// 2^64
		return p*b.q == q*b.p;
	}
};

bool deli(ull a, ull b, ull c) {
	ull g = gcd(a, b);
	a /= g;
	g = gcd(a, c);
	return a == g;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		ull x, y, v;
		cin >> x >> y >> v;
		c[i] = {x, y, v};
		a.push_back(x);
		b.push_back(y);
	}
	sq(a);
	sq(b);

	int rows = a.size();
	int cols = b.size();

	if (rows * 1ll * cols != n) {
		cout << "0\n";
		return 0;
	}

	d.assign(rows, vector<ull>(cols, 0));
	for (int i=0; i<n; i++) {
		int rr = lower_bound(a.begin(), a.end(), c[i].x) - a.begin();
		int cc = lower_bound(b.begin(), b.end(), c[i].y) - b.begin();
		d[rr][cc] = c[i].v;
	}

	bool ok = true;
	// verifikuj proizvoBd
	for (int i=0; i<rows-1; i++) {
		for (int j=0; j<cols-1; j++) {
			frac a = {d[i][j], d[i+1][j]};
			frac b = {d[i][j+1], d[i+1][j+1]};
			if (!(a == b)) {
				ok = false;
			}
		}
	}

	if (!ok) {
		cout << "0\n";
		return 0;
	}

	ull sol = 0;

	ull v0 = d[0][0];
	ull grow = 0;
	for (int j=0; j<cols; j++)
		grow = gcd(grow, d[0][j]);
	ull gcol = 0;
	for (int i=0; i<rows; i++)
		gcol = gcd(gcol, d[i][0]);

	set<ull> divs;
	for (ull i=1; i*i<=grow; i++) {
		if (grow % i == 0) {
			divs.insert(i);
			divs.insert(grow / i);
		}
	}
	for (ull g : divs) {
		// v0 | gcol * g
		if (deli(v0, gcol, g)) {
			sol++;
		}
	}
	cout << sol << '\n';
}