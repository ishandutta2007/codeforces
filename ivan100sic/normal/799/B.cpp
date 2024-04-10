#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> majice[4];
int p[200005], a[200005], b[200005];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> p[i];
	}

	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}

	for (int i=1; i<=n; i++) {
		majice[a[i]].insert({p[i], i});
		majice[b[i]].insert({p[i], i});
	}

	cin >> m;
	for (int i=1; i<=m; i++) {
		int c;
		cin >> c;
		if (majice[c].empty()) {
			cout << "-1 ";
			continue;
		}
		auto par = *majice[c].begin();
		int id = par.second;
		int cena = par.first;

		cout << cena << ' ';
		majice[a[id]].erase({p[id], id});
		majice[b[id]].erase({p[id], id});
	}
}