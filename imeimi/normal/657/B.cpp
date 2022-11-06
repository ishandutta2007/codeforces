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

const int inf = 1e6;
int n, k;
int a[200050];
int b[200050];

void imeassert(int i) {
    if (i) return;
    while (1) {
        i /= i;
    }
}

pii getB() {
    int mn = -1, mx = -1;
    llong j = 0;
    for (int i = 0; i <= n || j != 0; ++i) {
        j += a[i];
        b[i] = j & 1;
        imeassert(b[i] == 0 || b[i] == 1);
        if (b[i]) {
            mx = i;
            if (mn == -1) mn = i;
        }
        j >>= 1;
        if (i > n && j < 0) {
            mx = -1;
            break;
        }
    }
    return pii(mn, mx);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; ++i) {
        scanf("%d", a + i);
    }
    
    int mx, mn;
    tie(mn, mx) = getB();
    if (mx == -1) {
        for (int i = 0; i <= n; ++i) a[i] = -a[i];
        tie(mn, mx) = getB();
    }
    
    if (mx - mn > 40) {
        printf("0\n");
        return 0;
    }
    llong x = 0;
    int t = max(mx - 50, 0);
    for (int i = mx; i >= t; --i) {
        x <<= 1;
        x |= b[i];
    }
    
    int ans = 0;
    for (int i = t; i <= mn && i <= n; ++i) {
        if (x <= k + a[i] && !(i == n && x == a[i])) ++ans;
        imeassert(x != 0);
        x >>= 1;
    }
    printf("%d\n", ans);
	return 0;
}