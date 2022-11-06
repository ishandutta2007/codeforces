#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

struct maxTree {
	vector<pair<int, int> > v;
	int sz;

	maxTree () {};

	maxTree (int n) {
		sz = 1;
		while (sz < n) sz *= 2;
		v.resize(2 * n);
	}

	maxTree (vector<pair<int, int> > &a) {
		sz = 1;
		while (sz < a.size()) sz *= 2;
		v.resize(2 * sz);
		for (int i = 0; i < a.size(); ++i)
			v[i + sz] = a[i];
		for (int i = sz - 1; i >= 1; --i) {
			v[i] = max(v[2 * i], v[2 * i + 1]);
		}
	}
	
	pair<int, int> get(int l, int r) {
		l += sz, r += sz;
		pair<int, int> ans = {-1, -1};
		while (l < r) {
			if (l % 2) {
				ans = max(ans, v[l]);
				++l;
			}
			if (r % 2) {
				--r;
				ans = max(ans, v[r]);
			}
			l /= 2;
			r /= 2;
		}
		return ans;
	}
};



const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int> > a(n);
	forn(i, 0, n - 1) scanf("%d", &a[i].fs);
	a[n - 1].fs = n;
	forn(i, 0, n) {
		--a[i].fs;
		a[i].sn = i;
	}
	maxTree T(a);
	vector<pair<int, int> > c(n);
	forn(i, 0, n) c[i] = T.get(i, a[i].fs + 1);
	vector<ll> ans(n);
	ford(i, 0, n) {
		if (c[i].sn != i) {
			ans[i] = (a[i].fs - i) + (ans[c[i].sn] - a[i].fs + c[i].sn) + (n - a[i].fs - 1);
		} else {
			assert(i == n - 1);
			ans[i] = 0;
		}
	}
	ll sum = 0;
	forn(i, 0, n) sum += ans[i];
	//printf("%lld\n", sum);
	printf("%I64d\n", sum);
	return 0;
}