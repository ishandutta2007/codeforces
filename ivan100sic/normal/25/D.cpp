#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x]) {
			return  x;
		}
		return p[x] = e(p[x]);
	}

	bool merge(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return false;
		p[x] = y;
		return true;
	}
};

int n;
dsu d(0);

basic_string<pair<int, int>> rm, ad;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	d = dsu(n+1);
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		if (!d.merge(x, y)) {
			rm += {x, y};
		}
	}

	set<int> s;
	for (int i=1; i<=n; i++)
		s.insert(d.e(i));

	vector<int> v(s.begin(), s.end());
	for (int i=0; i<(int)v.size()-1; i++)
		ad += {v[i], v[i+1]};

	cout << rm.size() << '\n';
	for (int i=0; i<(int)rm.size(); i++) {
		cout << rm[i].first << ' ' << rm[i].second << ' ' << ad[i].first;
		cout << ' ' << ad[i].second << '\n';
	}
}