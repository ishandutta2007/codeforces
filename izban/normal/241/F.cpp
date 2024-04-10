#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};


int n, m, tim;
int xs, ys, xe, ye;
string a[maxn], s;
pair<int, int> pos[255], p[maxn][maxn];
int d[27][maxn][maxn];

bool ok(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

int foo(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	return 1;
}

void dijkstra(int k, int x, int y, int time = -1, int xe = 0, int ye = 0) {
	memset(d[k], 127, sizeof(d[k]));
	d[k][x][y] = 0;
	set<pair<int, pair<int, int> > > st;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) st.insert(make_pair(d[k][i][j], make_pair(i, j)));

	while (!st.empty()) {
		x = st.begin()->second.first, y = st.begin()->second.second;
		st.erase(st.begin());
		if (d[k][x][y] > 0 && a[x][y] >= 'a' && a[x][y] <= 'z') continue;
		for (int K = 0; K < 4; K++) {
			int nx = x + dx[K], ny = y + dy[K];
			if (!ok(nx, ny) || a[nx][ny] == '#') continue;
			if (d[k][nx][ny] > d[k][x][y] + foo(a[x][y])) {
				st.erase(make_pair(d[k][nx][ny], make_pair(nx, ny)));
				d[k][nx][ny] = d[k][x][y] + foo(a[x][y]);
				p[nx][ny] = make_pair(x, y);
				st.insert(make_pair(d[k][nx][ny], make_pair(nx, ny)));
			}
		}
	}

	if (time != -1) {
		while (d[k][xe][ye] > time) {
			x = p[xe][ye].first, y = p[xe][ye].second;
			xe = x;
			ye = y;
		}
		cout << xe + 1 << " " << ye + 1 << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m >> tim) {
		for (int i = 0; i < n; i++) cin >> a[i];
		cin >> xs >> ys >> s >> xe >> ye;
		xs--; ys--; xe--; ye--;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] >= 'a' && a[i][j] <= 'z') {
					dijkstra(a[i][j] - 'a' + 1, i, j);
					pos[a[i][j]] = make_pair(i, j);
				}
			}
		}
		dijkstra(0, xs, ys);

		bool answered = 0;
		int x = xs, y = ys;
		for (int i = 0; i <= s.length(); i++) {
			int nk = i ? s[i - 1] - 'a' + 1 : 0;
			int nx = i == s.length() ? xe : pos[s[i]].first;
			int ny = i == s.length() ? ye : pos[s[i]].second;

			if (d[nk][nx][ny] >= tim) {
				dijkstra(nk, x, y, tim, nx, ny);
				answered = 1;
				break;
			} else {
				tim -= d[nk][nx][ny];
				x = nx;
				y = ny;
			}
		}
		if (!answered) cout << x + 1 << " " << y + 1 << endl;
	}

	return 0;
}