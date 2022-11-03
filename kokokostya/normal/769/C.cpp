#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <algorithm>
#include <stack>
#include <complex>

using namespace std;

vector < vector < int > > d, us;
//vector < vector < char > > a;
int n, m;
string s = "DLRU";
vector < pair < int, int > > mv{ { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 0 } };

void bfs(int x, int y) {
	d[x][y] = 0;
	us[x][y] = 1;
	queue < pair < int, int > > q;
	q.push({ x, y });
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = v.first + mv[i].first, ny = v.second + mv[i].second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!us[nx][ny]) {
					d[nx][ny] = d[v.first][v.second] + 1;
					us[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	return;
}

int main() {
	//freopen("integral.in", "r", stdin);
	//freopen("integral.out", "w", stdout);
	iostream::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;

	d.resize(n, vector < int >(m, 1e8));
	us.resize(n, vector  < int >(m, 0));

	int k;
	cin >> k;
	if (k % 2) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'X') {
				x = i;
				y = j;
			}
			if (c == '*')
				us[i][j] = 1;
		}
	}

	bfs(x, y);

	for (int i = 0; i < k; i++) {
		bool flag = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + mv[j].first, ny = y + mv[j].second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (d[nx][ny] < k - i) {
					flag = 1;
					cout << s[j];
					x = nx, y = ny;
					break;
				}
			}
		}
		if (!flag) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	return 0;
}