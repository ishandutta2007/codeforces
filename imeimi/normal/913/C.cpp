#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

llong c[30];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, cost;
	cin >> n >> cost;
	for (int i = 0; i < n; ++i) cin >> c[i];
	for (int i = n; i < 30; ++i) c[i] = 4e18;
	for (int i = 1; i < 30; ++i) {
		c[i] = min(c[i], c[i - 1] << 1);
	}
	for (int i = 30; --i;) c[i - 1] = min(c[i - 1], c[i]);

	llong ans = 4e18, sum = 0;
	for (int i = 30; i--;) {
		if ((cost >> i) & 1) sum += c[i];
		ans = min(ans, ((cost & ((1 << i) - 1)) == 0) ? sum : sum + c[i]);
	}
	printf("%lld\n", ans);

	return 0;
}