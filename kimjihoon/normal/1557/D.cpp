#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<pair<int, int> > v[300009];
vector<int> pv;
map<int, int> mp;

int st[2400009], lz[2400009], lzn[2400009], pp[2400009], r[300009], pn;

void lazy(int tn, int s, int e)
{
	if (!lz[tn]) return;
	if (s != e) {
		if (lz[tn * 2] < lz[tn]) {
			lz[tn * 2] = lz[tn];
			lzn[tn * 2] = lzn[tn];
		}
		if (lz[tn * 2 + 1] < lz[tn]) {
			lz[tn * 2 + 1] = lz[tn];
			lzn[tn * 2 + 1] = lzn[tn];
		}
	}
	if (st[tn] < lz[tn]) {
		st[tn] = lz[tn];
		pp[tn] = lzn[tn];
	}
	lz[tn] = 0; lzn[tn] = 0;
	return;
}

void update(int tn, int s, int e, int ts, int te, int w)
{
	lazy(tn, s, e);
	if (e < ts || te < s) return;
	if (ts <= s && e <= te) {
		lz[tn] = w; lzn[tn] = pn;
		lazy(tn, s, e);
		return;
	}
	int md = (s + e) / 2;
	update(tn * 2, s, md, ts, te, w);
	update(tn * 2 + 1, md + 1, e, ts, te, w);
	if (st[tn * 2] > st[tn * 2 + 1]) {
		st[tn] = st[tn * 2];
		pp[tn] = pp[tn * 2];
	}
	else {
		st[tn] = st[tn * 2 + 1];
		pp[tn] = pp[tn * 2 + 1];
	}
}

pair<int, int> qry(int tn, int s, int e, int ts, int te)
{
	lazy(tn, s, e);
	if (e < ts || te < s) return make_pair(0, 0);
	if (ts <= s && e <= te) return make_pair(st[tn], pp[tn]);
	int md = (s + e) / 2;
	pair<int, int> a = qry(tn * 2, s, md, ts, te), b = qry(tn * 2 + 1, md + 1, e, ts, te);
	if (a.first > b.first) return a;
	return b;
}

bool vs[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p, a, b; cin >> p >> a >> b;
		v[p].push_back(make_pair(a, b));
		pv.push_back(a); pv.push_back(b);
	}
	sort(pv.begin(), pv.end());
	int c = 0;
	for (int i = 0; i < pv.size(); i++) {
		if (!i || pv[i] != pv[i - 1]) {
			c++;
			mp[pv[i]] = c;
		}
	}
	int ans = 1, ap = 1;
	for (int i = 1; i <= n; i++) {
		int mx = 1;
		r[i] = 0; pn = i;
		for (int j = 0; j < v[i].size(); j++) {
			v[i][j].first = mp[v[i][j].first];
			v[i][j].second = mp[v[i][j].second];
			int a = v[i][j].first, b = v[i][j].second;
			pair<int, int> t = qry(1, 1, c, a, b);
			if (mx < t.first + 1) {
				mx = t.first + 1;
				r[i] = t.second;
			}
		}
		for (int j = 0; j < v[i].size(); j++) {
			int a = v[i][j].first, b = v[i][j].second;
			update(1, 1, c, a, b, mx);
		}
		if (ans < mx) {
			ans = mx; ap = i;
		}
	}
	while (ap) {
		vs[ap] = true;
		ap = r[ap];
	}
	cout << n - ans << '\n';
	for (int i = 1; i <= n; i++)
		if (!vs[i])
			cout << i << " ";
	cout << '\n';
	return 0;
}