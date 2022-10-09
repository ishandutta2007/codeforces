#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;

map<int, vector<pair<int, int>>> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		mp[x].push_back({i, x});
		mp[y].push_back({i, y});
	}

	for (int i=1; i<=n; i++) {
		if (mp[i].size() == 0) {
			mp[i].push_back({50505050 + i, 50505050 + i});
		}
		cout << mp[i].size() << '\n';
		for (auto p : mp[i])
			cout << p.first << ' ' << p.second << '\n';
	}
}