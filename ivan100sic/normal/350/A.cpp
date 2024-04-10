#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int tl = -1e9, tr = 1e9;
	int lx = 1e9;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		tl = max(tl, x);
		lx = min(lx, x);
	}
	tl = max(tl, 2*lx);
	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		tr = min(tr, x-1);
	}

	cerr << tl << ' ' << tr << '\n';

	if (tl > tr)
		tl = -1;
	cout << tl << '\n';
}