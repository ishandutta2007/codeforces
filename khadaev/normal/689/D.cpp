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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int mins(map<int, int> &m) {
	if (m.empty()) return INF;
	return m.begin()->first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	forn(i, 0, n) cin >> a[i];
	forn(i, 0, n) cin >> b[i];
	map<int, int> as, bs;
	int l = 0, r = 0;
	as[-a[0]] = 1;
	bs[b[0]] = 1;
	ll ans = 0;
	while (l < n) {
		while (r < n - 1 && -mins(as) < mins(bs)) {
			++r;
			as[-a[r]]++;
			bs[b[r]]++;
		}
		ans += r - l;
		//cerr << l << ' ' << r << ' ' << st << '\n';
		if (-mins(as) < mins(bs)) ++ans;
		as[-a[l]]--;
		if (as[-a[l]] == 0) as.erase(-a[l]);
		bs[b[l]]--;
		if (bs[b[l]] == 0) bs.erase(b[l]);
		++l;
	}
	as.clear();
	bs.clear();
	l = 0, r = 0;
	as[-a[0]] = 1;
	bs[b[0]] = 1;
	while (l < n) {
		while (r < n - 1 && -mins(as) <= mins(bs)) {
			++r;
			as[-a[r]]++;
			bs[b[r]]++;
		}
		ans -= r - l;
		//cerr << l << ' ' << r << ' ' << st << '\n';
		if (-mins(as) <= mins(bs)) --ans;
		as[-a[l]]--;
		if (as[-a[l]] == 0) as.erase(-a[l]);
		bs[b[l]]--;
		if (bs[b[l]] == 0) bs.erase(b[l]);
		++l;
	}
	cout << -ans << '\n';
	return 0;
}