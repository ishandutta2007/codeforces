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

void fail() {
    printf("-1\n");
    exit(0);
}

int main() {
    int n, d, h;
    scanf("%d%d%d", &n, &d, &h);
    if (n > 2 && d == 1) fail();
    if (d == 1) {
        printf("1 2\n");
        return 0;
    }
    if (h == 1) {
        if (d > 2) fail();
        for (int i = 2; i <= n; ++i) {
            printf("1 %d\n", i);
        }
        return 0;
    }
    if (2 * h < d) fail();
    for (int i = 2; i <= h + 1; ++i) {
        printf("%d %d\n", i - 1, i);
    }
    if (h + 2 <= d + 1) printf("%d %d\n", 1, h + 2);
    for (int i = h + 3; i <= d + 1; ++i) {
        printf("%d %d\n", i - 1, i);
    }
    for (int i = d + 2; i <= n; ++i) {
        printf("%d %d\n", h, i);
    }
	return 0;
}