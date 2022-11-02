#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int p[200009], qf[1000009], ds[200009], sz[200009], cd[200009], cv[400009][2], rsz[400009], lb[200009], lc = 0;
vector<vector<int> > ct;
vector<set<pair<int, int> > > sv;
pair<int, int> eg[300009], qr[1000009];
bool er[300009];

int uf(int n)
{
	if (ds[n] == n) return n;
	return ds[n] = uf(ds[n]);
}

void dfs(int n)
{
	if (!cv[n][0]) {
		if (lb[n]) sv[lb[n]].erase(make_pair(-p[n], n));
		if (p[n]) sv[lc].insert(make_pair(-p[n], n));
		lb[n] = lc;
		return;
	}
	dfs(cv[n][0]); dfs(cv[n][1]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, q; cin >> n >> m >> q;
	ct.push_back(vector<int>());
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		ds[i] = cd[i] = i; sz[i] = rsz[i] = 1;
		ct.push_back(vector<int>());
		ct[i].push_back(i);
	}
	for (int i = 1; i <= m; i++) 
		cin >> eg[i].first >> eg[i].second;
	for (int i = 1; i <= q; i++) {
		cin >> qr[i].first >> qr[i].second;
		if (qr[i].first == 2) er[qr[i].second] = true;
	}
	for (int i = 1; i <= m; i++) {
		if (er[i]) continue;
		q++;
		qr[q].first = 2; qr[q].second = i;
	}
	int nc = n;
	for (int i = q; i >= 1; i--) {
		if (qr[i].first == 1) continue;
		int a = eg[qr[i].second].first, b = eg[qr[i].second].second;
		a = uf(a); b = uf(b);
		if (a == b) continue;
		nc++;
		qf[i] = nc;
		if (sz[a] > sz[b]) swap(a, b);
		cv[nc][0] = cd[a]; cv[nc][1] = cd[b];
		rsz[nc] = sz[a] + sz[b];
		ds[b] = a; sz[a] += sz[b];
		cd[a] = nc;
	}
	sv.push_back(set<pair<int, int> >());
	for (int i = 1; i <= n; i++)
		if (ds[i] == i) {
			sv.push_back(set<pair<int, int> >());
			lc++;
			dfs(cd[i]);
		}
	for (int i = 1; i <= q; i++) {
		if (qr[i].first == 1) {
			if (sv[lb[qr[i].second]].empty())
				cout << 0 << '\n';
			else {
				auto t = sv[lb[qr[i].second]].begin();
				cout << -(*t).first << '\n';
				p[(*t).second] = 0;
				sv[lb[qr[i].second]].erase(t);
			}
		}
		else if (qf[i]) {
			sv.push_back(set<pair<int, int> >());
			lc++;
			dfs(cv[qf[i]][0]);
		}
	}
	return 0;
}