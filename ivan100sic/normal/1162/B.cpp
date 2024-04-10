#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[55][55], b[55][55];

void no() {
	cout << "Impossible\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i][j] > b[i][j])
				swap(a[i][j], b[i][j]);
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i][j-1] >= a[i][j])
				no();
			if (a[i-1][j] >= a[i][j])
				no();

			if (b[i][j-1] >= b[i][j])
				no();
			if (b[i-1][j] >= b[i][j])
				no();
		}
	}
	
	cout << "Possible\n";
}