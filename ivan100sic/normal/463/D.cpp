#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[1005][1005];
int n, k;
int q[1005], g[1005], l, r;
int a[1005], d[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int j=1; j<=k; j++) {
		for (int i=1; i<=n; i++)
			cin >> a[i];
		for (int i=1; i<=n; i++)
			for (int j=i+1; j<=n; j++)
				c[a[i]][a[j]]++;
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if ((c[i][j] = c[i][j] == k)) {
				g[j]++;
			}
		}
	}

	for (int i=1; i<=n; i++)
		if (g[i] == 0)
			q[r++] = i;
	int sol = 0;
	while (l < r) {
		int x = q[l++];
		sol = max(sol, d[x] + 1);
		for (int i=1; i<=n; i++)
			if (c[x][i]) {
				if (!--g[i])
					q[r++] = i;
				d[i] = max(d[i], d[x] + 1);				
			}
	}
	cout << sol << '\n';
}