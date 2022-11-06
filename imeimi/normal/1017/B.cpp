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
char a[100001];
char b[100001];
int cnt[4];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
        ++cnt[(a[i] - '0') << 1 | (b[i] - '0')];
	}
	llong ans = (llong)cnt[0] * (cnt[2] + cnt[3]);
	ans += (llong)cnt[1] * cnt[2];
	printf("%lld\n", ans);
	return 0;
}