#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const int INF = 2e9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);

		int ans = 0;

		vector<int> b(n, INF);

		int mx = -1;
		for (int i = 0; i < n; i++) {
			mx = max(mx, i - a[i]);
			b[i] = min(b[i], i - mx);
		}

		int mn = n;
		for (int i = n - 1; i >= 0; i--) {
			mn = min(mn, i + a[i]);
			b[i] = min(b[i], mn - i);
		}

		for (int i = 0; i < n; i++) ans = max(ans, b[i]);

		cout << ans << endl;
	}

	return 0;
}