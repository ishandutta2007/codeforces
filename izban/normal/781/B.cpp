#include <functional>
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

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vector<string> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}

		vector<vector<string> > s(2, vector<string>(n));
		for (int i = 0; i < n; i++) {
			s[0][i] = a[i].substr(0, 3);
			s[1][i] = a[i].substr(0, 2) + b[i].substr(0, 1);
		}

		vector<vector<int> > e(n * 2);
		vector<vector<int> > g(n * 2);

		auto addEdge = [&](int u, int v) {
			e[u].push_back(v);
			g[v].push_back(u);
		};

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) if (i != j) {
				for (int ii = 0; ii < 2; ii++) {
					for (int jj = 0; jj < 2; jj++) {
						if (s[ii][i] == s[jj][j]) {
							addEdge(i * 2 + ii, ((j * 2 + jj) ^ 1));
						}
					}
				}
				if (s[0][i] == s[0][j]) {
					addEdge(i * 2 + 1, j * 2 + 1);
				}
			}
		}
		vector<char> vis(n * 2);
		vector<int> vct;
		vector<int> c(n * 2, -1);
		int cc = 0;
		function<void(int)> dfs1 = [&](int v) {
			vis[v] = 1;
			for (int to : e[v]) {
				if (vis[to]) continue;
				dfs1(to);
			}
			vct.push_back(v);
		};
		function<void(int)> dfs2 = [&](int v) {
			c[v] = cc;
			for (int to : g[v]) {
				if (c[to] == -1) {
					dfs2(to);
				}
			}
		};

		for (int i = 0; i < n * 2; i++) {
			if (!vis[i]) {
				dfs1(i);
			}
		}
		for (int i = 0; i < n * 2; i++) {
			int v = vct[n * 2 - i - 1];
			if (c[v] == -1) {
				dfs2(v);
				cc++;
			}
		}
		
		vector<int> id(n, -1);
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			if (c[i * 2] == c[i * 2 + 1]) {
				ok = 0;
			}
			else {
				id[i] = c[i * 2 + 1] > c[i * 2];
			}
		}
		if (ok) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) cout << s[id[i]][i] << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}