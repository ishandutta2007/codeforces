#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 21;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> m) {
		for (int i = 0; i < m; i++) scanf("%d", &a[i]);
		sort(a, a + m);
		n = 0;
		int M = m;
		while (M) {
			M /= 4;
			n++;
		}

		ll ans = 1LL * a[m - 1] * n;
		n--;
		int cur = 1;
		for (int i = m - 2; i >= 0; ) {
			for (int j = 0; j < 3 * cur; j++, i--) {
				ans += 1LL * a[i] * n;
			}
			cur *= 4; n--;
		}
		cout << ans << endl;
	}

	return 0;
}