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

//#define int li

int n, m;
int a[1000], b[1000];

void solve() {
	cin >> n >> m;
	int mn = 1000000000, mx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	mn *= 2;
	mx = max(mx, mn);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		if (b[i] <= mx) {
			cout << -1;
			return;
		}
	}
	cout << mx;

}