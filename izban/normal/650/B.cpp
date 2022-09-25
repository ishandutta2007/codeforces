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

const int MAXN = 1 << 19;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n, a, b, T;
char s[MAXN];

int solve() {
	ll cur = 1;
	if (s[0] == 'w') cur += b;
	if (cur > T) return 0;

	int cj = n;

	while (1) {
		if (cj == 0) break;
		ll ntime = cur + a + 1;
		if (s[cj - 1] == 'w') ntime += b;
		if (ntime <= T) {
			cj--;
			cur = ntime;
		}
		else break;
	}

	int ans = min(n, 1 + (n - cj));
	for (int i = 1; i < n; i++) {
		cur += 2 * a + 1;
		if (s[i] == 'w') cur += b;
		while (cur > T && cj < n) {
			cur -= a + 1;
			if (s[cj] == 'w') cur -= b;
			cj++;
		}
		if (cur <= T) {
			ans = max(ans, min(n, i + 1 + n - cj));
		}
	}

	cur = 1;
	if (s[0] == 'w') cur += b;
	for (int i = 1; i < n; i++) {
		cur += a + 1;
		if (s[i] == 'w') cur += b;
		if (cur <= T) ans = max(ans, i + 1);
	}

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d%d%d\n", &n, &a, &b, &T) == 4) {
		scanf("%s\n", s);
		
		int ans = solve();
		if (n > 1) {
			reverse(s + 1, s + n);
			ans = max(ans, solve());
		}
		cout << ans << endl;
	}

	return 0;
}