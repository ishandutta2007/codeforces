#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define fs first
#define sn second

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

const int MAXN = 1000000 + 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	forn(i, 0, n) cin >> a[i];
	vector<int> vals(m + 1), lcm(m + 1);
	forn(i, 0, n)
		if (a[i] <= m)
			vals[a[i]]++;
	fore(i, 1, m) {
		for (int j = 1; i * j <= m; ++j)
			lcm[i * j] += vals[i];
	}
	int maxv = -1, ans;
	fore(i, 1, m)
		if (lcm[i] > maxv) {
			maxv = lcm[i];
			ans = i;
		}
	int size = 0;
	forn(i, 0, n)
		if (ans % a[i] == 0)
			++size;
	cout << ans << ' ' << size << '\n';
	forn(i, 0, n)
		if (ans % a[i] == 0)
			cout << i + 1 << ' ';
	return 0;
}