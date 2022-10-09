// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

// izem vam zadatak
int n, m;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	if (n == 1 && m > 2) {
		cout << "1\n";
		cout << "1 " << m << " 1 1\n";
		for (int j=1; j<=m; j++) cout << "1 " << j << '\n';
		cout << "1 1\n";
	} else if (m == 1 && n > 2) {
		cout << "1\n";
		cout << n << " 1 1 1\n";
		for (int i=1; i<=n; i++) cout << i << " 1\n";
		cout << "1 1\n";
	} else if (n % 2 == 0) {
		cout << "0\n";
		for (int j=1; j<=m; j++) cout << "1 " << j << '\n';
		for (int i=2; i<=n; i++) {
			if (i % 2 == 0) {
				for (int j=m; j>=2; j--) cout << i << ' ' << j << '\n';
			} else {
				for (int j=2; j<=m; j++) cout << i << ' ' << j << '\n';
			}
		}
		for (int i=n; i>=1; i--) cout << i << " 1\n";
	} else if (m % 2 == 0) {
		cout << "0\n";
		for (int i=1; i<=n; i++) cout << i << " 1\n";
		for (int j=2; j<=m; j++) {
			if (j % 2 == 0) {
				for (int i=n; i>=2; i--) cout << i << ' ' << j << '\n';
			} else {
				for (int i=2; i<=n; i++) cout << i << ' ' << j << '\n';
			}
		}
		for (int j=m; j>=1; j--) cout << "1 " << j << '\n';
	} else {
		cout << "1\n";
		cout << n << ' ' << m << ' ' << n << " 1\n";
		for (int j=1; j<=m; j++) cout << "1 " << j << '\n';
		for (int i=2; i<=n; i++) {
			if (i % 2 == 0) {
				for (int j=m; j>=2; j--) cout << i << ' ' << j << '\n';
			} else {
				for (int j=2; j<=m; j++) cout << i << ' ' << j << '\n';
			}
		}
		for (int i=n; i>=1; i--) cout << i << " 1\n";
	}
}