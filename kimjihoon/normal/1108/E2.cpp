#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ls
{
	int s, e, i;
	ls(int s, int e, int i) : s(s), e(e), i(i) {};
	ls() : s(0), e(0), i(0) {};
};

vector<ls> sv[100009], ev[100009];
vector<int> rv;
int st[400009], lz[400009];

void up_lazy(int hn, int s, int e)
{
	if (lz[hn] != 0) {
		st[hn] += lz[hn];
		if (s != e) {
			lz[hn * 2] += lz[hn];
			lz[hn * 2 + 1] += lz[hn];
		}
		lz[hn] = 0;
	}
}

void update(int hn, int s, int e, int ts, int te, int w)
{
	up_lazy(hn, s, e);
	if (e < ts || te < s) return;
	if (ts <= s && e <= te) {
		st[hn] += w;
		if (s != e) {
			lz[hn * 2] += w;
			lz[hn * 2 + 1] += w;
		}
		return;
	}
	int md = (s + e) / 2;
	update(hn * 2, s, md, ts, te, w); update(hn * 2 + 1, md + 1, e, ts, te, w);
	st[hn] = max(st[hn * 2], st[hn * 2 + 1]);
}

int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(1, 1, n, i, i, a[i]);
	}
	for (int i = 1; i <= m; i++) {
		int l, r; cin >> l >> r;
		sv[l].push_back(ls(l, r, i));
		ev[r + 1].push_back(ls(l, r, i));
	}
	int ans = 0, ai = 0, c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sv[i].size(); j++) {
			update(1, 1, n, sv[i][j].s, sv[i][j].e, -1);
			c++;
		}
		for (int j = 0; j < ev[i].size(); j++) {
			update(1, 1, n, ev[i][j].s, ev[i][j].e, 1);
			c--;
		}
		int t = st[1] - (a[i] - c);
		if (ans < t) {
			ans = t;
			ai = i;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < sv[i].size(); j++)
			if (sv[i][j].s <= ai && ai <= sv[i][j].e)
				rv.push_back(sv[i][j].i);
	cout << ans << '\n';
	cout << rv.size() << '\n';
	for (int i = 0; i < rv.size(); i++)
		cout << rv[i] << " ";
	cout << '\n';
	return 0;
}