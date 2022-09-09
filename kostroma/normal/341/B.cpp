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

//#define int li

int n;
int a[100500];
int e[100500];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	e[0] = 0;
	for (int i = 1; i <= n + 1; ++i)
		e[i] = 1000000000;
	for (int i = 0; i < n; ++i) {
		int id = lower_bound(e, e + n + 1, a[i]) - e;
		//cout << "id = " << id << endl;
		e[id] = a[i];
	}
	int mx = 0;
	for (int i = 1; i <= n; ++i)
		if (e[i] != 1000000000)
			mx = max(mx, i);
	cout << mx;
}