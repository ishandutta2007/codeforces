#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;

	int c = 0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int d = min({i-1, n-i, j-1, m-j});
			if (d % 2 == 0 && d < 2*k)
				c++;
		}
	}
	cout << c << '\n';
}