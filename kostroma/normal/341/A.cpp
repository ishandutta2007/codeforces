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

int n;
int a[100500];

int gcd (int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = 0;
	for (int i = 1; i < n; ++i) {
		sum += (n - i) * (2 * i + 1) * (a[i + 1] - a[i]);
	}
	sum += a[1] * n;
	int g = gcd(sum, n);
	cout << sum / g << ' ' << n / g << endl;
}