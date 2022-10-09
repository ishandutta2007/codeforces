// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int w[18][18];
bool v[18];
int c[18];
int a[18];
basic_string<int> topo;

void dfs(int x) {
	v[x] = 1;
	for (int i=0; i<n; i++) {
		if (!v[i] && w[x][i] != -1) {
			dfs(i);
		}
	}
	topo += x;
}

void delta(int mask, int d) {
	for (int i=0; i<n; i++) {
		if (mask & (1 << i)) {
			a[i] += d;
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	memset(w, 255, sizeof w);

	{
		int m;
		cin >> m;
		while (m--) {
			int x, y, z;
			cin >> x >> y >> z;
			x--, y--;
			w[x][y] = z;
			c[x] += z;
			c[y] -= z;
		}
	}

	for (int i=0; i<n; i++) {
		if (!v[i]) {
			dfs(i);
		}
	}

	for (int i=0; i<n; i++) {
		a[topo[i]] = i;
	}

	while (1) {
		bool f = 0;
		for (int mask=1; mask<(1<<n)-1; mask++) {
			int above = 123123123, below = 123123123;
			int coef = 0;

			for (int i=0; i<n; i++) {
				if (mask & (1 << i)) {

					coef += c[i];

					for (int j=0; j<n; j++) {
						if (!(mask & (1 << j))) {

							if (w[j][i] != -1) {
								above = min(above, a[j] - a[i] - 1);
							}

							if (w[i][j] != -1) {
								below = min(below, a[i] - a[j] - 1);
							}

						}
					}

				}
			}


			if (coef < 0) {
				if (above > 0) {
					delta(mask, above);
					f = 1;
				}
			} else if (coef > 0) {
				if (below > 0) {
					delta(mask, -below);
					f = 1;
				}
			}
		}

		if (!f) break;
	}

	for (int i=0; i<n; i++) {
		cout << a[i] + 100000 << " \n"[i == n-1];
	}

}