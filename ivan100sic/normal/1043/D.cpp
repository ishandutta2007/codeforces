#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int y[100005], c[100005];

int n, m;
int a[15][100005];

bool vis[100005];
int d[100005];

void dub(int x) {
	if (vis[x])
		return;
	vis[x] = 1;
	if (c[x] == m) {
		dub(y[x]);
		d[x] = d[y[x]] + 1;
	} else {
		d[x] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++)
			cin >> a[i][j];

		for (int j=1; j<n; j++) {
			int u = a[i][j];
			int v = a[i][j+1];

			if (y[u] == v)
				c[u]++;
			else {
				c[u] = 1;
				y[u] = v;
			}
		}
	}

	for (int i=1; i<=n; i++)
		dub(i);

	cout << accumulate(d+1, d+n+1, 0ll) << '\n';
}