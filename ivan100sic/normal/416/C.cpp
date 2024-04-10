#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct visitor {
	int c, p, id;
	bool operator< (const visitor& o) const {
		return p > o.p;
	}
} a[1005];

struct table {
	int c, id;
	bool operator< (const table& o) const {
		return c < o.c;
	}
} b[1005];

int n, m;
basic_string<pair<int, int>> sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].c >> a[i].p;
		a[i].id = i+1;
	}
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> b[i].c;
		b[i].id = i+1;
	}
	sort(a, a+n);
	sort(b, b+m);
	int prof = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (b[j].c >= a[i].c) {
				b[j].c = -1;
				prof += a[i].p;
				sol += {a[i].id, b[j].id};
				break;
			}
		}
	}
	cout << sol.size() << ' ' << prof << '\n';
	for (auto p : sol)
		cout << p.first << ' ' << p.second << '\n';
}