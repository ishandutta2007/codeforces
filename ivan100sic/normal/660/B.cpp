// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[105][4];
int n, m;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	int j = 1;
	for (int i=0; i<n && j<=m; i++) {
		if (j <= m) a[i][0] = j++;
		if (j <= m) a[i][3] = j++;
	}

	for (int i=0; i<n && j<=m; i++) {
		if (j <= m) a[i][1] = j++;
		if (j <= m) a[i][2] = j++;
	}

	for (int i=0; i<n; i++) {
		if (a[i][1]) cout << a[i][1] << ' ';
		if (a[i][0]) cout << a[i][0] << ' ';
		if (a[i][2]) cout << a[i][2] << ' ';
		if (a[i][3]) cout << a[i][3] << ' ';
	}
	cout << '\n';
}