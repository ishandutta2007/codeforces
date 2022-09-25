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

const int MAXN = 1 << 19;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const int INF = (int)(1e9);

int n, m, sz;
int h[MAXN];
int a[MAXN], b[MAXN];
pair<int, int> t[2 * (2 * MAXN)];
int p[MAXN];

void build(int v, int tl, int tr) {
	t[v] = make_pair(0, -1);
	if (tl == tr) {
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
	if (l > r) return make_pair(0, -1);
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) >> 1;
	return max(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void upd(int v, int tl, int tr, int x, pair<int, int> y) {
	if (tl == tr) {
		t[v] = max(t[v], y);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (x <= tm) upd(v * 2, tl, tm, x, y);
	else upd(v * 2 + 1, tm + 1, tr, x, y);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

vector<int> fastsolve() {
	vector<int> vct;
	for (int i = 0; i < n; i++) {
		vct.push_back(h[i]);
	}
	for (int i = 0; i < m; i++) {
		vct.push_back(b[i]);
	}
	sort(vct.begin(), vct.end());
	vct.resize(unique(vct.begin(), vct.end()) - vct.begin());
	for (int i = 0; i < n; i++) h[i] = lower_bound(vct.begin(), vct.end(), h[i]) - vct.begin();
	for (int i = 0; i < m; i++) b[i] = lower_bound(vct.begin(), vct.end(), b[i]) - vct.begin();

	vector<vector<int> > q(n);
	for (int i = 0; i < m; i++) {
		q[a[i] - 1].push_back(i);
	}

	for (int i = 0; i < n; i++) p[i] = -1;
	vector<int> f(n, 0);
	vector<int> ans(m, 1);
	sz = vct.size();
	build(1, 0, sz - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)q[i].size(); j++) {
			int id = q[i][j];
			ans[id] += get(1, 0, sz - 1, 0, b[id] - 1).first;
		}
		pair<int, int> val = get(1, 0, sz - 1, 0, h[i] - 1);
		if (val.first == 0) p[i] = -1;
		else p[i] = -val.second;
		upd(1, 0, sz - 1, h[i], make_pair(val.first + 1, -i));
	}
	int x = -t[1].second;
	while (x != -1) {
		f[x]++;
		x = p[x];
	}
	build(1, 0, sz - 1);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < (int)q[i].size(); j++) {
			int id = q[i][j];
			ans[id] += get(1, 0, sz - 1, b[id] + 1, sz - 1).first;
		}
		pair<int, int> val = get(1, 0, sz - 1, h[i] + 1, sz - 1);
		if (val.first == 0) p[i] = -1;
		else p[i] = val.second;
		upd(1, 0, sz - 1, h[i], make_pair(val.first + 1, i));
	}
	x = t[1].second;
	while (x != -1) {
		f[x]++;
		x = p[x];
	}

	for (int i = 0; i < m; i++) {
		int nval = t[1].first;
		if (f[a[i] - 1] == 2) nval--;
		ans[i] = max(ans[i], nval);
	}

	return ans;
}

void print(vector<int> a) {
	for (int i = 0; i < (int)a.size(); i++) printf("%d\n", a[i]);
}

vector<int> slowsolve() {
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		int old = h[a[i] - 1];
		h[a[i] - 1] = b[i];

		vector<int> d(n + 1, INF);
		d[0] = -INF;
		for (int i = 0; i < n; i++) {
			int j = upper_bound(d.begin(), d.end(), h[i]) - d.begin();
			if (d[j - 1] < h[i] && h[i] < d[j]) {
				d[j] = h[i];
			}
		}
		vector<char> f(n, 0);
		int len = 0;
		while (len < n && d[len + 1] < INF) len++;
		ans.push_back(len);
		h[a[i] - 1] = old;
	}
	return ans;
}

void printAll() {
	cout << "---" << endl;
	cout << n << " " << m << endl;
	for (int i = 0; i < n; i++) cout << h[i] << " \n"[i + 1 == n];
	for (int i = 0; i < m; i++) cout << a[i] << " " << b[i] << endl;
}

void stress(bool f) {
	if (!f) return;
	for (int it = 0;; it++) {
		cerr << it << endl;
		n = rand() % 100 + 1;
		for (int i = 0; i < n; i++) h[i] = rand() % 50 + 1;
		m = rand() % 100 + 1;
		for (int i = 0; i < m; i++) {
			a[i] = rand() % n + 1;
			b[i] = rand() % 100 + 1;
		}

		//if (it == 46) printAll();
		vector<int> ans1 = fastsolve();
		//if (it == 46) printAll();
		vector<int> ans2 = slowsolve();
		//if (it == 46) printAll();
		if (ans1 != ans2) {
			cout << "---" << endl;
			print(ans1);
			cout << "instead of" << endl;
			print(ans2);
			printAll();
			print(fastsolve());
			exit(0);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	stress(0);

	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &h[i]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a[i], &b[i]);
		}

		print(fastsolve());
	}

	return 0;
}