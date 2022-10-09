#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[105][105];
int n, m;

int deg(int x) {
	return count(a[x]+1, a[x]+n+1, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		a[u][v] = 1;
		a[v][u] = 1;
	}

	int z = 0;

	while (1) {
		basic_string<int> r;
		for (int i=1; i<=n; i++) {
			if (deg(i) == 1) {
				r += i;
			}
		}
		for (int i : r) {
			for (int j=1; j<=n; j++) {
				a[i][j] = a[j][i] = 0;
			}
		}
		if (r.size()) {
			z++;
		} else {
			break;
		}
	}
	cout << z << '\n';
}