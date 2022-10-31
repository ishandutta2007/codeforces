// Hydro submission #62c7c5f0c3a9fda5622c4682@1657259505246
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 1;
int r[MAX], c[MAX], cnt[MAX], ans[9], n, m;
unordered_map<int, vector<int>> row, col, ld, rd;

void f(unordered_map<int, vector<int>> const& m, int comp[]) {
	for (auto const& pair : m) {
		if (pair.second.size() < 2) continue;
		int mn = INT_MAX, mx = INT_MIN;
		for (int i : pair.second) mn = min(mn, comp[i]), mx = max(mx, comp[i]);
		for (int i : pair.second) cnt[i] += comp[i] == mn || comp[i] == mx ? 1 : 2;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> r[i] >> c[i];
	for (int i = 0; i < m; ++i) {
		row[r[i]].push_back(i);
		col[c[i]].push_back(i);
		ld[r[i] + c[i]].push_back(i);
		rd[r[i] - c[i]].push_back(i);
	}
	f(row, c);
	f(col, r);
	f(ld, r);
	f(rd, r);
	for (int i = 0; i < m; ++i)
		++ans[cnt[i]];
	for (int i = 0; i < 9; ++i)
		cout << ans[i] << ' ';
}