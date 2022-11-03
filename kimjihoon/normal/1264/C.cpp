#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

int md = 998244353;

struct fn
{
	int a, b;
	fn() : a(0), b(1) {};
	fn(int a, int b) : a(a), b(b) {};
	fn operator*(const fn &r) const {
		return fn((1LL * a * r.a) % md, (1LL * b * r.b) % md);
	}
	fn operator/(const fn &r) const {
		return fn((1LL * a * r.b) % md, (1LL * b * r.a) % md);
	}
	fn operator+(const fn &r) const {
		return fn((1LL * a * r.b + 1LL * r.a * b) % md, (1LL * b * r.b) % md);
	}
	fn operator-(const fn &r) const {
		return fn((((1LL * a * r.b - 1LL * r.a * b) % md) + md) % md, (1LL * b * r.b) % md);
	}
};

int a[200009];
bool p[200009];
fn ft[200009], fs[200009], pv[200009];
set<int> st;

fn qry(int s, int e)
{
	return ((fs[e] - fs[s - 1] - fn(e - s + 2, 1) * ft[e]) / ft[s - 1] + fn(1, 1)) / (ft[e] / ft[s - 1]) + fn(e - s + 1, 1);
}

int ep(int n, int r)
{
	int s = 1;
	while (r) {
		if (r % 2) s = (1LL * s * n) % md;
		r /= 2; n = (1LL * n * n) % md;
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	ft[0] = fn(1, 1); fs[0] = fn();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ft[i] = ft[i - 1] * fn(a[i], 100);
		fs[i] = fs[i - 1] + ft[i];
	}
	st.insert(1); st.insert(n + 1);
	p[1] = true;
	pv[1] = qry(1, n);  fn ans = pv[1];
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (p[t]) {
			p[t] = false; st.erase(t);
			auto pt = st.lower_bound(t);
			int r = (*pt) - 1; pt--; int l = (*pt);
			ans = ans - pv[l] - pv[t];
			pv[l] = qry(l, r); ans = ans + pv[l];
		}
		else {
			p[t] = true;
			auto pt = st.lower_bound(t);
			int r = (*pt) - 1; pt--; int l = (*pt);
			st.insert(t);
			ans = ans - pv[l];
			pv[l] = qry(l, t - 1); pv[t] = qry(t, r);
			ans = ans + pv[l] + pv[t];
		}
		cout << (1LL * ep(ans.b, md - 2) * ans.a) % md << '\n';
	}
	return 0;
}