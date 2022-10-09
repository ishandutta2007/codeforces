#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1005];
bool rm[1005];
vector<int> e[1005];
pair<int, int> b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i=1; i<=n; i++) {
		b[i-1] = {-a[i], i};
	}
	sort(b, b+n);
	long long sol = 0;

	for (int i=0; i<n; i++) {
		int x = b[i].second;
		// rm x
		for (int y : e[x]) {
			if (!rm[y]) {
				sol += a[y];
			}
		}

		rm[x] = true;
	}

	cout << sol << '\n';
}