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

int n;
int a[100500];

bool good (int k) {
	int pref = 0;
	for (int i = 0; i < n; ++i) {
		pref += k - a[i];
	}
	return pref >= k;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	int l = a[n - 1] - 1, r = 1000000000000LL;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (good(m))
			r = m;
		else
			l = m;
	}

	cout << r << endl;
}