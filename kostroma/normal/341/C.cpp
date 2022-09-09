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
#ifdef room210
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

int mod = 1000000007;
int n;
int a[100500];
int have[100500];

int fact[100500];

int c[2005][2005];

void solve() {
	fact[0] = 1;
	for (int i = 1; i < 100500; ++i)
		fact[i] = (fact[i - 1] * i) % mod;
	c[0][0] = 1;
	for (int i = 0; i < 2005; ++i) {
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == -1) {
			++cnt;
			continue;
		}
		--a[i];
		have[a[i]] = 1;
	}
	int b = 0;
	for (int i = 0; i < n; ++i) {
		if (!have[i] && a[i] == -1)
			++b;
	}
	int res = 0;
	for (int i = 0; i <= b; ++i) {
		if ((i & 1) == 0)
			res += c[b][i] * fact[cnt - i];
		else
			res -= c[b][i] * fact[cnt - i];
		//cout << res << endl;
		res %= mod;
	}
	cout << (res + mod) % mod;
}