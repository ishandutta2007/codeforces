#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, h;
int a[105][105], c[105], r[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> h;
	for (int i=1; i<=m; i++)
		cin >> c[i];
	for (int i=1; i<=n; i++)
		cin >> r[i];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> a[i][j];

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cout << a[i][j] * min(r[i], c[j]) << " \n"[j == m];
}