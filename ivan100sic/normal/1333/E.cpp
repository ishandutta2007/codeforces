// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[505][505];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	if (n <= 2) {
		cout << "-1\n";
		return 0;
	}

	a[0][0] = 1, a[0][1] = 7, a[0][2] = 4;
	a[1][0] = 2, a[1][1] = 5, a[1][2] = 3;
	a[2][0] = 8, a[2][1] = 6, a[2][2] = 9;

	int w = 0;
	// idi u spiralu ka unutra
	for (int k=n-1; k>=3; k--) {
		if (k % 2) {
			for (int j=0; j<=k; j++)
				a[j][k] = ++w;
			for (int j=k-1; j>=0; j--)
				a[k][j] = ++w;
		} else {
			for (int j=0; j<=k; j++)
				a[k][j] = ++w;
			for (int j=k-1; j>=0; j--)
				a[j][k] = ++w;
		}
	}

	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			a[i][j] += n*n-9;

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cout << a[i][j] << " \n"[j == n-1];
}