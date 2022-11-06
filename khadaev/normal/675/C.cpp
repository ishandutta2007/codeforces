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
	int n;
	scanf("%d", &n);
	map<ll, int> a;
	ll s = 0;
	int t;
	forn(i, 0, n) {
		a[s]++;
		scanf("%d", &t);
		s += t;
	}
	int mx = 0;
	for (auto p : a) mx = max(mx, p.sn);
	printf("%d\n", n - mx);
	return 0;
}