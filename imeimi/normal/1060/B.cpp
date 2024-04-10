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

llong ten[100];

int get(llong n, int bit) {
    int ret = 0;
    for (int i = 0; i < 13; ++i) {
        if ((bit >> i) & 1) n -= ten[i + 1], ret += 10;
    }
    if (n < 0) return 0;
    for (int i = 0; i < 13; ++i) {
        if ((bit >> i) & 1) {
            llong x = n % ten[i + 1] / ten[i];
            if (x > 8) return 0;
            n -= ten[i] * x;
            ret += x;
        }
        else {
            llong x = n % ten[i + 1] / ten[i];
            n -= ten[i] * x;
            ret += x;
        }
    }
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	llong n;
	cin >> n;
	ten[0] = 1;
	for (int i = 1; i < 100; ++i) ten[i] = ten[i - 1] * 10;
	int ans = 0;
	for (int i = 0; i < (1 << 13); ++i) ans = max(ans, get(n, i));
	printf("%d\n", ans);
	return 0;
}