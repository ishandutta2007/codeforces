#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[505][505];
int b[505][505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> b[i][j];
		}
	}
	for (int d=2; d<=n+m; d++) {
		basic_string<int> u, v;
		for (int i=1; i<=n; i++) {
			int j = d-i;
			if (1 <= j && j <= m) {
				u += a[i][j];
				v += b[i][j];
			}
		}
		sort(u.begin(), u.end());
		sort(v.begin(), v.end());
		if (u != v) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}