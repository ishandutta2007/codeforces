#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>
#include <deque>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace std;

//inline void operator delete (void *) {};

const int MX = 25;

vector < vector < int > > nz;
vector < vector < int > > d;
int n, m, q, p;
vector < pair < int, int > > mv{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int get(int x, int y) {
	d.assign(n, vector < int > (m, -1));
	d[x][y] = 0;
	int ans = 0;
	queue < pair < int, int > > q;
	q.push({ x, y });
	while (!q.empty()) {
		auto c = q.front();
		q.pop();
		auto x = c.first, y = c.second;
		if (d[x][y] > MX)
			continue;
		ans += nz[x][y] / (1 << d[x][y]);
		for (auto j : mv) {
			auto nx = x + j.first, ny = y + j.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || d[nx][ny] != -1 || nz[nx][ny] == -1)
				continue;
			d[nx][ny] = d[x][y] + 1;
			q.push({ nx, ny });
		}
	}
	return ans;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> q >> p;

	nz.resize(n, vector < int > (m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '.')
				nz[i][j] = 0;
			if (isalpha(c))
				nz[i][j] = (c - 'A' + 1) * q;
			if (c == '*')
				nz[i][j] = -1;
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (nz[i][j] == -1)
				continue;
			ans += get(i, j) > p;
		}
	}

	cout << ans;

	return 0;
}