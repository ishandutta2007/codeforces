#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int md, a[200009], dt[200009], pr[200009], mn[200009], mx[200009];
long long d[200009];
vector<int> ch[200009];
vector<pair<int, int> > v[200009];
vector<long long> dl[200009], dr[200009];

void dfs(int n)
{
	md = max(md, dt[n]);
	v[dt[n]].push_back(make_pair(a[n], n));
	dl[dt[n]].push_back(0LL); dr[dt[n]].push_back(0LL);
	mx[dt[n]] = max(mx[dt[n]], a[n]);
	mn[dt[n]] = min(mn[dt[n]], a[n]);
	for (int i = 0; i < ch[n].size(); i++) {
		int tn = ch[n][i];
		dt[tn] = dt[n] + 1;
		dfs(tn);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			ch[i].clear();
			dl[i].clear(); dr[i].clear();
			d[i] = 0;
			mx[i] = -1000000009, mn[i] = 1000000009;
		}
		for (int i = 2; i <= n; i++) {
			cin >> pr[i];
			ch[pr[i]].push_back(i);
		}
		for (int i = 2; i <= n; i++)
			cin >> a[i];
		dt[1] = 1; md = 1;
		dfs(1);
		for (int i = 1; i <= md; i++)
			sort(v[i].begin(), v[i].end());
		long long ans = 0;
		for (int i = 2; i <= md; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				int hn = v[i][j].second;
				long long t = d[pr[hn]] - 1LL * a[hn];
				if (j == 0) dl[i][j] = t;
				else dl[i][j] = max(dl[i][j - 1], t);
			}
			for (int j = (int)v[i].size() - 1; j >= 0; j--) {
				int hn = v[i][j].second;
				long long t = d[pr[hn]] + 1LL * a[hn];
				if (j == (int)v[i].size() - 1) dr[i][j] = t;
				else dr[i][j] = max(dr[i][j + 1], t);
			}
			for (int j = 0; j < v[i].size(); j++) {
				int hn = v[i][j].second;
				d[hn] = d[pr[hn]] + max(1LL * a[hn] - 1LL * mn[i], mx[i] - 1LL * a[hn]);
				if (j > 0) d[hn] = max(d[hn], dl[i][j - 1] + 1LL * a[hn]);
				if (j + 1 < v[i].size()) d[hn] = max(d[hn], dr[i][j + 1] - 1LL * a[hn]);
				if (i == md) ans = max(ans, d[hn]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}