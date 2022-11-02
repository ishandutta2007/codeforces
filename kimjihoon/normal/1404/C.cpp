#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int n, st[1200009], si[1200009], lz[1200009], ft[300009], ans[300009], inf = 1000000000;
int a[300009];
vector<pair<int, int> > qr[300009];

void init(int tn, int s, int e)
{
	if (s == e) {
		si[tn] = s;
		st[tn] = a[s];
		return;
	}
	int md = (s + e) / 2;
	init(tn * 2, s, md); init(tn * 2 + 1, md + 1, e);
	if (st[tn * 2] < st[tn * 2 + 1]) {
		st[tn] = st[tn * 2];
		si[tn] = si[tn * 2];
	}
	else {
		st[tn] = st[tn * 2 + 1];
		si[tn] = si[tn * 2 + 1];
	}
}

void ulz(int tn, int s, int e)
{
	if (!lz[tn]) return;
	st[tn] += lz[tn];
	if (s != e) {
		lz[tn * 2] += lz[tn];
		lz[tn * 2 + 1] += lz[tn];
	}
	lz[tn] = 0;
}

void up(int tn, int s, int e, int ts, int te, int w)
{
	ulz(tn, s, e);
	if (ts > e || s > te) return;
	if (ts <= s && e <= te) {
		lz[tn] += w;
		ulz(tn, s, e);
		return;
	}
	int md = (s + e) / 2;
	up(tn * 2, s, md, ts, te, w);
	up(tn * 2 + 1, md + 1, e, ts, te, w);
	if (st[tn * 2] < st[tn * 2 + 1]) {
		st[tn] = st[tn * 2];
		si[tn] = si[tn * 2];
	}
	else {
		st[tn] = st[tn * 2 + 1];
		si[tn] = si[tn * 2 + 1];
	}
}

int qry(int tn, int s, int e, int ts, int te)
{
	ulz(tn, s, e);
	if (ts > e || s > te) return 0;
	if (ts <= s && e <= te) return tn;
	int md = (s + e) / 2;
	int p0 = qry(tn * 2, s, md, ts, te), p1 = qry(tn * 2 + 1, md + 1, e, ts, te);
	if (st[p0] < st[p1]) return p0;
	return p1;
}

void fup(int i, int w)
{
	while (i <= n) {
		ft[i] += w;
		i += (i & (-i));
	}
}

int qryf(int i)
{
	int s = 0;
	while (i) {
		s += ft[i];
		i -= (i & (-i));
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] = i - a[i];
		if (a[i] < 0) a[i] = inf;
	}
	init(1, 1, n); st[0] = inf * 2;
	for (int i = 0; i < q; i++) {
		int x, y; cin >> x >> y;
		qr[x + 1].push_back(make_pair(y, i));
	}
	for (int i = n; i >= 1; i--) {
		while (true) {
			int tn = qry(1, 1, n, i, n);
			if (st[tn] != 0) break;
			int pn = si[tn];
			up(1, 1, n, pn, pn, inf);
			fup(pn, 1);
			up(1, 1, n, pn, n, -1);
		}
		for (int j = 0; j < qr[i].size(); j++) 
			ans[qr[i][j].second] = qryf(n - qr[i][j].first);
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}