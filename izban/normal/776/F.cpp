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
	//freopen("output.txt", "w", stdout);
#endif

	int n, m;
	while (cin >> n >> m) {
		vector<pair<int, int> > edges(m);
		for (int i = 0; i < m; i++) {
			cin >> edges[i].first >> edges[i].second;
			edges[i].first--;
			edges[i].second--;
		}
		if (m == 0) {
			printf("%d\n", 1);
			continue;
		}
		/*n = 1e5;
		m = n - 3;
		edges.resize(m);
		for (int i = 0; i < m; i++) edges[i] = make_pair(0, i + 2);*/

		vector<vector<int> > e(n);
		for (int i = 0; i < m; i++) {
			e[edges[i].first].push_back(edges[i].second);
			e[edges[i].second].push_back(edges[i].first);
		}

		vector<map<int, int> > id(n);
		for (int i = 0; i < n; i++) {
			e[i].push_back((i + 1) % n);
			e[i].push_back((i - 1 + n) % n);
			sort(e[i].begin(), e[i].end(), [&](int x, int y) {
				if ((x < i) != (y < i)) {
					return x >= i;
				}
				return x < y;
			});
			for (int j = 0; j < (int)e[i].size(); j++) {
				id[i][e[i][j]] = j;
			}
		}

		map<pair<int, int>, int> mp;
		vector<vector<int> > comps;
		for (int i = 0; i < m; i++) {
			int u = edges[i].first;
			int v = edges[i].second;

			for (int it = 0; it < 2; it++) {
				swap(u, v);
				if (mp.count(make_pair(u, v))) continue;
				int x = v;
				int prev = u;
				vector<int> vct;
				vct.push_back(u);
				while (x != u) {
					vct.push_back(x);
					int cid = id[x][prev];
					assert(cid > 0);
					int nw = e[x][cid - 1];
					prev = x;
					x = nw;
				}
				for (int j = 0; j < (int)vct.size(); j++) {
					mp[make_pair(vct[j], vct[(j + 1) % (int)vct.size()])] = comps.size();
				}
				comps.push_back(vct);
			}
		}
		int k = comps.size();
		vector<vector<int> > scomps(k);
		for (int i = 0; i < k; i++) {
			scomps[i] = comps[i];
			sort(scomps[i].begin(), scomps[i].end());
			reverse(scomps[i].begin(), scomps[i].end());
		}
		vector<int> p(k);
		for (int i = 0; i < k; i++) {
			p[i] = i;
		}
		sort(p.begin(), p.end(), [&](int i, int j) {
			return scomps[i] < scomps[j];
		});
		vector<int> o(k);
		for (int i = 0; i < k; i++) o[p[i]] = i;

		vector<vector<int> > g(k);
		for (int i = 0; i < m; i++) {
			int u = edges[i].first;
			int v = edges[i].second;

			auto it1 = mp.find(make_pair(u, v));
			assert(it1 != mp.end());
			int id1 = it1->second;

			auto it2 = mp.find(make_pair(v, u));
			assert(it2 != mp.end());
			int id2 = it2->second;

			id1 = o[id1];
			id2 = o[id2];
			g[id1].push_back(id2);
			g[id2].push_back(id1);
		}

		vector<int> cnt(k);
		vector<int> alive(k, 1);
		vector<int> last(k, 0);
		int tmr = 0;

		function<void(int)> dfs = [&](int v) {
			last[v] = tmr;
			cnt[v] = 1;
			for (int to : g[v]) {
				if (!alive[to] || last[to] == tmr) continue;
				dfs(to);
				cnt[v] += cnt[to];
			}
		};

		vector<int> ans(k);
		function<void(int, int)> solve = [&](int v, int cc) {
			tmr++;
			dfs(v);
			int prev = -1;
			int all = cnt[v];
			while (1) {
				bool found = 0;
				for (int to : g[v]) {
					if (!alive[to]) continue;
					if (to != prev && cnt[to] * 2 >= all) {
						prev = v;
						v = to;
						found = 1;
						break;
					}
				}
				if (!found) break;
			}
			ans[v] = cc;
			alive[v] = 0;
			for (int to : g[v]) {
				if (!alive[to]) continue;
				solve(to, cc + 1);
			}
		};
		solve(0, 1);
		for (int i = 0; i < k; i++) assert(ans[i] != 0);
		for (int i = 0; i < k; i++) printf("%d%c", ans[i], " \n"[i + 1 == k]);

		//break;
	}

	return 0;
}