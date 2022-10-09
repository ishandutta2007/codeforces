#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dsu {
	vector<int> p;

	dsu(int n = 105) : p(n+1) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	void m(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return;
		p[x] = y;
	}
} d[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		d[z].m(x, y);
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y, c=0;
		cin >> x >> y;
		for (int i=1; i<=100; i++)
			if (d[i].e(x) == d[i].e(y))
				c++;
		cout << c << '\n';
	}
}