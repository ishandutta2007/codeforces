#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> p[i];
	}

	for (int i=1; i<=m; i++) {
		int l, r, x, c = 0;
		cin >> l >> r >> x;
		for (int j=l; j<=r; j++) {
			if (p[j] < p[x]) {
				c++;
			}
		}
		if (l + c == x) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

}