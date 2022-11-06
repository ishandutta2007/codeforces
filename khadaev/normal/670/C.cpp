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
	int n;
	cin >> n;
	map<int, int> l;
	forn(i, 0, n) {
		int t;
		cin >> t;
		l[t]++;
	}
	int m;
	cin >> m;
	vector<int> b(m), c(m);
	forn(i, 0, m) cin >> b[i];
	forn(i, 0, m) cin >> c[i];
	int m1 = -1, m2 = -1, opt = -1;
	forn(i, 0, m) {
		if (l[b[i]] > m1 || l[b[i]] == m1 && l[c[i]] > m2) {
			m1 = l[b[i]];
			m2 = l[c[i]];
			opt = i;
		} 
	}
	cout << opt + 1 << '\n';
	return 0;
}