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
const int MAXN = 1 << 18;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n;
vector<pair<int, int> > e[MAXN];
int a[MAXN];
int ans[MAXN];
vector<pair<ll, int> > st;
int cnt[MAXN];
int add[MAXN];

void dfs(int v, ll h, int pr) {
	st.push_back(make_pair(h, v));

	int id = lower_bound(st.begin(), st.end(), make_pair(h - a[v], -1)) - st.begin();
	if (id > 0) add[st[id - 1].second]--;
	
	for (auto o : e[v]) {
		int to = o.first;
		if (to == pr) continue;
		dfs(to, h + o.second, v);
		add[v] += add[to];
	}
	ans[v] = add[v];

	add[v]++;
	st.pop_back();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			e[i].clear();
			ans[i] = 0;
			add[i] = 0;
		}
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);

		for (int i = 1; i < n; i++) {
			int p, x;
			scanf("%d%d", &p, &x);
			--p;
			e[p].push_back(make_pair(i, x));
			e[i].push_back(make_pair(p, x));
		}
		dfs(0, 0, 0);
		for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i + 1 == n]);
	}

	return 0;
}