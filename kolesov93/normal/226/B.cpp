#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

const int N = 111111;

int a[N];
ll s[N], ans[N];
int n;

ll gets(ll l, ll r) {
    if (r >= n) r = n - 1;
    if (!l) return s[r];
    return s[r] - s[l - 1];
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n, std::greater<int>());

    s[0] = a[0];
    for (int i = 1; i < n; ++i) s[i] = s[i - 1] + ll(a[i]);

    for (int c = 1; c <= n; ++c) {
        ll result = 0, factor = 0, len = 1;
        ll pos = 0;
        while (pos < n) {
            result += gets(pos, pos + len - 1) * factor;
            pos += len;
            ++factor;
            len *= ll(c);
        }
        ans[c] = result;
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        int x; scanf("%d", &x);
        ll result = ans[x];
        if (x >= n) {
            result = ans[n];
        }
        printf("%I64d ", result);
    }
    puts("");

    return 0;
}