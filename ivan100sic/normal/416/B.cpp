#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[50005][11], b[50005][11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> a[i][j];

	for (int j=1; j<=m; j++) {
		for (int i=1; i<=n; i++) {
			b[i][j] = max(b[i][j-1], b[i-1][j]) + a[i][j];
		}
	}
	for (int i=1; i<=n; i++)
		cout << b[i][m] << ' ';
	cout << '\n';
}