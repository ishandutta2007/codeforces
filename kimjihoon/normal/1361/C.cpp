#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;

int n, pl, a[1000009], dg[2000009];
set<pair<int, int> > v[2000009];
vector<int> ans[29], st[2000009];

void dfs(int hn)
{
	while (!v[hn].empty()) {
		int tn = (*v[hn].begin()).first, p = (*v[hn].begin()).second;
		v[hn].erase(v[hn].begin());
		if (tn == hn) {
			st[hn].push_back(p);
			v[hn].erase(v[hn].begin());
			continue;
		}
		v[tn].erase(make_pair(hn, (p ^ 1)));
		dfs(tn);
		ans[pl].push_back(p ^ 1); 
		ans[pl].push_back(p);
	}
	while (!st[hn].empty()) {
		ans[pl].push_back(st[hn].back());
		ans[pl].push_back(st[hn].back() ^ 1);
		st[hn].pop_back();
	}
}

bool ps(int l)
{
	pl = l;
	ans[pl].clear();
	l = (1 << l); l--;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int a1 = (a[i * 2] & l), a2 = (a[i * 2 + 1] & l);
		mx = max(mx, max(a1, a2));
		v[a1].insert(make_pair(a2, i * 2)); v[a2].insert(make_pair(a1, i * 2 + 1));
		dg[a1]++; dg[a2]++;
	}
	for (int i = 0; i <= mx; i++)
		if (dg[i] & 1) {
			for (int i = 0; i <= mx; i++) {
				v[i].clear();
				dg[i] = 0;
			}
			return false;
		}
	dfs(a[0] & l);
	for (int i = 0; i <= mx; i++) {
		v[i].clear();
		dg[i] = 0;
	}
	if (ans[pl].size() != 2 * n) return false;
	return true;
}

int bs(int s, int e)
{
	int md = (s + e + 1) / 2;
	if (s >= e) return md;
	if (ps(md)) return bs(md, e);
	else return bs(s, md - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];
	int ma = bs(0, 20);
	cout << ma << '\n';
	if (ans[ma].size() != 2 * n)
		ps(ma);
	for (int i = 0; i < 2 * n; i++)
		cout << ans[ma][i] + 1 << " ";
	cout << '\n';
	return 0;
}