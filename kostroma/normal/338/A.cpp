#pragma comment (linker, "/STACK:128000000")
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
//void precalc();
clock_t start;
//int timer = 1;
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cout.sync_with_stdio(0);
	//precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
    while (t--) {
        solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

#define int li

int mod = 1000000009;

int binpow (int q, int w) {
	if (!w)
		return 1;
	if (w & 1)
		return (q * binpow(q, w - 1)) % mod;
	return binpow((q * q) % mod, w / 2);
}

int n, m, k;

void solve() {
	cin >> n >> m >> k;

	int diff = n - m;
	int need = n / k;

	if (need <= diff) {
		cout << m % mod << "\n";
		return;
	}

	int rest = m - (k - 1) * diff;

	int now = rest / k;

	int ans = ((binpow(2, now + 1) - 2) * k) % mod + (rest % k) + ((k - 1) * diff) % mod;
	ans %= mod;

	cout << (ans + mod) % mod << "\n";

}