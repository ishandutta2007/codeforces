#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int p[3005], c[3005];

vector<int> votes[3005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> p[i] >> c[i];
	}

	for (int i=1; i<=n; i++) {
		votes[p[i]].push_back(c[i]);
	}

	for (int i=1; i<=m; i++) {
		sort(votes[i].begin(), votes[i].end());
	}

	ll sol = 123123123123123123ll;

	// broj glasova koje imaju svi drugi
	for (int g=0; g<n; g++) {
		int kecc = votes[1].size();
		ll cost = 0;
		// svima spustis na ispod toga
		vector<int> resto;
		for (int j=2; j<=m; j++) {
			if ((int)votes[j].size() > g) {
				kecc += votes[j].size() - g;
				cost += accumulate(votes[j].begin(), votes[j].begin() + 
					(votes[j].size() - g), 0ll);
				copy(votes[j].begin() + 
					(votes[j].size() - g), votes[j].end(), back_inserter(resto));
			} else {
				copy(votes[j].begin(), votes[j].end(), back_inserter(resto));
			}
		}

		// cerr << g << ' ' << resto.size() << '\n';

		sort(resto.begin(), resto.end());
		int z = 0;
		while (kecc <= g) {
			cost += resto[z++];
			kecc++;
		}

		if (kecc > g) {
			sol = min(sol, cost);
		}
	}

	cout << sol;

}