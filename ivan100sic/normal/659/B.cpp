#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
vector<pair<int, string>> w[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		string s;
		int x, y;
		cin >> s >> x >> y;
		w[x].emplace_back(y, s);
	}

	for (int i=1; i<=m; i++) {
		sort(w[i].begin(), w[i].end());
		if (w[i].size() > 2 && w[i][w[i].size()-2].first == w[i][w[i].size()-3].first)
			cout << "?\n";
		else
			cout << w[i][w[i].size()-2].second << ' ' << w[i][w[i].size()-1].second << '\n';
	}
}