#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>

using namespace std;

vector< vector< pair<int, int> > > g;
int n;
const long long INF = 1e18;

void buildin(int v, int tl, int tr) {
	if (tl != tr) {
		int tm = (tl + tr) >> 1;
		buildin((v << 1), tl, tm);
		buildin(((v << 1) | 1), tm + 1, tr);
		g[v + n].push_back({ (v << 1) + n, 0 });
		g[v + n].push_back({ ((v << 1) | 1) + n, 0 });
	}
	else
		g[v + n].push_back({ tl, 0 });

	return;
}

void buildout(int v, int tl, int tr) {
	if (tl != tr) {
		int tm = (tl + tr) >> 1;
		buildout((v << 1), tl, tm);
		buildout(((v << 1) | 1), tm + 1, tr);
		g[(v << 1) + 5 * n].push_back({ v + 5 * n, 0 });
		g[((v << 1) | 1) + 5 * n].push_back({ v + 5 * n, 0 });
	}
	else {
		g[tl].push_back({ v + 5 * n, 0 });
	}
	return;
}

void updatein(int v, int tl, int tr, int l, int r, int fr, int val) {
	if (l > r)
		return;
	if (l == tl && r == tr) {
		g[fr].push_back({ v + n, val });
	}
	else {
		int tm = (tl + tr) >> 1;
		updatein((v << 1), tl, tm, l, min(r, tm), fr, val);
		updatein(((v << 1) | 1), tm + 1, tr, max(tm + 1, l), r, fr, val);
	}
	return;
}
void updateout(int v, int tl, int tr, int l, int r, int to, int val) {
	if (l > r)
		return;
	if (l == tl && r == tr) {
		g[v + 5 * n].push_back({ to, val });
	}
	else {
		int tm = (tl + tr) >> 1;
		updateout((v << 1), tl, tm, l, min(r, tm), to, val);
		updateout(((v << 1) | 1), tm + 1, tr, max(tm + 1, l), r, to, val);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int  m, s;
	cin >> n >> m >> s; s--;
	g.resize(9 * n);
	buildin(1, 0, n - 1); buildout(1, 0, n - 1);
	while (m--) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int u, v, w;
			cin >> u >> v >> w; u--; v--;
			updatein(1, 0, n - 1, v, v, u, w);
		}
		if (tp == 2) {
			int v, l, r, w;
			cin >> v >> l >> r >> w; v--; l--; r--;
			updatein(1, 0, n - 1, l, r, v, w);
		}
		if (tp == 3) {
			int v, l, r, w;
			cin >> v >> l >> r >> w; v--; l--; r--;
			updateout(1, 0, n - 1, l, r, v, w);
		}
	}
	vector<long long> d(9 * n, INF);
	d[s] = 0;
	priority_queue < pair<long long, int> > q;
	q.push(make_pair(0, s));
	while (!q.empty()) {
		int v = q.top().second;
		long long cur_d = -q.top().first;
		q.pop();
		if (cur_d != d[v])  continue;
		for (pair<int, int> to : g[v]) {
			if (d[v] + to.second < d[to.first]) {
				d[to.first] = d[v] + to.second;
				q.push(make_pair(-d[to.first], to.first));
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (d[i] == INF)
			cout << -1 << ' ';
		else
			cout << d[i] << ' ';
	return 0;
}