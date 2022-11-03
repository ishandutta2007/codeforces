#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <unordered_map>

using namespace std;

vector< vector< pair<int, int> > > g;
vector<bool> used;
vector<int> col;

bool dfs(int v, int c) {
	used[v] = 1;
	col[v] = c;
	bool is = 1;
	for (pair<int, int> i : g[v]) {
		if (!used[i.second]) {
			if (i.first)
				is &= dfs(i.second, c ^ 1);
			else
				is &= dfs(i.second, c);
		}
		else {
			if (i.first) {
				if (col[i.second] != c ^ 1)
					return 0;
			}
			else {
				if (col[i.second] != c)
					return 0;
			}
		}
	}

	return is;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	used.resize(m);
	vector<int> r(n);
	col.resize(m, -1);
	for (int i = 0; i < n; i++)
		cin >> r[i];
	vector< vector<int> > arr(m);
	vector< vector<int> > numb(n);
	for (int i = 0; i < m; i++) {
		int sz;
		cin >> sz;
		arr[i].resize(sz);
		for (int j = 0; j < sz; j++) {
			cin >> arr[i][j];
			arr[i][j]--;
		}
		for (int j = 0; j < sz; j++) {
			numb[arr[i][j]].push_back(i);
		}
	}
	g.resize(m);
	for (int i = 0; i < n; i++) {
		if (!r[i]) {
			g[numb[i][0]].push_back({1, numb[i][1]});
			g[numb[i][1]].push_back({1, numb[i][0]});
		}
		else {
			g[numb[i][0]].push_back({ 0, numb[i][1] });
			g[numb[i][1]].push_back({ 0, numb[i][0] });
		}
	}
	for (int i = 0; i < m; i++) {
		if (!used[i])
			if (!dfs(i, 1)) {
				cout << "NO";
				return 0;
			}
	}
	cout << "YES";
	return 0;
}