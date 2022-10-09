#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dsu {
	vector<int> p;
	int sz;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
		sz = n;
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	void spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y) {
			cout << "NO\n";
			exit(0);
		}
		sz--;
		p[x] = y;
	}
};

struct seg {
	int l, r, i;
	bool operator< (const seg& b) const {
		return l < b.l;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<seg> a;
	for (int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		a.push_back({l, r, i});
	}
	dsu d(n);
	sort(a.begin(), a.end());
	set<pair<int, int>> s;
	for (auto [l, r, i] : a) {
		auto it = s.lower_bound({l, -1});
		while (it != s.end() && it->first < r) {
			d.spoji(i, it->second);
			++it;
		}
		s.insert({r, i});
	}
	cout << (d.sz == 1 ? "YES\n" : "NO\n");
}