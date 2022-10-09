#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[5][55];

struct tp {
	int x, y, z;
};

vector<tp> sol;

void db() {
	for (int i=1; i<=n; i++)
		cerr << a[2][i] << ' ';
	cerr << '\n';
	for (int i=1; i<=n; i++)
		cerr << a[3][i] << ' ';
	cerr << '\n';
	cerr << '\n';
}

bool ostalo() {
	for (int i=1; i<=n; i++)
		if (a[2][i])
			return 1;
		else if (a[3][i])
			return 1;
	return 0;
}

void polomi() {
	if (ostalo())
		exit(1);
}

void pomeri(int x, int y, int tx, int ty) {
	if (!a[x][y])
		return;
	sol.push_back({a[x][y], tx, ty});
	if (tx == 1 || tx == 4) {
		a[x][y] = 0;
	} else {
		a[tx][ty] = a[x][y];
		a[x][y] = 0;
	}
}

void carousel() {
	int c = 0, f = 0;
	for (int i=0; i<8*n; i++) {
		int x = i/n % 2 + 2;
		int y = i%n;
		if (x == 2) {
			y = y+1;
		} else {
			y = n-y;
		}

		int tx, ty;
		if (x == 2) {
			if (y == n) {
				tx = 3;
				ty = n;
			} else {
				tx = 2;
				ty = y+1;
			}
		} else {
			if (y == 1) {
				tx = 2;
				ty = 1;
			} else {
				tx = 3;
				ty = y-1;
			}
		}

		if (a[tx][ty] && a[x][y] == 0) {
			pomeri(tx, ty, x, y);
			f = 1;
		}

		c += f;
		
		if (c == 2*n-1)
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=4; i++) {
		for (int j=1; j<=n; j++) {
			cin >> a[i][j];
		}
	}

	// nema resenja?
	if (k == 2*n) {
		int c = 0;
		for (int i=1; i<=n; i++) {
			if (a[1][i] != a[2][i])
				c++;
			if (a[3][i] != a[4][i])
				c++;
		}
		if (c == k) {
			cout << "-1\n";
			return 0;
		}
	}

	// makni dobre
	for (int i=1; i<=n; i++) {
		if (a[1][i] == a[2][i] && a[2][i])
			pomeri(2, i, 1, i);
		if (a[3][i] == a[4][i] && a[3][i])
			pomeri(3, i, 4, i);
	}

	// resi

	// db();

	for (int r=0; r<8*n; r++) {
		carousel();

		for (int i=1; i<=n; i++) {
			if (a[1][i] == a[2][i] && a[2][i])
				pomeri(2, i, 1, i);
			if (a[3][i] == a[4][i] && a[3][i])
				pomeri(3, i, 4, i);
		}

		// db();
	}

	// db();
	// polomi();

	cout << sol.size() << '\n';
	for (auto p : sol)
		cout << p.x << ' ' << p.y << ' ' << p.z << '\n';
}