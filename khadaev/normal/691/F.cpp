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

const int N = 1000010;
const int MX = 3000010;
const int D = 70;

ll cnt[MX], res[MX], sum[MX]; 

int main() {
	int n;
	scanf("%d", &n);
	forn(i, 0, n) {
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	forn(i, 1, MX) for (int j = i, k = 1; j < MX; j += i, ++k) {
		if (i != k) res[j] += cnt[i] * cnt[k];
		else res[j] += cnt[i] * (cnt[i] - 1);
	}
	sum[0] = 0;
	forn(i, 1, MX) sum[i] = sum[i - 1] + res[i - 1];
	ll all = 1ll * n * (n - 1);
	int m;
	scanf("%d", &m);
	forn(i, 0, m) {
		int p;
		scanf("%d", &p);
		printf("%lld ", all - sum[p]);
	}
	return 0;
}