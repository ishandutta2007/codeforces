#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

void fail() {
	printf("-1\n");
	exit(0);
}

int n;
int up[300000];
int dn[300000];
int mx[300000];
int mn[300000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int s, g;
	for (int i = 0; i < n; ++i) {
		cin >> s >> g;
		up[i] = s + g;
		dn[i] = s;
	}

	int MM = 1e9, mm = -1;
	for (int i = 0; i < n; ++i) {
		++MM, --mm;
		MM = min(MM, up[i]);
		mm = max(mm, dn[i]);
		mx[i] = MM;
		mn[i] = mm;
	}

	for (int i = n; i--;) {
		++MM, --mm;
		MM = min(MM, up[i]);
		mm = max(mm, dn[i]);
		mx[i] = min(MM, mx[i]);
		mn[i] = max(mm, mn[i]);
	}

	llong ans = 0;
	for (int i = 0; i < n; ++i) {
		if (mx[i] < mn[i]) fail();
		ans += mx[i] - dn[i];
	}
	printf("%lld\n", ans);
	for (int i = 0; i < n; ++i) printf("%d ", mx[i]);

	return 0;
}