#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;	

vector<int> v[3009];
int dt[3009], ch[3009], dg[3009][3009], c[3009][3009], l[3009][3009];
long long d[3009][3009];
bool vs[3009][3009], pr[3009][3009];
queue < pair<int, int> > q;

void dfs(int n, int p)
{
	ch[n] = 1;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == p) continue;
		dt[tn] = dt[n] + 1;
		dfs(tn, n);
		ch[n] += ch[tn];
	}
}

void dfst(int n, int rt, int pt)
{
	pr[n][rt] = true; l[rt][n] = pt;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (n == rt) pt = tn;
		if (dt[tn] < dt[n]) continue;
		dfst(tn, rt, pt);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	dt[1] = 1;
	dfs(1, 0);
	for (int i = 1; i <= n; i++) 
		dfst(i, i, -1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (pr[i][j] || (!pr[i][j] && !pr[j][i])) dg[i][j] = ch[i];
			else dg[i][j] = n - ch[l[i][j]];
		}
	for (int i = 1; i <= n; i++) {
		q.push(make_pair(i, i));
		d[i][i] = 0; dg[i][i] = 1; vs[i][i] = true;
	}
	long long ans = 0;
	while (!q.empty()) {
		int a = q.front().first, b = q.front().second; q.pop();
		ans = max(ans, d[a][b]);
		for (int i = 0; i < v[a].size(); i++) {
			int tn = v[a][i], ta = tn, tb = b;
			if (ta > tb) swap(ta, tb);
			if (vs[ta][tb]) continue;
			c[ta][tb]++; d[ta][tb] = max(d[ta][tb], d[a][b] + 1LL * dg[b][tn] * dg[tn][b]);
			if (c[ta][tb] == 2) {
				q.push(make_pair(ta, tb));
				vs[ta][tb] = true;
			}
		}
		if (a == b) continue;
		for (int i = 0; i < v[b].size(); i++) {
			int tn = v[b][i], ta = tn, tb = a;
			if (ta > tb) swap(ta, tb);
			if (vs[ta][tb]) continue;
			c[ta][tb]++; d[ta][tb] = max(d[ta][tb], d[a][b] + 1LL * dg[a][tn] * dg[tn][a]);
			if (c[ta][tb] == 2) {
				q.push(make_pair(ta, tb));
				vs[ta][tb] = true;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}