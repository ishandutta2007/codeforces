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

const int N = 512;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<bitset<N> > a(k + 1);
	a[0][0] = 1;
	forn(i, 0, n) {
		int c;
		cin >> c;
		ford(i, c, k + 1) {
			a[i] |= a[i - c];
			a[i] |= a[i - c] << c;
		}
	}
	vector<int> ans;
	forn(i, 0, N) if (a[k][i]) ans.eb(i);
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << ' ';
	return 0;
}