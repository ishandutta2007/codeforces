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
const int MOD = 1000 * 1000 * 1000 + 7;

int n, m;
vector<pair<int, ll> > e[MAXN];
vector<int> g[MAXN];
char used[MAXN];
int ans;
ll xr[MAXN];
vector<ll> vct;
int fct[MAXN], ofct[MAXN], pw2[MAXN];

int bin(int n, int k) {
	if (k == 0) return 1 % MOD;
	int res = bin(n, k / 2);
	res = 1LL * res * res % MOD;
	if (k % 2) res = 1LL * res * n % MOD;
	return res;
}

int inv(int x) {
	return bin(x, MOD - 2);
}

inline int getC(int n, int k) {
	return 1LL * fct[n] * ofct[k] % MOD * ofct[n - k] % MOD;
}

vector<int> vv;
void dfs1(int v, int pr, ll curxr) {
	vv.push_back(v);
	used[v] = 1;
	xr[v] = curxr;
	for (int i = 0; i < (int)e[v].size(); i++) {
		int to = e[v][i].first;
		if (used[to]) {
			if (used[to] == 1 && to != pr) {
				vct.push_back(xr[v] ^ xr[to] ^ e[v][i].second);
			}
			e[v][i].second = -1;
			continue;
		}
		dfs1(to, v, curxr ^ e[v][i].second);
	}
	used[v] = 2;
}

int ways0, ways1;
int ways;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

/*pair<int, int> dfs2(int v, int pr, ll bit) {
	int cnt0 = 0, cnt1 = 0;
	if (xr[v] & bit) cnt1++;
	else cnt0++;

	for (int i = 0; i < (int)g[v].size(); i++) {
		//if (e[v][i].second == -1) continue;
		//int to = e[v][i].first;
		int to = g[v][i];
		pair<int, int> ncnt = dfs2(to, v, bit);
		//ways = (ways + 1LL * cnt0 * ncnt.first % MOD * ways1) % MOD;
		//ways = (ways + 1LL * cnt0 * ncnt.second % MOD * ways0) % MOD;
		//ways = (ways + 1LL * cnt1 * ncnt.first % MOD * ways0) % MOD;
		//ways = (ways + 1LL * cnt1 * ncnt.second % MOD * ways1) % MOD;
		ways = (ways + (1LL * cnt0 * ncnt.first + 1LL * cnt1 * ncnt.second) % MOD * ways1 +
			(1LL * cnt0 * ncnt.second + 1LL * cnt1 * ncnt.first) % MOD * ways0) % MOD;
		//cnt0 = (cnt0 + ncnt.first) % MOD;
		//cnt1 = (cnt1 + ncnt.second) % MOD;
		add(cnt0, ncnt.first);
		add(cnt1, ncnt.second);
	}
	return make_pair(cnt0, cnt1);
}*/

void solve(int v) {
	vct.clear();
	vv.clear();
	dfs1(v, -1, 0);
	sort(vct.begin(), vct.end());
	for (int i = 0; i < (int)vct.size(); i++) {
		int mx = i;
		for (int j = i; j < (int)vct.size(); j++) {
			if (vct[j] > vct[mx]) {
				mx = j;
			}
		}
		swap(vct[mx], vct[i]);
		if (vct[i] == 0) {
			vct.resize(i);
			break;
		}
		int bit = -1;
		for (int j = 0; j < 60; j++) if (vct[i] & (1LL << j)) bit = j;
		assert(bit != -1);
		for (int j = i + 1; j < (int)vct.size(); j++) {
			if (vct[j] & (1LL << bit)) {
				vct[j] ^= vct[i];
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		g[i].clear();
		for (int j = 0; j < (int)e[i].size(); j++) {
			if (e[i][j].second != -1) {
				g[i].push_back(e[i][j].first);
			}
		}
	}*/

	for (int bit = 0; bit < 60; bit++) {
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < (int)vct.size(); i++) {
			if (vct[i] & (1LL << bit)) cnt1++;
			else cnt0++;
		}
		ways0 = ways1 = 0;
		for (int i = 0; i <= cnt1; i++) {
			if (i % 2 == 0) {
				//ways0 = (ways0 + getC(cnt1, i)) % MOD;
				add(ways0, getC(cnt1, i));
			}
			else {
				//ways1 = (ways1 + getC(cnt1, i)) % MOD;
				add(ways1, getC(cnt1, i));
			}
		}
		ways0 = 1LL * ways0 * pw2[cnt0] % MOD;
		ways1 = 1LL * ways1 * pw2[cnt0] % MOD;

		ways = 0;
		
		cnt0 = 0;
		cnt1 = 0;
		for (int v : vv) {
			if (xr[v] & (1LL << bit)) cnt1++;
			else cnt0++;
		}
		ways = (ways + (1LL * cnt0 * (cnt0 - 1) / 2 + 1LL * cnt1 * (cnt1 - 1) / 2) % MOD * ways1 +
			(1LL * cnt0 * cnt1) % MOD * ways0) % MOD;

		ans = (ans + 1LL * pw2[bit] * ways) % MOD;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	fct[0] = 1;
	for (int i = 1; i < MAXN; i++) fct[i] = 1LL * fct[i - 1] * i % MOD;
	ofct[MAXN - 1] = inv(fct[MAXN - 1]);
	for (int i = MAXN - 2; i >= 0; i--) {
		ofct[i] = 1LL * ofct[i + 1] * (i + 1) % MOD;
	}
	pw2[0] = 1;
	for (int i = 1; i < MAXN; i++) pw2[i] = pw2[i - 1] * 2LL % MOD;

	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 0; i < n; i++) {
			e[i].clear();
			used[i] = 0;
		}
		ans = 0;

		for (int i = 0; i < m; i++) {
			int u, v;
			ll w;
			scanf("%d%d%I64d", &u, &v, &w);
			--u; --v;
			e[u].push_back(make_pair(v, w));
			e[v].push_back(make_pair(u, w));
		}

		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				solve(i);
			}
		}
		printf("%d\n", ans);
	}

#ifndef ONLINE_JUDGE
	cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
	return 0;
}