#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct komanda {
	int t, l, r;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> g(n), a(n);
	vector<komanda> c(m);

	for (int i=0; i<m; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		l--, r--;
		if (t == 1) {
			for (int i=l; i<r; i++)
				g[i] = 1;
		}
		c[i] = {t, l, r};
	}

	for (int i=0, v=10000; i<n; i++) {
		a[i] = v;
		v -= 1-g[i];
	}

	for (int i=0; i<m; i++) {
		if (c[i].t == 0) {
			int inv = 0;
			for (int j=c[i].l; j<c[i].r; j++) {
				if (a[j] > a[j+1])
					inv++;
			}
			if (inv == 0) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for (int x : a)
		cout << x << ' ';
	cout << '\n';
}