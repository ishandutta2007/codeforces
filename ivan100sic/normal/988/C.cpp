#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a[200005];

map<int, pair<int, int>> mp;
struct pt {
	int x, y, z;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[i].resize(x);
		for (int& y : a[i])
			cin >> y;
	}

	for (int i=1; i<=n; i++) {
		int z = accumulate(a[i].begin(), a[i].end(), 0);

		vector<pt> dodaj;

		for (int j=0; j<(int)a[i].size(); j++) {
			int v = z - a[i][j];
			if (mp.count(v)) {
				cout << "YES\n";
				cout << mp[v].first << ' ' << mp[v].second << '\n';
				cout << i << ' ' << j+1 << '\n';
				return 0;
			} else {
				dodaj.push_back({v, i, j+1});
			}
		}

		for (auto x : dodaj) {
			mp[x.x] = {x.y, x.z};
		}
	}
	cout << "NO\n";


}