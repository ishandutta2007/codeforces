#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long llong;

int n;
const int range = 1e6;
llong x, y;
int cnt[range + 1];
llong sum[range + 1];
bool prime[range + 1];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x >> y;
	int i, j;
	for (i = 0; i < n; ++i) {
		cin >> j;
		++cnt[j];
		sum[j] += j;
	}
	for (i = 2; i <= range; ++i) {
		cnt[i] += cnt[i - 1];
		sum[i] += sum[i - 1];
	}
	llong ans = 1e18;
	for (i = 2; i <= range; ++i) {
		if (prime[i]) continue;
		for (llong k = (llong)i * i; k <= 1e6; k += i) prime[k] = true;
		llong cost = 0;
		for (int j = 0; j < range; j += i) {
			int m = min(max(i - x / y, 1ll) + j, range + 1ll);
			cost += x * (cnt[m - 1] - cnt[j]);
			cost += y * ((llong)(cnt[min(j + i, range)] - cnt[m - 1]) * (j + i) - (sum[min(j + i, range)] - sum[m - 1]));
		}
		ans = min(cost, ans);
	}
	printf("%lld\n", ans);
	return 0;
}