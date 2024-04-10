#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[205][205];
bool ok_red[205], cached[205];

bool proveri() {
	bool ok = true;
	for (int i=1; i<n; i++) {
		if (!cached[i]) {
			int x[2] = {0, 0};
			for (int j=0; j<m; j++) {
				x[a[i][j] ^ a[0][j]]++;
			}
			ok_red[i] = !(x[0] && x[1]); 
			cached[i] = true;
		}
		ok &= ok_red[i];
	}
	return ok;
}

void promeni(int x, int y) {
	a[x][y] ^= 1;
	if (x == 0) {
		for (int i=1; i<n; i++)
			cached[i] = false;
	} else {
		cached[x] = false;
	}
}

void probaj() {
	if (proveri()) {
		cout << "YES\n";
		string r = "0", c;
		for (int j=0; j<m; j++) {
			c += a[0][j] + 48;
		}
		for (int i=1; i<n; i++) {
			r += 48 + (a[i][0] != a[0][0]);
		}
		cout << r << '\n' << c << '\n';
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}

	// proveri init
	for (int i=n-1; i>=0; i--) {
		for (int j=m-1; j>=0; j--) {
			promeni(i, j);
			probaj();
		}
	}

	cout << "NO\n";
}