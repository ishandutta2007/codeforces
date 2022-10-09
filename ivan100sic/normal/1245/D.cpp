#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct grana {
	int u, v;
	ll c;
	bool operator< (const grana& b) const {
		return c < b.c;
	}
};

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	bool spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return false;
		p[x] = y;
		return true;
	}
};

vector<grana> v;
int n;
int x[2005], y[2005];
int c[2005], k[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> x[i] >> y[i];
	for (int i=1; i<=n; i++)
		cin >> c[i];
	for (int i=1; i<=n; i++)
		cin >> k[i];

	for (int i=1; i<n; i++) {
		for (int j=i+1; j<=n; j++) {
			v.push_back({i, j, (k[i] + k[j] + 0ll) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))});
		}
	}

	for (int i=1; i<=n; i++)
		v.push_back({0, i, c[i]});

	sort(v.begin(), v.end());
	dsu d(n+2);
	basic_string<pair<int, int>> gr;
	basic_string<int> pwr;
	ll sol = 0;
	for (auto [x, y, c] : v) {
		if (d.spoji(x, y)) {
			if (x == 0)
				pwr += y;
			else
				gr.push_back({x, y});
			sol += c;
		}
	}

	cout << sol << '\n';

	cout << pwr.size() << '\n';
	for (int x : pwr)
		cout << x << ' ';
	cout << '\n';

	cout << gr.size() << '\n';
	for (auto [x, y] : gr)
		cout << x << ' ' << y << '\n';
}