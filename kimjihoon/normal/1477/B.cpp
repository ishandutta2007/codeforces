#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

pair<int, int> p[200009];
priority_queue<int, vector<int>, greater<int> > pq;
int c[200009], st[800009], lz[800009];
vector<int> v[200009];
bool rp[200009], tp[200009][2];

void up_lazy(int tn, int s, int e)
{
	if (lz[tn] == -1) return;
	st[tn] = lz[tn] * (e - s + 1);
	if (s != e) {
		lz[tn * 2] = lz[tn];
		lz[tn * 2 + 1] = lz[tn];
	}
	lz[tn] = -1;
}

void update(int tn, int s, int e, int ts, int te, int w)
{
	up_lazy(tn, s, e);
	if (e < ts || te < s) return;
	if (ts <= s && e <= te) {
		lz[tn] = w;
		up_lazy(tn, s, e);
		return;
	}
	int md = (s + e) / 2;
	update(tn * 2, s, md, ts, te, w);
	update(tn * 2 + 1, md + 1, e, ts, te, w);
	st[tn] = st[tn * 2] + st[tn * 2 + 1];
}

int qry(int tn, int s, int e, int ts, int te)
{
	up_lazy(tn, s, e);
	if (e < ts || te < s) return 0;
	if (ts <= s && e <= te) return st[tn];
	int md = (s + e) / 2;
	return qry(tn * 2, s, md, ts, te) + qry(tn * 2 + 1, md + 1, e, ts, te);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, q; cin >> n >> q;
		string s, f; cin >> s >> f;
		for (int i = 0; i <= n + 1; i++) {
			c[i] = 0;
			v[i].clear();
		}
		for (int i = 0; i <= 4 * n; i++) {
			st[i] = 0;
			lz[i] = -1;
		}
		for (int i = 0; i < n; i++)
			if (f[i] == '1')
				update(1, 0, n - 1, i, i, 1);
		for (int i = 0; i <= q; i++) {
			rp[i] = false;
			tp[i][0] = tp[i][1] = false;
		}
		while (!pq.empty())
			pq.pop();
		for (int i = 1; i <= q; i++) {
			cin >> p[i].first >> p[i].second;
			p[i].first--; p[i].second--;
			v[p[i].first].push_back(i);
			v[p[i].second + 1].push_back(-i);
		}
		bool ff = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				int a = v[i][j];
				if (a > 0) {
					rp[a] = true;
					pq.push(a);
				}
				else
					rp[-a] = false;
			}
			while (!pq.empty() && !rp[pq.top()])
				pq.pop();
			if (!pq.empty())
				tp[pq.top()][s[i] - '0'] = true;
			if (pq.empty() && s[i] != f[i]) {
				ff = false;
				break;
			}
		}
		if (!ff) {
			cout << "NO" << '\n';
			continue;
		}
		for (int i = q; i >= 1; i--) {
			int sz = p[i].second - p[i].first + 1, c1 = qry(1, 0, n - 1, p[i].first, p[i].second), c0 = sz - c1;
			int cl = (sz - 1) / 2;
			//cout << p[i].first << " " << p[i].second << " " << sz << " " << c0 << " " << c1 << " " << tp[i][0] << " " << tp[i][1] << '\n';
			if ((tp[i][0] && c1 > cl) || (tp[i][1] && c0 > cl) || (c0 > cl && c1 > cl)) {
				ff = false;
				break;
			}
			if (tp[i][0]) update(1, 0, n - 1, p[i].first, p[i].second, 0);
			else if (tp[i][1]) update(1, 0, n - 1, p[i].first, p[i].second, 1);
			else if (c1 < c0) update(1, 0, n - 1, p[i].first, p[i].second, 0);
			else update(1, 0, n - 1, p[i].first, p[i].second, 1);
		}
		if (ff) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}