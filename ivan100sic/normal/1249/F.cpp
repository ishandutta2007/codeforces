#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[205];
basic_string<int> e[205];

const int inf = 1023123123;

int dp[222][222];

void mx(int& x, int y) {
	x = max(x, y);
}

void dfs(int x, int p) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);
	}

	vector<int> ol(k+2, -inf);
	ol[k+1] = 0;

	int bez = 0;

	for (int y : e[x]) {
		if (y == p)
			continue;

		vector<int> nu(k+2, -inf);

		for (int i=0; i<=k+1; i++) {
			for (int j=0; j<=k+1; j++) {
				if (i+j+2 <= k)
					continue;
				mx(nu[min(i, j)], ol[i] + dp[y][j]);
			}
		}

		swap(ol, nu);
		bez += max(dp[y][k+1], dp[y][k]);
	}

	copy(ol.begin(), ol.end(), dp[x]+1);
	mx(dp[x][k+1], dp[x][k+2]);

	dp[x][0] = bez + a[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs(1, 1);

	// for (int i=1; i<=n; i++)
	// 	for (int j=0; j<=k+2; j++)
	// 		cerr << dp[i][j] << " \n"[j == k+2];

	cout << *max_element(dp[1], dp[1] + 205) << '\n';
}