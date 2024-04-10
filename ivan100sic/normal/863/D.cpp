#include <bits/stdc++.h>
using namespace std;

struct upit {
	int t, l, r;
};

int n, q, m;
int b[105];
upit u[200005];
int a[200005];

void perform(upit u) {
	for (int i=1; i<=m; i++) {
		int& x = b[i];
		if (u.l <= x && x <= u.r) {
			if (u.t == 2) {
				x = u.r + u.l - x;
			} else {
				if (x == u.l) {
					x = u.r;
				} else {
					x--;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=q; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		u[i] = {t, l, r};
	}

	for (int i=1; i<=m; i++) {
		cin >> b[i];
	}

	for (int i=q; i>=1; i--) {
		perform(u[i]);
	}

	for (int i=1; i<=m; i++) {
		cout << a[b[i]] << ' ';
	}
}