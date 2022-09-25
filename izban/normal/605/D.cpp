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

const int MAXN = 1 << 17;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n;
pair<int, int> a[MAXN], b[MAXN];

set<pair<int, int> > t[4 * MAXN];

void build(int v, int tl, int tr) {
	t[v].clear();
	if (tl == tr) return;
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
}

void add(int v, int tl, int tr, int x, pair<int, int> o) {
	t[v].insert(o);
	if (tl == tr) return;
	int tm = (tl + tr) >> 1;
	if (x <= tm) add(v * 2, tl, tm, x, o);
	else add(v * 2 + 1, tm + 1, tr, x, o);
}

void del(int v, int tl, int tr, int x, pair<int, int> o) {
	t[v].erase(o);
	if (tl == tr) return;
	int tm = (tl + tr) >> 1;
	if (x <= tm) del(v * 2, tl, tm, x, o);
	else del(v * 2 + 1, tm + 1, tr, x, o);
}

vector<int> vct;

void get(int v, int tl, int tr, int l, int r, int ly, int ry) {
	if (l > r) return;
	if (l == tl && r == tr) {
		set<pair<int, int> > ::iterator it = t[v].lower_bound(make_pair(ly, -1));
		while (it != t[v].end() && it->first <= ry) {
			vct.push_back(it->second);
			it++;
		}
		return;
	}
	int tm = (tl + tr) >> 1;
	get(v * 2, tl, tm, l, min(r, tm), ly, ry);
	get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, ly, ry);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d", &n) == 1) {
		vector<int> vx(1, 0);
		//vector<int> vy(1, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d%d", &a[i].first, &a[i].second, &b[i].first, &b[i].second);
			vx.push_back(a[i].first);
			vx.push_back(b[i].first);
			//vy.push_back(a[i].second);
			//vy.push_back(b[i].second);
		}
		sort(vx.begin(), vx.end());
		vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
		//sort(vy.begin(), vy.end());
		//vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
		for (int i = 0; i < n; i++) {
			a[i].first = lower_bound(vx.begin(), vx.end(), a[i].first) - vx.begin();
			b[i].first = lower_bound(vx.begin(), vx.end(), b[i].first) - vx.begin();
			//a[i].second = lower_bound(vy.begin(), vy.end(), a[i].second) - vy.begin();
			//b[i].second = lower_bound(vy.begin(), vy.end(), b[i].second) - vy.begin();
		}

		int m = vx.size();
		build(1, 0, m - 1);
		for (int i = 0; i < n; i++) {
			add(1, 0, m - 1, a[i].first, make_pair(a[i].second, i));
		}

		b[n] = make_pair(0, 0);
		vector<int> p(n, -1);
		queue<int> q;
		q.push(n);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			vct.clear();
			get(1, 0, m - 1, 0, b[v].first, 0, b[v].second);
			for (int i = 0; i < (int)vct.size(); i++) {
				p[vct[i]] = v;
				q.push(vct[i]);
				del(1, 0, m - 1, a[vct[i]].first, make_pair(a[vct[i]].second, vct[i]));
			}
		}

		if (p[n - 1] == -1) {
			printf("%d\n", -1);
		}
		else {
			vector<int> ans;
			int v = n - 1;
			while (v != n) {
				ans.push_back(v + 1);
				v = p[v];
			}
			reverse(ans.begin(), ans.end());
			printf("%d\n", ans.size());
			for (int i = 0; i < (int)ans.size(); i++) printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
		}
	}

	return 0;
}