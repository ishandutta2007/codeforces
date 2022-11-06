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
	set<int> a, l;
	int t;
	scanf("%d", &t);
	a.insert(t);
	forn(i, 0, n - 1) {
		scanf("%d", &t);
		auto itl = a.upper_bound(t);
		auto itr = itl;
		--itl;
		if (itr != a.end() && l.find(*itr) == l.end()) {
			printf("%d ", (*itr));
			l.insert(*itr);
		} else {
			printf("%d ", (*itl));
			//r.insert(*itl);
		}
		a.insert(t);
	}
	return 0;
}