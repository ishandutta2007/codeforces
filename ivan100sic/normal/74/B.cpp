#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k, dir, w;
string _d, s;

int winner[205][55];
int gsp[205];

int solve(int i, int j) {
	if (winner[i][j])
		return winner[i][j];
	if (s[i] == '0') {
		if (gsp[i] == j)
			winner[i][j] = i;
		else {
			int z = i;
			z = max(z, solve(i+1, j));
			if (j < n && gsp[i] != j+1)
				z = max(z, solve(i+1, j+1));
			if (j > 1 && gsp[i] != j-1)
				z = max(z, solve(i+1, j-1));
			winner[i][j] = z;
		}
	} else {
		if (gsp[i] == j)
			winner[i][j] = i;
		else {
			if (i == w)
				return 123123123;
			int z = 0;
			for (int b=1; b<=n; b++)
				z = max(z, solve(i+1, b));
			winner[i][j] = z;
		}
	}
	return winner[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> _d >> _d >> s;
	w = s.size();
	s = string(" ") + s;
	if (_d == "head")
		dir = -1;
	else
		dir = 1;
	gsp[1] = k;
	for (int i=2; i<=w; i++) {
		gsp[i] = gsp[i-1] + dir;
		if (gsp[i] == 1 && dir == -1) {
			dir = 1;
		} else if (gsp[i] == n && dir == 1) {
			dir = -1;
		}
		cerr << i << ' ' << gsp[i] << '\n';
	}
	int z = solve(1, m);
	if (z == 123123123) {
		cout << "Stowaway\n";
	} else {
		cout << "Controller " << z-1 << '\n';
	}

	for (int i=1; i<=w; i++) {
		for (int j=1; j<=n; j++) {
			cerr << winner[i][j] << ' ';
		}
		cerr << '\n';
	}
}