#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <cstring>
using namespace std;

int n, matmin = 2e9;
int a[2005][2005];
bool blocked[2005];
bool prime[2005];

void read_input() {
	cin >> n;
	for (int i=1; i<n; i++) {
		for (int j=i+1; j<=n; j++) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
			matmin = min(matmin, a[i][j]);
		}
	}
}

void debug_matrix() {
	cerr << "matrix\n";
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cerr << a[i][j] << ' ';
			if (a[i][j] == matmin) {
				prime[i] = true;
				prime[j] = true;
			}
		}
		cerr << '\n';
	}
}

void solve_bad() {
	for (int i=1; i<=n; i++) {

		bool found = false;
		long long sol = 0;

		if (prime[i]) {
			sol = (n-1) * 1ll * matmin;
			found = true;
		}

		if (!found) {
			int susv = 2e9;
			for (int j=1; j<=n; j++) {
				if (i != j) {
					susv = min(susv, a[i][j]);
				}
			}

			for (int j=1; j<=n; j++) {
				if (i != j) {
					if (a[i][j] == susv && prime[j]) {
						found = true;
						sol = (n-2) * 1ll * matmin + susv;
						break;
					}
				}
			}

			if (!found) {
				sol = (n-3) * 1ll * matmin + 2ll * susv;
			}
		}

		cout << sol << '\n';
	}
}

int dist[2005];
bool done[2005];

void solve_good() {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i != j) {
				a[i][j] -= matmin;
			}
		}
	}

	for (int i=1; i<=n; i++) {
		dist[i] = 2e9;
		for (int j=1; j<=n; j++) {
			if (i != j) {
				dist[i] = min(dist[i], a[i][j] * 2);
			}
		}
	}

	// dijkstra
	while (1) {
		int x = 0;
		for (int i=1; i<=n; i++) {
			if (!done[i] && (x == 0 || dist[i] < dist[x])) {
				x = i;
			}
		}
		if (x == 0) {
			break;
		}

		done[x] = true;

		for (int j=1; j<=n; j++) {
			if (j != x) {
				if (dist[x] + a[x][j] < dist[j]) {
					dist[j] = dist[x] + a[x][j];
				}
			}
		}

	}

	for (int i=1; i<=n; i++) {
		cout << dist[i] + matmin * 1ll * (n-1) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	read_input();
	
	// debug_matrix();

	solve_good();
}