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

vector<vector<pair<int, int> > > p;

pair<int, int> get(pair<int, int> o) {
	if (o == p[o.first][o.second]) return o;
	return p[o.first][o.second] = get(p[o.first][o.second]);
}

void uni(pair<int, int> a, pair<int, int> b) {
	a = get(a);
	b = get(b);
	p[b.first][b.second] = a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		vector<vector<int> > a(n, vector<int>(m));
		vector<int> vct;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			vct.push_back(a[i][j]);
		}
		sort(vct.begin(), vct.end());
		vct.resize(unique(vct.begin(), vct.end()) - vct.begin());
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			a[i][j] = lower_bound(vct.begin(), vct.end(), a[i][j]) - vct.begin();
		}

		vector<vector<int> > b(n, vector<int>(m));

		vector<int> mx1(n, 0), mx2(m, 0);
		vector<vector<pair<int, int> > > mp(vct.size());
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) mp[a[i][j]].push_back(make_pair(i, j));

		p.assign(n, vector<pair<int, int> >(m));
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) p[i][j] = make_pair(i, j);
		vector<vector<pair<int, int> > > sp1(n);
		vector<vector<pair<int, int> > > sp2(m);

		for (int ii = 0; ii < (int)vct.size(); ii++) {
			const vector<pair<int, int> > &v = mp[ii];

			int k = v.size();
			vector<int> nval(k);
			for (int i = 0; i < k; i++) {
				int x = v[i].first, y = v[i].second;
				nval[i] = max(mx1[x], mx2[y]) + 1;
				sp1[x].push_back(make_pair(x, y));
				sp2[y].push_back(make_pair(x, y));
			}

			for (int i = 0; i < k; i++) {
				int x = v[i].first, y = v[i].second;
				if (!sp1[x].empty()) {
					for (int j = 1; j < (int)sp1[x].size(); j++) {
						uni(sp1[x][j - 1], sp1[x][j]);
					}
					sp1[x].clear();
				}
				if (!sp2[y].empty()) {
					for (int j = 1; j < (int)sp2[y].size(); j++) {
						uni(sp2[y][j - 1], sp2[y][j]);
					}
					sp2[y].clear();
				}
			}

			for (int i = 0; i < k; i++) {
				int x = v[i].first, y = v[i].second;
				pair<int, int> o = get(make_pair(x, y));
				b[o.first][o.second] = max(b[o.first][o.second], nval[i]);
			}

			for (int i = 0; i < k; i++) {
				int x = v[i].first, y = v[i].second;
				pair<int, int> o = get(make_pair(x, y));
				b[x][y] = b[o.first][o.second];
				mx1[x] = max(mx1[x], b[x][y]);
				mx2[y] = max(mx2[y], b[x][y]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d%c", b[i][j], " \n"[j + 1 == m]);
			}
		}
	}

	return 0;
}