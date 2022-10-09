#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[505][505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int _r=0; _r<2; _r++)
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++) {
				int x;
				cin >> x;
				a[i][j] ^= x;
			}

	int ok = 1;
	for (int i=0; i<n; i++) {
		int x = 0;
		for (int j=0; j<m; j++) {
			x += a[i][j];
		}
		if (x % 2)
			ok = 0;
	}

	for (int j=0; j<m; j++) {
		int x = 0;
		for (int i=0; i<n; i++) {
			x += a[i][j];
		}
		if (x % 2)
			ok = 0;
	}

	cout << (ok ? "Yes\n" : "No\n");
}