#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

vector<int> sz;
int cnt;
int csum;
vector<int> ccnt;
int cells;

void add(int cc, int d) {
	if (ccnt[cc] == 0 && d == 1) {
		csum += sz[cc];
	}
	ccnt[cc] += d;
	if (ccnt[cc] == 0 && d == -1) {
		csum -= sz[cc];
	}
}

int fastsolve(vector<string> a, int n, int k) {
	vector<vector<char> > used(n, vector<char>(n));
	cnt = 0;
	sz.clear();
	vector<vector<vector<int> > > b(n, vector<vector<int> >(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (used[i][j] || a[i][j] == 'X') continue;
			queue<pair<int, int> > q;
			q.push(make_pair(i, j));
			used[i][j] = 1;
			sz.push_back(0);
			cnt++;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				sz[cnt - 1]++;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (used[nx][ny]) continue;
					if (a[nx][ny] == 'X') {
						b[nx][ny].push_back(cnt - 1);
					}
					else {
						used[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sort(b[i][j].begin(), b[i][j].end());
			b[i][j].resize(unique(b[i][j].begin(), b[i][j].end()) - b[i][j].begin());
		}
	}

	bool e = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			e &= a[i][j] == '.';
		}
	}
	if (e) return n * n;

	int ans = 0;
	for (int x = 0; x + k <= n; x++) {
		csum = 0;
		ccnt.assign(cnt, 0);
		cells = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				for (int l = 0; l < (int)b[x + i][j].size(); l++) {
					add(b[x + i][j][l], 1);
				}
				cells += a[x + i][j] == 'X';
			}
		}

		for (int j = 0; j + k <= n; j++) {
			ans = max(ans, cells + csum);
			for (int i = 0; i < k; i++) {
				for (int l = 0; l < (int)b[x + i][j].size(); l++) {
					add(b[x + i][j][l], -1);
				}
				cells -= a[x + i][j] == 'X';
				if (j + k == n) continue;
				for (int l = 0; l < (int)b[x + i][j + k].size(); l++) {
					add(b[x + i][j + k][l], 1);
				}
				cells += a[x + i][j + k] == 'X';
			}
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	if (0) {
		int n = 500;
		int k = 250;
		vector<string> a(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i] += (i + j) % 2 ? 'X' : '.';
			}
		}
		cout << fastsolve(a, n, k) << endl;
		return 0;
	}

	int n, k;
	while (cin >> n >> k) {
		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		cout << fastsolve(a, n, k) << endl;
	}

	return 0;
}