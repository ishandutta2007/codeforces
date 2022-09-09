#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
//#define FILENAME "1dembedding"
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cin >> t;
    while (t--)
        solve();
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

#define int li

int n, l, r, ql, qr;
int w[100500];
int pref[100500];

int sum(int l, int r) { return pref[r + 1] - pref[l]; }

void solve() {
	cin >> n >> l >> r >> ql >> qr;
	pref[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		pref[i + 1] = pref[i] + w[i];
	}
	int ans = 1e18;
	for (int border = 0; border <= n; ++border) {
		int res = 0;
		int a = border, b = n - border;
		if (a > b)
			res = (a - b - 1) * ql;
		if (a < b)
			res = (b - a - 1) * qr;
		res += l * sum(0, border - 1) + r * sum(border, n - 1);
		ans = min(ans, res);
	}
	cout << ans;

}