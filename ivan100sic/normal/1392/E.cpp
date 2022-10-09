// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
ll a[26][26];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i+j > 2) {
				a[i][j] = (i%2) * (1ll << (i+j-3));
			}
		}
	}
	a[n][n] = 0;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cout << a[i][j] << " \n"[j == n];
		}
	}
	cout << flush;

	int q;
	cin >> q;
	while (q--) {
		ll x;
		cin >> x;
		int i = 1, j = 1;
		cout << i << ' ' << j << '\n';
		while (i + j < 2*n) {
			bool ip;
			if (i == n) {
				ip = false;
			} else if (j == n) {
				ip = true;
			} else {
				ll y = a[i+1][j] ^ a[i][j+1];
				if (y & x) {
					ip = true;
				} else {
					ip = false;
				}
				ip ^= a[i+1][j] == 0;
			}

			(ip ? i : j)++;
			cout << i << ' ' << j << '\n';
		}
		cout << flush;
	}
}