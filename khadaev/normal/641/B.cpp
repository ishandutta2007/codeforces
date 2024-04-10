#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int ans[100][100];
const int N = 10010;
int t[N], a[N], b[N], c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	forn(i, 0, q) {
		cin >> t[i];
		if (t[i] == 3) {
			cin >> a[i] >> b[i] >> c[i];
			--a[i];
			--b[i];
		} else {
			cin >> a[i];
			--a[i];
		}
	}
	for (int i = q - 1; i >= 0; --i) {
		if (t[i] == 3) ans[a[i]][b[i]] = c[i];
		if (t[i] == 1) {
			int tmp = ans[a[i]][m - 1];
			for(int j = m - 2; j >= 0; --j) {
				ans[a[i]][j + 1] = ans[a[i]][j];
			}
			ans[a[i]][0] = tmp;
		}
		if (t[i] == 2) {
			int tmp = ans[n - 1][a[i]];
			for (int j = n - 2; j >= 0; --j) {
				ans[j + 1][a[i]] = ans[j][a[i]];
			}
			ans[0][a[i]] = tmp;
		}
	}
	forn(i, 0, n){
		forn(j, 0, m) cout << ans[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}