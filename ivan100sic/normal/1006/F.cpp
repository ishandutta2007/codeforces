#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[22][22], k;
vector<ll> u[22][22], v[22][22];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> a[i][j];

	int x = (n+m+2) / 2;
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			if (i+j > x)
				continue;
			if (i > 1 && j > 1) {
				u[i][j].resize(u[i-1][j].size() + u[i][j-1].size());
				int z = 0;
				for (ll x : u[i-1][j])
					u[i][j][z++] = x ^ a[i][j];
				for (ll x : u[i][j-1])
					u[i][j][z++] = x ^ a[i][j];
			} else if (i > 1) {
				u[i][j].resize(u[i-1][j].size());
				int z = 0;
				for (ll x : u[i-1][j])
					u[i][j][z++] = x ^ a[i][j];
			} else if (j > 1) {
				u[i][j].resize(u[i][j-1].size());
				int z = 0;
				for (ll x : u[i][j-1])
					u[i][j][z++] = x ^ a[i][j];
			} else {
				u[i][j] = {a[i][j]};
			}
		}

	for (int i=n; i>=1; i--)
		for (int j=m; j>=1; j--) {
			if (i+j < x)
				continue;
			if (i < n && j < m) {
				v[i][j].resize(v[i+1][j].size() + v[i][j+1].size());
				int z = 0;
				for (ll x : v[i+1][j])
					v[i][j][z++] = x ^ a[i][j];
				for (ll x : v[i][j+1])
					v[i][j][z++] = x ^ a[i][j];
			} else if (i < n) {
				v[i][j].resize(v[i+1][j].size());
				int z = 0;
				for (ll x : v[i+1][j])
					v[i][j][z++] = x ^ a[i][j];
			} else if (j < m) {
				v[i][j].resize(v[i][j+1].size());
				int z = 0;
				for (ll x : v[i][j+1])
					v[i][j][z++] = x ^ a[i][j];
			} else {
				v[i][j] = {a[i][j]};
			}
		}

	ll c = 0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			if (i+j == x) {
				sort(v[i][j].begin(), v[i][j].end());
				for (ll x : u[i][j]) {
					auto p = equal_range(v[i][j].begin(), v[i][j].end(), x ^ a[i][j] ^ k);
					c += p.second - p.first;
				}
			}
		}
	cout << c << '\n';
}