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
	int sol = 0;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		int x = 1123123123;
		for (int j=1; j<=m; j++) {
			int y;
			cin >> y;
			x = min(x, y);
		}
		sol = max(sol, x);
	}
	cout << sol << '\n';
}