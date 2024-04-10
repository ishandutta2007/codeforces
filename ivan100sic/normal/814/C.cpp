#include <bits/stdc++.h>
using namespace std;

int n, q;
string a;

vector<int> e[26];

int ans[26][1505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a;
	a = string(" ") + a;

	for (int i=1; i<=n; i++) {
		e[a[i] - 'a'].push_back(i);
	}

	for (int c=0; c<26; c++) {
		int m = e[c].size();

		for (int i=0; i<m; i++) {
			for (int j=i; j<m; j++) {
				int gap = (e[c][j] - e[c][i]) - (j - i);
				int res = (e[c][j] - e[c][i] + 1);

				ans[c][gap] = max(ans[c][gap], res);
			}
		}

		for (int i=1; i<=n; i++) {
			ans[c][i] = min(n, max(ans[c][i], ans[c][i-1] + 1));
			// ans[c][i] = max(ans[c][i], ans[c][i-1] + 1);
		}
	}

	cin >> q;

	while (q--) {
		int i;
		char x;
		cin >> i >> x;
		cout << ans[x - 'a'][i] << '\n';

	}
}