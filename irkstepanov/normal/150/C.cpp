#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double ld;

/*struct node
{
	ld sum;
	ld maxx;
	ld promise;
	node() : sum(0), maxx(0), promise(0) {}
};

vector<node> t;

void push(int v, int tl, int tr)
{
	int tm = (tl + tr) >> 1;
	t[v * 2].sum += t[v].promise * ld(tm - tl + 1);
	t[v * 2].maxx += t[v].promise;
	t[v * 2].promise += t[v].promise;
	t[v * 2 + 1].sum += t[v].promise * ld(tr - tm);
	t[v * 2 + 1].maxx += t[v].promise;
	t[v * 2 + 1].promise += t[v].promise;
	t[v].promise = 0;
}

void update(int v, int tl, int tr, int l, int r, ld val)
{
	if (tl == l && tr == r) {
		t[v].promise += val;
		t[v].maxx += val;
		t[v].sum += val * ld(tr - tl + 1);
		return;
	}
	int tm = (tl + tr) >> 1;
	push(v, tl, tr);
	if (l <= tm) {
		update(v * 2, tl, tm, l, min(r, tm), val);
	}
	if (r > tm) {
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
	t[v].maxx = max(t[v * 2].maxx, t[v * 2 + 1].maxx);
	t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
}

ld get(int v, int tl, int tr, int l, int r)
{
	if (tl == l && tr == r) {
		return t[v].maxx;
	}
	int tm = (tl + tr) >> 1;
	push(v, tl, tr);
	ld ans = 0;
	if (l <= tm) {
		ans = max(ans, get(v * 2, tl, tm, l, min(r, tm)));
	}
	if (r > tm) {
		ans = max(ans, get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}
	return ans;
}*/

struct node
{
	ld best;
	ld pref;
	ld suff;
	ld total = 0;
	node() : best(0), pref(0), suff(0), total(0) {}
};

vector<node> t;

void build(int v, int tl, int tr, vector<ld>& a)
{
	if (tl == tr) {
		t[v].best = max(0.0, a[tl]);
		t[v].pref = max(0.0, a[tl]);
		t[v].suff = max(0.0, a[tl]);
		t[v].total = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm, a);
	build(v * 2 + 1, tm + 1, tr, a);
	t[v].total = t[v * 2].total + t[v * 2 + 1].total;
	t[v].pref = max(t[v * 2].pref, t[v * 2].total + t[v * 2 + 1].pref);
	t[v].suff = max(t[v * 2 + 1].suff, t[v * 2 + 1].total + t[v * 2].suff);
	t[v].best = max(t[v * 2].best, max(t[v * 2 + 1].best, t[v * 2].suff + t[v * 2 + 1].pref));
}

node get(int v, int tl, int tr, int l, int r)
{
	if (tl == l && tr == r) {
		return t[v];
	}
	int tm = (tl + tr) >> 1;
	if (r <= tm) {
		return get(v * 2, tl, tm, l, r);
	}
	if (l > tm) {
		return get(v * 2 + 1, tm + 1, tr, l, r);
	}
	node x = get(v * 2, tl, tm, l, tm);
	node y = get(v * 2 + 1, tm + 1, tr, tm + 1, r);
	node ans;
	ans.total = x.total + y.total;
	ans.pref = max(x.pref, x.total + y.pref);
	ans.suff = max(y.suff, y.total + x.suff);
	ans.best = max(x.best, max(y.best, x.suff + y.pref));
	return ans;
}

int main()
{

	//ifstream cin("input.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	ld c;
	cin >> n >> m >> c;

	vector<ld> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	vector<ld> p(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> p[i];
		p[i] /= 100.0;
	}

	vector<ld> cost(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cost[i] = 0.5 * (x[i + 1] - x[i]) - p[i] * c;
	}

	t.resize(4 * (n - 1));
	build(1, 0, n - 2, cost);

	ld ans = 0;

	while (m--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		--r;
		ans += get(1, 0, n - 2, l, r).best;
	}

	cout << fixed;
	cout.precision(12);
	cout << ans << '\n';

	/*vector<int> cnt(n - 1);
	while (m--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		++cnt[l];
		--cnt[r];
	}

	for (int i = 1; i < n - 1; ++i) {
		cnt[i] += cnt[i - 1];
	}*/

	// cnt[i] -- the number of people crossing i-th segment

	/*for (int i = 0; i < n - 1; ++i) {
		cout << cnt[i] << "\n";
	}*/

	/*for (int i = 0; i < n - 1; ++i) {
		//cout << x[i] << " " << x[i + 1] << " " << p[i] << " " << cnt[i] << "\n";
		ld val = 0.5 * (x[i + 1] - x[i]) * ld(cnt[i]) - p[i] * c * ld(cnt[i]);
		cout << i << " " << val << "\n";
	}

	ld ans = 0;

	for (int lf = 0; lf < n; ++lf) {
		for (int rg = lf; rg < n; ++rg) {
			ld curr = 0;
			for (int i = lf; i < rg; ++i) {
				ld val = 0.5 * (x[i + 1] - x[i]) * ld(cnt[i]) - p[i] * c * ld(cnt[i]);
				curr += val;
			}
			ans = max(ans, curr);
		}
	}

	cout << ans << "\n";*/

	/*t = vector<node>(4 * (n - 1));
	ld ans = 0;

	vector<ld> pro;

	for (int i = n - 2; i >= 0; --i) {
		ld profit = ld(cnt[i]) * ((x[i + 1] - x[i]) / 2.0 - p[i] * c);
		pro.pb(profit);
		//cout << i << " " << profit << "\n";
		ans = max(ans, profit + get(1, 0, n - 2, i, n - 2));
		update(1, 0, n - 2, i, n - 2, profit);
	}

	reverse(all(pro));

	ld sum = 0;
	for (int i = 0; i < sz(pro); ++i) {
		for (int j = i; j < sz(pro); ++j) {
			ld val = 0;
			for (int k = i; k <= j; ++k) {
				val += pro[k];
			}
			sum = max(sum, val);
		}
	}

	cout << fixed;
	cout.precision(12);
	cout << ans << '\n';
	cout << sum << "\n";*/

}