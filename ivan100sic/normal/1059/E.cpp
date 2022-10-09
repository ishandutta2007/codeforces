#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, l;
ll s;
int p[18][100005];
vector<int> e[100005];
int w[100005];

ll root_tez[100005];
int root_duz[100005];

ll duz[100005], tez[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l >> s;
	for (int i=1; i<=n; i++)
		cin >> w[i];

	for (int i=1; i<=n; i++)
		if (w[i] > s)
			return cout << -1, 0;

	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		p[0][i] = x;
		e[x].push_back(i);
	}

	p[0][1] = 0;
	for (int i=1; i<18; i++) {
		for (int x=1; x<=n; x++) {
			p[i][x] = p[i-1][p[i-1][x]];
		}
	}
	
	root_tez[1] = w[1];
	
	for (int i=2; i<=n; i++) {
		root_tez[i] = root_tez[p[0][i]] + w[i];
		root_duz[i] = root_duz[p[0][i]] + 1;
	}

	int sol = 0;

	for (int i=n; i>=1; i--) {
		// uzmi naj dete
		int y = -1, h = -1;
		for (int x : e[i]) {
			if (duz[x] == l || tez[x] + w[i] > s) {
				continue;
			}
			
			int xx = x;

			for (int j=17; j>=0; j--) {
				int xxx = p[j][xx];
				if (tez[x] + root_tez[i] - root_tez[p[0][xxx]] <= s) {
					if (duz[x] + root_duz[i] - root_duz[p[0][xxx]] <= l) {
						xx = xxx;
					}
				}
			}

			if (y == -1 || xx < y) {
				y = xx;
				h = x;
			}
		}

		if (h == -1) {
			tez[i] = w[i];
			duz[i] = 1;
			sol += (int)e[i].size();
		} else {
			tez[i] = tez[h] + w[i];
			duz[i] = duz[h] + 1;
			sol += (int)e[i].size() - 1;
		}
	}

	sol += 1; // kec

	/*
	for (int i=1; i<=n; i++) {
		cerr << i << ' ' << tez[i] << ' ' << duz[i] << '\n';
	}
	*/

	cout << sol << '\n';
}