#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, m, t;
ull bk[55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	bk[0][0] = 1;
	for (int i=1; i<55; i++)
		bk[0][i] = bk[i][0] = 1;
	for (int i=1; i<55; i++)
		for (int j=1; j<55; j++)
			bk[i][j] = bk[i-1][j] + bk[i][j-1];

	cin >> n >> m >> t;

	ull sol = 0;

	for (ll x=4; x<t; x++) {
		ll y = t-x;
		if (y > m || y < 1 || x < 4 || x > n)
			continue;
		sol += bk[x][n-x] * bk[y][m-y];
	}

	cout << sol << '\n';
}