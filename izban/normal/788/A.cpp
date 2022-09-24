#include <unordered_map>
#include <unordered_set>
#include <functional>
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

const int MAXK = -1;
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

const ll INF = 1e18;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);

		vector<int> b(n - 1);
		for (int i = 0; i < n - 1; i++) b[i] = abs(a[i] - a[i + 1]);
		n--;

		ll ans = -INF;
		ll min0 = 0;
		ll min1 = -INF;
		ll cur = 0;
		for (int i = 0; i < n; i++) {
			cur += b[i] * (i % 2 ? -1 : 1);

			ans = max(ans, cur - min0);
			ans = max(ans, -(cur - min1));
			if (i % 2 == 0) min1 = max(min1, cur);
			else min0 = min(min0, cur);
		}
		cout << ans << endl;
	}

	return 0;
}