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
int l[100000];
int r[100000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
	}
	sort(l, l + n);
	sort(r, r + n);
	llong ans = n;
	for (int i = 0; i < n; ++i) {
        ans += max(l[i], r[i]);
	}
	printf("%lld\n", ans);
	return 0;
}