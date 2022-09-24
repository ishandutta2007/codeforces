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

	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		vector<int> r(n);
		for (int i = 0; i < n; i++) scanf("%d", &r[i]);

		vector<vector<int> > a(m);
		vector<vector<int> > e(n);
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			a[i].resize(x);
			for (int j = 0; j < x; j++) {
				scanf("%d", &a[i][j]);
				a[i][j]--;
				e[a[i][j]].push_back(i);
			}
		}

		vector<char> ans(m, -1);
		vector<char> vis(n, 0);
		bool fail = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			bool ok = 0;
			for (int touch = 0; touch < 2; touch++) {
				bool cok = 1;
				queue<int> q;
				ans[e[i][0]] = touch;
				q.push(e[i][0]);
				vector<int> vv;
				while (!q.empty()) {
					int v = q.front();
					vv.push_back(v);
					q.pop();
					for (int x : a[v]) {
						vis[x] = 1;
						bool found = 0;
						for (int it = 0; it < (int)e[x].size(); it++) {
							int y = e[x][it];
							if (ans[y] == -1) {
								ans[y] = r[x] ^ ans[e[x][it ^ 1]] ^ 1;
								q.push(y);
								found = 1;
							}
						}
						if (!found && (r[x] ^ ans[e[x][0]] ^ ans[e[x][1]]) == 0) {
							cok = false;
						}
					}
				}
				if (cok) {
					ok = 1;
					break;
				}
				for (int v : vv) ans[v] = -1;
			}
			if (!ok) fail = 1;
		}
		if (fail) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}