#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int e[100005][2];
int deg[9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		e[x][!!e[x][0]] = y;
		e[y][!!e[y][0]] = x;
	}

	if (n <= 6) {
		for (int mask=0; mask<(1 << n*(n-1)/2); mask++) {
			int f = 0, ok = 1;
			memset(deg, 0, sizeof deg);
			for (int i=1; i<=n; i++) {
				for (int j=i+1; j<=n; j++) {
					if (mask & (1 << f)) {
						if (e[i][0] == j || e[i][1] == j)
							ok = 0;
						ok &= ++deg[i] <= 2 && ++deg[j] <= 2;
					}
					f++;
				}
			}
			if (ok && __builtin_popcount(mask) == m) {
				f = 0;
				for (int i=1; i<=n; i++) {
					for (int j=i+1; j<=n; j++) {
						if (mask & (1 << f)) {
							cout << i << ' ' << j << '\n';
						}
						f++;
					}
				}
				return 0;
			}
		}
		cout << "-1\n";
	} else {
		// randoooom
		mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
			+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));
		vector<int> p(n);
		iota(p.begin(), p.end(), 1);

		while (1) {
			random_shuffle(p.begin(), p.end());
			int ok = 1;
			for (int i=0; i<n; i++) {
				int j = i == n-1 ? 0 : i + 1;
				if (e[p[i]][0] == p[j] || e[p[i]][1] == p[j]) {
					ok = 0;
					break;
				}
			}

			if (ok) {
				for (int i=0; i<m; i++)
					cout << p[i] << ' ' << p[(i+1) % n] << '\n';
				return 0;
			}
		}
	}
}