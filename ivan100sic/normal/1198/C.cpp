#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string mark(3*n+1, 0);
		vector<pair<int, int>> f;
		vector<int> g;
		for (int i=0; i<m; i++) {
			int u, v;
			cin >> u >> v;
			f.emplace_back(u, v);
			if (!mark[u] && !mark[v]) {
				mark[u] = mark[v] = 1;
				g.push_back(i+1);
			}
		}
		if ((int)g.size() >= n) {
			cout << "Matching\n";
			for (int i=0; i<n; i++)
				cout << g[i] << " \n"[i == n-1];
		} else {
			cout << "IndSet\n";
			for (int i=1, k=0; k<n; i++) {
				if (!mark[i]) {
					cout << i << ' ';
					k++;
				}
			}
			cout << '\n';
		}
	}
}