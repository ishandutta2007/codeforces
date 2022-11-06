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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, p;
	cin >> n >> m >> p;
	string s, t;
	cin >>  s >> t;
	vector<int> b(n + 1), pr(n + 1), nx(n + 1);
	int bal = 0;
	forn(i, 0, n) {
		b[i] = bal;
		if (s[i] == '(') ++bal;
		else --bal;
	}
	b[n] = bal;

	fore(i, 0, n) {
		nx[i] = i + 1;
		pr[i] = i - 1;
	}
	int cur = p - 1;
	int st = 0;
	forn(i, 0, m) {
		if (t[i] == 'L') cur = pr[cur];
		else if (t[i] == 'R') cur = nx[cur];
		else {
			int l, r;
			if (s[cur] == '(') {
				l = cur;
				r = cur;
				do {
					r = nx[r];
				} while (b[r] != b[l]);
			} else {
				l = nx[cur];
				r = nx[cur];
				do {
					l = pr[l];
				} while (b[l] != b[r]);
			}
			//cerr << l << ' ' << r << '\n';
			if (pr[l] != -1) nx[pr[l]] = r;
			if (r <= n) pr[r] = pr[l];
			cur = r;
			if (cur == n) cur = pr[l];
			if (st == l) st = cur;
			//trace(pr);
			//trace(nx);
		}
	}
	while (st != n) {
		cout << s[st];
		st = nx[st];
	}
	return 0;
}