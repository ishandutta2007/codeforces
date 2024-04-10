#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1005], b[1005];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int j=1; j<=m; j++)
		cin >> b[j];

	int y = 1;
	int c = 0;
	for (int i=1; i<=n; i++) {
		if (y <= m && a[i] <= b[y]) {
			c++;
			y++;
		}
	}

	cout << c << '\n';
}