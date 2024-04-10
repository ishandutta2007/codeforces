#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[3005], f[3005];
int p[3005][3005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		f[v] += u;
	}

	for (int x=1; x<=n; x++) {
		for (int b : f[x])
			for (int a : e[x])
				p[b][a]++;
	}

	ll sol = 0;

	for (int x=1; x<=n; x++)
		for (int y=1; y<=n; y++) {
			if (x != y) {
				sol += p[x][y] * (p[x][y] - 1ll);
			}
		}

	cout << (sol >> 1) << '\n';
}