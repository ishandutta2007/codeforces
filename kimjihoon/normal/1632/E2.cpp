#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int inf = 100000000;

struct node
{
	int mx, mn, lmx, rmx, smx;
};

node st[2400009];
int dt[300009], ds[300009], rd[300009], ans[300009];
vector<int> v[300009], rv[300009];
vector<int> sv;
queue<int> q;
bool vs[300009];

void init(int tn, int s, int e)
{
	if (s == e) {
		st[tn].mx = st[tn].mn = dt[sv[s]];
		st[tn].lmx = st[tn].rmx = -dt[sv[s]];
		st[tn].smx = 0;
		return;
	}
	int md = (s + e) / 2;
	init(tn * 2, s, md);
	init(tn * 2 + 1, md + 1, e);
	st[tn].mx = max(st[tn * 2].mx, st[tn * 2 + 1].mx);
	st[tn].mn = min(st[tn * 2].mn, st[tn * 2 + 1].mn);
	st[tn].lmx = max(max(st[tn * 2].lmx, st[tn * 2 + 1].lmx), st[tn * 2].mx - st[tn * 2 + 1].mn * 2);
	st[tn].rmx = max(max(st[tn * 2].rmx, st[tn * 2 + 1].rmx), st[tn * 2 + 1].mx - st[tn * 2].mn * 2);
	st[tn].smx = max(max(st[tn * 2].smx, st[tn * 2 + 1].smx), max(st[tn * 2].mx + st[tn * 2 + 1].rmx, st[tn * 2].lmx + st[tn * 2 + 1].mx));
}

void update(int tn, int s, int e, int p)
{
	if (s == e) {
		st[tn].mx = st[tn].lmx = st[tn].rmx = st[tn].smx = -inf;
		return;
	}
	int md = (s + e) / 2;
	if (p <= md) update(tn * 2, s, md, p);
	else update(tn * 2 + 1, md + 1, e, p);
	st[tn].mx = max(st[tn * 2].mx, st[tn * 2 + 1].mx);
	st[tn].mn = min(st[tn * 2].mn, st[tn * 2 + 1].mn);
	st[tn].lmx = max(max(st[tn * 2].lmx, st[tn * 2 + 1].lmx), st[tn * 2].mx - st[tn * 2 + 1].mn * 2);
	st[tn].rmx = max(max(st[tn * 2].rmx, st[tn * 2 + 1].rmx), st[tn * 2 + 1].mx - st[tn * 2].mn * 2);
	st[tn].smx = max(max(st[tn * 2].smx, st[tn * 2 + 1].smx), max(st[tn * 2].mx + st[tn * 2 + 1].rmx, st[tn * 2].lmx + st[tn * 2 + 1].mx));
}

void dfs(int n, int p)
{
	rv[n].push_back(sv.size());
	sv.push_back(n);
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (p == tn) continue;
		dt[tn] = dt[n] + 1;
		dfs(tn, n);
		rv[n].push_back(sv.size());
		sv.push_back(n);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		sv.clear(); sv.push_back(0);
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			rv[i].clear();
			vs[i] = false;
			rd[i] = n;
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b); v[b].push_back(a);
		}
		dt[1] = 0;
		dfs(1, 0);
		int sn = (int)sv.size() - 1;
		init(1, 1, sn);
		while (!q.empty())
			q.pop();
		q.push(1); vs[1] = true; ds[1] = 0;
		while (!q.empty()) {
			int hn = q.front(); q.pop();
			for (int i = 0; i < rv[hn].size(); i++)
				update(1, 1, sn, rv[hn][i]);
			if (st[1].smx < 0) rd[ds[hn]] = n;
			else rd[ds[hn]] = max(0, ds[hn] - (st[1].smx + 1) / 2);
			for (int i = 0; i < v[hn].size(); i++) {
				int tn = v[hn][i];
				if (vs[tn]) continue;
				q.push(tn); 
				ds[tn] = ds[hn] + 1; vs[tn] = true;
			}
		}
		rd[0] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = rd[i - 1] + 1; j <= rd[i]; j++)
				ans[j] = i;
		for (int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}