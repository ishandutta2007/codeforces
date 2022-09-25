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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 95;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, k;
int a[2 * maxn + 1][2 * maxn + 1];
int vis[2 * maxn + 1][2 * maxn + 1];

void compute() {
	memset(a, 0, sizeof(a));
	memset(vis, 0, sizeof(vis));

	a[maxn][maxn] = n;
	queue<pair<int, int> > q;
	if (a[maxn][maxn] >= 4) q.push(make_pair(maxn, maxn));
	
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		vector<pair<pair<int, int>, int> > v;
		while (!q.empty()) {
			int i = q.front().first, j = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx < maxn) continue;
				if (ny < maxn) continue;
				int d = a[i][j] / 4;
				if (nx == maxn && abs(i - maxn) == 1) d *= 2;
				if (ny == maxn && abs(j - maxn) == 1) d *= 2;
				v.push_back(make_pair(make_pair(nx, ny), d));
			}
			a[i][j] %= 4;
		}
		//sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first.first, y = v[i].first.second, d = v[i].second;
			a[x][y] += d;
			if (vis[x][y] != cnt && a[x][y] >= 4) {
				q.push(make_pair(x, y));
				vis[x][y] = cnt;
			}
			//if ((i == (int)v.size() - 1 || v[i].first != v[i + 1].first) && a[x][y] >= 4) q.push(make_pair(x, y));
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	int t;
	while (cin >> n >> t) {
		compute();
		for (int i = 0; i < t; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x < 0) x = -x;
			if (y < 0) y = -y;
			if (x >= 95 || y >= 95) printf("%d\n", 0);
			else printf("%d\n", a[maxn + x][maxn + y]);
		}
	}

	return 0;
}