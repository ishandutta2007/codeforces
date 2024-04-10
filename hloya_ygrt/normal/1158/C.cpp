#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int maxn = 5e5 + 100;

vector<int> g[maxn];
int ans[maxn];
int n;
int nxt[maxn];
vector<int> ord;
int sum[4 * maxn];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		sum[v] = 1;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v<<1, tl, tm);
	build(v<<1|1, tm + 1, tr);
	sum[v] = sum[v<<1] + sum[v<<1|1];
}

void upd(int v, int tl, int tr, int pos) {
	if (tl == tr) {
		sum[v] = 0;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v<<1, tl, tm, pos);
	else
		upd(v<<1|1, tm + 1, tr, pos);
	sum[v] = sum[v<<1] + sum[v<<1|1];
}

int get(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return n;
	if (sum[v] == 0)
		return n;
	if (tl == tr)
		return tl;
	int tm = (tl + tr) >> 1;
	int x = get(v<<1, tl, tm, l, min(r, tm));
	if (x != n)
		return x;
	x = get(v<<1|1, tm + 1, tr, max(l, tm + 1), r);
	return x;
}

bool used[maxn];

bool check() {
	vector<pair<int, int> > st;
	st.push_back(make_pair(n, n));
	for (int i = n - 1; i >= 0; i--) {
		while (st.size() && st.back().first < ans[i])
			st.pop_back();
		int rn = st.back().second;
		if (nxt[i] != -1 && rn != nxt[i]) {
			return false;
		}
		st.push_back(make_pair(ans[i], i));
	}
	return true;	
}

void dfs(int v) {
	used[v] = 1;
	upd(1, 0, n - 1, v);

	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}

	if (nxt[v] != -1) {
		int l = v + 1, r = nxt[v] -  1;
		while (l <= r) {
			int x = get(1, 0, n - 1, l, r);
			if (x < n) {
				dfs(x);
			}
			l = x + 1;
		}
	}

	ord.push_back(v);
}

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		used[i] = 0;
		g[i].clear();
	}

	for (int i = 0; i < n; i++) {
		cin >> nxt[i];
		if (nxt[i] != -1)
			nxt[i]--;

		if (nxt[i] != -1 && nxt[i] != n)
			g[nxt[i]].push_back(i);
	}

	build(1, 0, n - 1);
	ord.clear();

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}

	// reverse(all(ord));

	for (int i = 0; i < n; i++) {
		ans[ord[i]] = i;
	}

	if (!check()) {
		cout << -1 << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] + 1 << ' ';
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}