#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, q;
int u[200005], v[200005];
int d[1005][1005];
int l[200005], r[200005], s[200005], t[200005];
bool ans[200005];
basic_string<int> e[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=1; i<=m; i++)
		cin >> u[i] >> v[i];
	for (int i=0; i<q; i++) {
		cin >> l[i] >> r[i] >> s[i] >> t[i];
		e[l[i]] += i;
	}

	memset(d, 63, sizeof d);
	for (int i=m; i>=1; i--) {
		int x = u[i], y = v[i];
		for (int j=1; j<=n; j++) {
			d[x][j] = d[y][j] = min(d[x][j], d[y][j]);
			d[x][y] = d[y][x] = i;
		}
		for (int j : e[i])
			ans[j] = d[s[j]][t[j]] <= r[j];
	}
	for (int i=0; i<q; i++)
		cout << (ans[i] ? "Yes\n" : "No\n");
}