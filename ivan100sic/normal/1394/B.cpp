// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k;
vector<pair<int, int>> e[200005];
vector<pair<int, int>> f[200005];

bool fp[10][9][10][9];
bool fs[10][9];
bool sp[10][9];
int c[10];
int sol;

int ok() {
	for (int i=1; i<=k; i++) {
		if (fs[i][c[i]]) {
			return 0;
		}

		for (int j=1; j<i; j++) {
			if (fp[i][c[i]][j][c[j]]) {
				return 0;
			}
		}
	}

	return 1;
}

void rek(int l) {
	if (l == k+1) {
		sol += ok();
		return;
	}

	for (int i=0; i<l; i++) {
		c[l] = i;
		rek(l+1);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		e[x].emplace_back(y, w);
	}

	for (int x=0; x<n; x++) {
		sort(begin(e[x]), end(e[x]), [](auto p, auto q) { return q.second < p.second; });
		int l = e[x].size();
		if (l == 0) {
			cout << "0\n";
			return 0;
		}
		for (int i=0; i<l; i++) {
			f[e[x][i].first].emplace_back(i, l);
		}
	}

	for (int x=0; x<n; x++) {
		memset(sp, 0, sizeof sp);
		for (auto [i, l] : f[x]) {
			// cerr << x << " -> " << i << '/' << l << "\n";

			if (sp[l][i]) {
				fs[l][i] = 1;
			} else {
				for (int j=1; j<=k; j++) {
					for (int z=0; z<j; z++) {
						if (sp[j][z]) {
							fp[j][z][l][i] = 1;
							fp[l][i][j][z] = 1;
						}
					}
				}
				sp[l][i] = 1;
			}
		}
	}

	rek(1);

	cout << sol << '\n';
}