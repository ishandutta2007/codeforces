#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
ll a[300005], z[300005][10];
ll d[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int r=0; r<m; r++)
		for (int i=1; i<=n; i++)
			z[i][r] = z[i-1][r] + a[i] - (i%m == r ? k : 0);
	ll sol = 0;
	memset(d, 63, sizeof(d));
	for (int i=1; i<=n; i++) {
		for (int r=0; r<m; r++)
			d[r] = min(d[r], z[i-1][r]);
		sol = max(sol, z[i][i%m] - d[i%m]);
	}
	cout << sol << '\n';
}