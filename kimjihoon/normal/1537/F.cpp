#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int ds[200009], d[200009];
long long t[200009];
vector<int> p[200009];
vector<pair<int, int> > pv;

int uf(int n)
{
	if (n == ds[n]) return n;
	return ds[n] = uf(ds[n]);
}

void dfs(int n, int pr)
{
	for (int i = 0; i < p[n].size(); i++) {
		int tn = p[n][i];
		if (tn == pr) continue;
		d[tn] = 1 - d[n];
		dfs(tn, n);
	}
	if (pr) {
		t[pr] -= t[n];
		t[n] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		pv.clear();
		for (int i = 1; i <= n; i++) {
			cin >> t[i];
			ds[i] = i;
			p[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			long long a; cin >> a;
			t[i] = a - t[i];
		}
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			int ua = uf(a), ub = uf(b);
			if (ua != ub) {
				ds[ua] = ub;
				p[a].push_back(b);
				p[b].push_back(a);
			}
			else
				pv.push_back(make_pair(a, b));
		}
		d[1] = 0;
		dfs(1, 0);
		if (abs(t[1]) % 2 == 1) {
			cout << "NO" << '\n';
			continue;
		}
		if (t[1] == 0) {
			cout << "YES" << '\n';
			continue;
		}
		bool f = false;
		for (int i = 0; i < pv.size(); i++) {
			int a = pv[i].first, b = pv[i].second;
			if (d[a] == d[b]) {
				f = true;
				break;
			}
		}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;	
}