#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int c[512], cu[512];
basic_string<pair<int, int>> pice[512];

int readmask() {
	int t;
	cin >> t;
	int z = 0;
	while (t--) {
		int x;
		cin >> x;
		z |= 1 << (x-1);
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		c[readmask()]++;
	for (int i=0; i<512; i++) {
		for (int j=0; j<512; j++) {
			if ((i & j) == j) {
				cu[i] += c[j];
			}
		}
	}
	for (int i=0; i<m; i++) {
		int c;
		cin >> c;
		pice[readmask()] += {c, i+1};
	}
	for (int i=0; i<512; i++)
		sort(pice[i].begin(), pice[i].end());
	int sol_ljudi = -1;
	int sol_cena = 2012012012;
	int ii = -1, jj = -1;
	for (int i=0; i<512; i++)
		for (int j=i; j<512; j++) {
			int pr = 0;
			int i1 = -1, j1 = -1;
			if (i == j) {
				if (pice[i].size() < 2)
					continue;
				pr = pice[i][0].first + pice[i][1].first;
				i1 = pice[i][0].second;
				j1 = pice[i][1].second;
			} else {
				if (pice[i].size() < 1)
					continue;
				if (pice[j].size() < 1)
					continue;
				pr = pice[i][0].first + pice[j][0].first;
				i1 = pice[i][0].second;
				j1 = pice[j][0].second;
			}

			int ljudi = cu[i | j];
			if (ljudi > sol_ljudi || (ljudi == sol_ljudi && pr < sol_cena)) {
				sol_ljudi = ljudi;
				sol_cena = pr;
				ii = i1;
				jj = j1;
			}
		}
	// cerr << "sol_ljudi " << sol_ljudi << '\n';
	// cerr << "sol_cena " << sol_cena << '\n';
	cout << ii << ' ' << jj << '\n';
}