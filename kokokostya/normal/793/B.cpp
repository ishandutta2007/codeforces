#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>

using namespace std;

vector< pair<int, int> > o = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

vector< vector< vector<bool> > > used;
vector< vector<char> > a;
int n, m;

void dfs(int x, int y, int j) {
	used[x][y][j] = 1;
		int tox = x + o[j].first;
		int toy = y + o[j].second;
		if (tox < n && toy < m && tox >= 0 && toy >= 0 && !used[tox][toy][j] && a[tox][toy] != '*')
			dfs(tox, toy, j);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	pair<int, int> st, fin;
	a.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S')
				st = { i, j };
			if (a[i][j] == 'T')
				fin = { i, j };
		}
	}
	vector< pair<int, int> > is;
	is.push_back(st);
	for (int doit = 0; doit < 3; doit++) {
		used.assign(n, vector<vector<bool> >(m, vector<bool>(4)));
		for (int i = 0; i < is.size(); i++) {
			for (int j = 0; j < 4; j++) {
				if (!used[is[i].first][is[i].second][j])
					dfs(is[i].first, is[i].second, j);
			}
		}
		is.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int q = 0; q < 4; q++) {
					if (used[i][j][q]) {
						is.push_back({ i, j });
						q = 4;
					}
				}
			}
		}
	}
	for (int i = 0; i < is.size(); i++) {
		if (is[i] == fin) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}