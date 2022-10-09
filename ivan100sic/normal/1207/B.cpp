#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[55][55], b[55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> a[i][j];
	vector<pair<int, int>> q;
	for (int i=1; i<n; i++) {
		for (int j=1; j<m; j++) {
			if (a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1] == 4) {
				q.emplace_back(i, j);
				b[i][j] = 1;
				b[i+1][j] = 1;
				b[i][j+1] = 1;
				b[i+1][j+1] = 1;
			}
		}
	}
	int ok = 1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (a[i][j] != b[i][j])
				ok = 0;
	if (ok) {
		cout << q.size() << '\n';
		for (auto [x, y] : q)
			cout << x << ' ' << y << '\n';
	} else {
		cout << "-1\n";
	}
}