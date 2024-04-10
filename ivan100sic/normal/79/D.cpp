#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, l;
int b[22];
int c[10005];
int a[105];

int d[10005];
int dist[22][22];

void bfs(int x) {
	memset(d, 7, sizeof d);
	d[x] = 0;
	basic_string<int> q = {x};
	size_t qs = 0;
	while (q.size() != qs) {
		int x = q[qs++];
		for (int i=0; i<l; i++) {
			for (int dir=-1; dir<=1; dir+=2) {
				int y = x + dir*a[i];
				if (y < 0 || y > n)
					continue;
				if (d[y] > 123123) {
					d[y] = d[x] + 1;
					q += y;
				}
			}
		}
	}
}

int dp[1 << 20];

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> l;
	for (int i=0; i<k; i++) {
		int x;
		cin >> x;
		c[x-1] ^= 1;
		c[x] ^= 1;
	}
	int m = 0;
	for (int i=0; i<=n; i++) {
		if (c[i])
			b[m++] = i;
	}
	for (int i=0; i<l; i++)
		cin >> a[i];

	for (int i=0; i<m; i++) {
		bfs(b[i]);
		for (int j=0; j<m; j++)
			dist[i][j] = d[b[j]];
	}

	for (int i=0; i<m; i++)
		for (int j=0; j<m; j++)
			cerr << dist[i][j] << " \n"[j == m-1];

	memset(dp, 31, sizeof dp);
	dp[0] = 0;
	for (int mask=0; mask<(1<<m); mask++) {
		for (int i=0; i<m; i++) {
			if (mask & (1 << i))
				continue;
			for (int j=0; j<m; j++) {
				if (mask & (1 << j))
					continue;
				if (i == j)
					continue;
				mn(dp[mask | (1 << i) | (1 << j)], dp[mask] + dist[i][j]);
			}
		}
	}

	int z = dp[(1<<m)-1];
	if (z > 1123123)
		z = -1;
	cout << z << '\n';
}