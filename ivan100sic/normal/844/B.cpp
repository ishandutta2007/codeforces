#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
ll sol;
int a[55][55];
int r[55], c[55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int x;
			cin >> x;
			a[i][j] = x;
			r[i] += x;
			c[j] += x;
		}
	}

	for (int i=0; i<n; i++)
		sol += (1ll << r[i]) + (1ll << (m - r[i]));
	for (int j=0; j<m; j++)
		sol += (1ll << c[j]) + (1ll << (n - c[j]));
	// cerr << "pre: " << sol << '\n';
	sol -= 2*(n+m) + n*m;
	cout << sol << '\n';
}