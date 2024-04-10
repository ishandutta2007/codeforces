#include <bits/stdc++.h>
using namespace std;

const size_t MAXLEN = 12;

string a[205];
set<pair<int, int>> ima[205];
int n, m;

void nadji(set<pair<int, int>>& ima, const string& s) {
	for (size_t i = 0; i < s.size(); i++) {
		int mask = 0;
		for (size_t j = 1; j <= MAXLEN; j++) {
			if (i + j - 1 >= s.size()) {
				break;
			}

			mask = 2 * mask + s[i+j-1] - '0';
			ima.insert({j, mask});
		}
	}
}

void nadji(int id) {
	nadji(ima[id], a[id]);
}

void spoji(int id, int x, int y) {
	a[id] = a[x] + a[y];
	if (a[id].size() > 2*MAXLEN) {
		a[id] = a[id].substr(0, MAXLEN) + a[id].substr(a[id].size() - MAXLEN, MAXLEN);
	}
	ima[id] = ima[x];
	for (auto p : ima[y]) {
		ima[id].insert(p);
	}

	string between = a[x].size() > MAXLEN ? a[x].substr(a[x].size() - MAXLEN, MAXLEN) : a[x];
	between += a[y].size() > MAXLEN ? a[y].substr(0, MAXLEN) : a[y];

	nadji(ima[id], between);
}

int broj(int id) {
	for (int k=MAXLEN; k>0; k--) {
		bool ok = true;
		for (int mask=0; mask<(1<<k); mask++) {
			if (!ima[id].count({k, mask})) {
				ok = false;
				break;
			}
		}
		if (ok) {
			return k;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		nadji(i);
	}

	cin >> m;
	for (int i=n+1; i<=n+m; i++) {
		int x, y;
		cin >> x >> y;
		spoji(i, x, y);
		cout << broj(i) << '\n';
	}


}