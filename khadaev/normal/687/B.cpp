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

const int MAXC = 1000010;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> c(n);
	forn(i, 0, n) scanf("%d", &c[i]);
	vector<int> p(MAXC);
	forn(i, 0, MAXC) p[i] = i;
	vector<int> primes;
	forn(i, 2, MAXC) {
		if (p[i] == i) primes.eb(i);
		for (int j : primes) {
			if (j > p[i] || 1ll * i * j >= MAXC) break;
			p[i * j] = j;
		}
	}
	map<int, int> lcm;
	forn(i, 0, n) {
		map<int, int> loc;
		int x = c[i];
		while (x > 1) {
			loc[p[x]]++;
			x /= p[x];
		}
		for (auto p : loc) lcm[p.fs] = max(lcm[p.fs], p.sn);
	}
	map<int, int> kdiv;
	while (k > 1) {
		kdiv[p[k]]++;
		k /= p[k];
	}
	for (auto p : kdiv)
		if (lcm[p.fs] < p.sn) {
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	return 0;
}