#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[55], f[555];
ld dp[555][55], bk[55][55], F[55];
int sz[555];

void prepare(int x);

void prepare(int x, int p) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		f[x] += y;
		prepare(y, x);
	}
}

void prepare(int x) {
	// cerr << "preparing " << x << '\n';
	fill(f+1, f+n+1, basic_string<int>());
	m = n;
	prepare(x, x);
}

void solve(int x) {
	if (f[x].size() == 0) {
		dp[x][0] = 1.0;
		sz[x] = 0;
	} else if (f[x].size() == 1) {
		int y = f[x][0];
		solve(y);
		sz[x] = sz[y] + 1;
		for (int j=0; j<=sz[x]; j++) {
			dp[x][j] = 0.0;
			for (int k=0; k<sz[x]; k++) {
				dp[x][j] += dp[y][k<j ? j-1 : k] / sz[x] * (k<j ? 1.0 : 0.5);
			}
			// cerr << x << ' ' << j << ' ' << dp[x][j] << '\n';
		}
	} else {
		int u = ++m;
		int v = ++m;
		f[u] = f[x].substr(0, f[x].size()/2);
		f[v] = f[x].substr(f[x].size()/2);

		solve(u);
		solve(v);

		sz[x] = sz[u] + sz[v];

		for (int j=0; j<=sz[x]; j++) {
			dp[x][j] = 0.0;
			for (int k=0; k<=j; k++) {
				int l = j-k;
				if (k > sz[u] || l > sz[v])
					continue;

				ld q = F[sz[u]]*F[sz[v]]*F[sz[x]-j]*F[j] /
					(F[sz[u]-k]*F[sz[v]-l]*F[k]*F[l]*F[sz[x]]);

				// cerr << sz[u] << ' ' << sz[v] << ' ' << k << ' ' << l << '\n';
				// cerr << "--> " << q << '\n';

				dp[x][j] += dp[u][k] * dp[v][l] * q;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	cout << fixed << setprecision(20);

	bk[0][0] = F[0] = 1.0;
	for (int i=0; i<54; i++) {
		F[i+1] = F[i] * (i+1);
		for (int j=0; j<54; j++) {
			bk[i+1][j] += bk[i][j] / 2;
			bk[i][j+1] += bk[i][j] / 2;
		}
	}

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=n; i++) {
		prepare(i);
		solve(i);
		cout << dp[i][0] << '\n';
	}
}