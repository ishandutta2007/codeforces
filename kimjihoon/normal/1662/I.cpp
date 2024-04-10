#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pnt
{
	long long x;
	int t, i;
	bool operator<(const pnt& r) const {
		if (x != r.x) return x < r.x;
		return t > r.t;
	}
	pnt(long long x, int t, int i) : x(x), t(t), i(i) {};
	pnt() : x(0LL), t(0), i(0) {};
};

vector<pnt> v, rv;
long long p[200009], l[200009], r[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		v.push_back(pnt(1LL * (i - 1) * 200, 0, i));
	}
	for (int i = 1; i <= m; i++) {
		long long x; cin >> x; x *= 2;
		v.push_back(pnt(x, 1, i));
	}
	sort(v.begin(), v.end());
	long long pr = -1;
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].t) l[v[i].i] = pr;
		else pr = v[i].x;
	}
	pr = -1;
	for (int i = (int)v.size() - 1; i >= 0; i--) {
		if (!v[i].t) r[v[i].i] = pr;
		else pr = v[i].x;
	}
	for (int i = 1; i <= n; i++) {
		long long pl = 0, pr = 0, xx = 1LL * (i - 1) * 200;
		if (l[i] == -1) {
			pr = r[i];
			pl = xx - (r[i] - xx);
		}
		else if (r[i] == -1) {
			pl = l[i];
			pr = xx + (xx - l[i]);
		}
		else {
			pl = max(xx - (r[i] - xx), l[i]);
			pr = min(xx + (xx - l[i]), r[i]);
		}
		if (pl < pr) {
			rv.push_back(pnt(pl, 0, i));
			rv.push_back(pnt(pr, 1, i));
		}
	}
	sort(rv.begin(), rv.end());
	long long ans = 0, ss = 0;
	for (int i = 0; i < rv.size(); i++) {
		if (!rv[i].t) ss += p[rv[i].i];
		else ss -= p[rv[i].i];
		if (i + 1 != (int)rv.size() && rv[i].x == rv[i + 1].x && rv[i + 1].t) continue;
		ans = max(ans, ss);
	}
	cout << ans << '\n';
	return 0;
}