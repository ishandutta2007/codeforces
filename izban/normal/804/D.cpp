#include <unordered_map>
#include <unordered_set>
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

const int MAXK = 17;
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

int n, m, q;
vector<int> e[MAXN];
int down[MAXN];
int any[MAXN];
int cdiam, ccomp, comp[MAXN];
int cnt[MAXN];

void dfs1(int v, int pr, int ch) {
	down[v] = 0;
	for (int to : e[v]) {
		if (to == pr) continue;
		dfs1(to, v, ch + 1);
		down[v] = max(down[v], down[to] + 1);
	}
}

void dfs2(int v, int pr) {
	any[v] = 0;
	for (int to : e[v]) {
		any[v] = max(any[v], down[to] + 1);
	}
	cdiam = max(cdiam, any[v]);
	cnt[any[v]]++;
	comp[v] = ccomp;

	int k = e[v].size();
	vector<int> pref(k + 2, 0), suf(k + 2, 0);
	for (int i = 1; i <= k; i++) pref[i] = max(pref[i - 1], down[e[v][i - 1]] + 1);
	for (int i = k; i >= 1; i--) suf[i] = max(suf[i + 1], down[e[v][i - 1]] + 1);

	for (int i = 1; i <= k; i++) {
		int to = e[v][i - 1];
		if (to == pr) continue;
		int old = down[v];
		down[v] = max(pref[i - 1], suf[i + 1]);
		dfs2(to, v);
		down[v] = old;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d%d", &n, &m, &q) == 3) {
		for (int i = 0; i < n; i++) {
			e[i].clear();
			comp[i] = -1;
		}

		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}

		vector<vector<int> > vct;
		ccomp = 0;
		for (int i = 0; i < n; i++) {
			if (comp[i] != -1) continue;
			cdiam = 0;
			dfs1(i, -1, 0);
			dfs2(i, -1);
			vector<int> cur(cdiam + 1);
			for (int i = 0; i <= cdiam; i++) cur[i] = cnt[i];
			vct.push_back(cur);

			for (int i = 0; i <= cdiam; i++) cnt[i] = 0;
			ccomp++;
		}
		vector<vector<ll> > sum(ccomp);
		vector<vector<ll> > sum2(ccomp);
		for (int i = 0; i < ccomp; i++) {
			sum[i].assign(vct[i].size(), 0);
			sum2[i].assign(vct[i].size(), 0);
			for (int j = (int)sum[i].size() - 1; j >= 0; j--) {
				if (j + 1 < (int)sum[i].size()) {
					sum[i][j] = sum[i][j + 1];
					sum2[i][j] = sum2[i][j + 1];
				}
				sum[i][j] += vct[i][j];
				sum2[i][j] += 1LL * vct[i][j] * j;
			}
		}

		map<pair<int, int>, double> mp;
		for (int i = 0; i < q; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			u = comp[u];
			v = comp[v];
			if (u == v) {
				printf("%d\n", -1);
			}
			else {
				if (!mp.count(make_pair(u, v))) {
					if (vct[u].size() > vct[v].size()) swap(u, v);
					int maxdiam = max((int)vct[u].size() - 1, (int)vct[v].size() - 1);

					ll ccnt = 0;
					ll csum = 0;
					for (int i = 0; i < (int)vct[u].size(); i++) {
						// i + j + 1 > maxdiam
						int j = maxdiam - i;
						if (j < (int)vct[v].size()) {
							ccnt += 1LL * vct[u][i] * sum[v][j];
							csum += 1LL * vct[u][i] * (sum2[v][j] + 1LL * sum[v][j] * (i + 1));
						}
					}
					ll cnt2 = 1LL * sum[v][0] * sum[u][0] - ccnt;
					double res = (cnt2 * maxdiam + csum) * 1.0 / (1LL * sum[v][0] * sum[u][0]);
					mp[make_pair(u, v)] = res;
				}
				printf("%.15f\n", mp[make_pair(u, v)]);
			}
		}
	}

	return 0;
}