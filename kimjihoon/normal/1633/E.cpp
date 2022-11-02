#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge
{
	int a, b, w, i;
	bool operator<(const edge& r) const {
		return w < r.w;
	}
};

int n, m, rp[309], vs[309], ds[309];

struct pnt
{
	int a, b, p;
	bool operator<(const pnt& r) const {
		if (p != r.p) return p < r.p;
		if (rp[a] != rp[r.a]) return rp[a] < rp[r.a];
		return rp[b] > rp[r.b];
	}
	pnt() : a(0), b(0), p(0) {};
	pnt(int a, int b, int p) : a(a), b(b), p(p) {};
};

struct tp
{
	int p;
	long long a, b;
	bool operator<(const tp& r) const {
		return p < r.p;
	}
	tp() : p(0), a(0LL), b(0LL) {};
	tp(int p, long long a, long long b) : p(p), a(a), b(b) {};
};

vector<pnt> pv, tpv;
vector<tp> tv;
edge eg[309];
bool ff[309];

int uf(int n)
{
	if (n == ds[n]) return n;
	return ds[n] = uf(ds[n]);
}

tp ps()
{
	for (int i = 1; i <= n; i++)
		ds[i] = i;
	tp ans = tp(0, 0LL, 0LL);
	for (int i = 0; i < m; i++) {
		int a = uf(eg[i].a), b = uf(eg[i].b);
		if (a != b) {
			ds[a] = b;
			if (ff[eg[i].i]) {
				ans.a++;
				ans.b -= eg[i].w;
			}
			else {
				ans.a--;
				ans.b += eg[i].w;
			}
		}
	}
	return ans;
}

long long qry(long long q)
{
	auto p = upper_bound(tv.begin(), tv.end(), tp(q, 0LL, 0LL));
	p--;
	return ((p->a) * q + (p->b)) / 2LL;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> eg[i].a >> eg[i].b >> eg[i].w;
		eg[i].i = i;
		eg[i].w *= 2;
	}
	sort(eg, eg + m);
	tv.push_back(ps());
	tv.back().p = -1;
	for (int i = 0; i < m; i++) {
		rp[eg[i].i] = i;
		pv.push_back(pnt(eg[i].i, eg[i].i, eg[i].w));
		vs[eg[i].i] = -1;
	}
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++) {
			pv.push_back(pnt(eg[i].i, eg[j].i, (eg[i].w + eg[j].w) / 2));
		}
	sort(pv.begin(), pv.end());
	for (int i = 0; i < pv.size(); i++) {
		int a = pv[i].a, b = pv[i].b;
		if (rp[a] > rp[b]) {
			swap(pv[i].a, pv[i].b);
			swap(a, b);
		}
		if (a == b) 
			ff[a] = true;
		else
			tpv.push_back(pv[i]);
		if (i + 1 == pv.size() || pv[i].p != pv[i + 1].p) {
			sort(tpv.begin(), tpv.end());
			for (int j = 0; j < tpv.size(); j++) {
				int ta = tpv[j].a, tb = tpv[j].b;
				if (vs[ta] != pv[i].p && vs[tb] != pv[i].p) {
					vs[ta] = vs[tb] = pv[i].p;
					swap(eg[rp[ta]], eg[rp[tb]]);
					swap(rp[ta], rp[tb]);
				}
			}	
			tpv.clear();
			tv.push_back(ps());
			tv.back().p = pv[i].p;
		}
	}
	int p, k; cin >> p >> k;
	long long a, b, c; cin >> a >> b >> c;
	long long pr = 0, ans = 0;
	for (int i = 0; i < p; i++) {
		long long q; cin >> q;
		ans ^= qry(q * 2);
		pr = q;
	}
	for (int i = 0; i < k - p; i++) {
		long long q = (pr * a + b) % c;
		ans ^= qry(q * 2);
		pr = q;
	}
	cout << ans << '\n';
	return 0;
}