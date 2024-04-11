#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <memory.h>

using namespace std;
typedef long long ll;

const int N = 5555;
ll a[N], added[N];
ll ans[N];
ll mn[N], mx[N];

int L[N], R[N], D[N], T[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        mn[i] = -1000000000;
        mx[i] = 1000000000;
    }

    for (int it = 0; it < m; ++it) {
        int t; scanf("%d", &t);
        int l, r; scanf("%d%d", &l, &r);
        --l; --r;
        int d; scanf("%d", &d);

        L[it] = l;
        R[it] = r;
        T[it] = t;
        D[it] = d;

        if (t == 1) {
            for (int i = l; i <= r; ++i) {
                added[i] += d;
            }
        } else {
            for (int i = l; i <= r; ++i) {
                mx[i] = min(mx[i], d - added[i]);
            }
        }
    }

    memcpy(ans, mx, sizeof(ans));
    bool cool = true;
    for (int i = 0; i < n; ++i)
        if (mx[i] <= -1000000000) cool = false;
    for (int it = 0; it < m; ++it) {
        if (T[it] == 1) {
            for (int i = L[it]; i <= R[it]; ++i) {
                mx[i] += D[it];
            }
        } else {
            ll res = mx[ L[it] ];
            for (int i = L[it]; i <= R[it]; ++i) {
                res = max(res, mx[i]);
            }
            if (res != D[it]) cool = false;
        }
    }

    if (cool) {
        puts("YES");
        for (int i = 0; i < n; ++i) printf("%d ", int(ans[i]));
        puts("");
    } else {
        puts("NO");
    }

    return 0;
}