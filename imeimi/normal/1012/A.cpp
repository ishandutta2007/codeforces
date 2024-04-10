#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
int a[200000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < (n << 1); ++i) {
        cin >> a[i];
	}
	sort(a, a + (n << 1));
	llong ans = (llong)(a[n - 1] - a[0]) * (a[(n << 1) - 1] - a[n]);
	for (int i = 1; i <= n; ++i) {
        ans = min(ans, (llong)(a[(n << 1) - 1] - a[0]) * (a[i + n - 1] - a[i]));
	}
	printf("%lld\n", ans);
	return 0;
}