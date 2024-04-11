#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int N = 1111;
ll a[N];
ll f[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m;    
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d",&x);
        a[i] = x;
    }

    f[0] = f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= 1000000000;
    }

    while (m--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int x, v;
            scanf("%d%d", &x, &v);
            a[x] = v;
        } else {
            ll ans = 0;
            int l, r;
            scanf("%d%d", &l, &r);
            int lim = r - l;
            for (int i = 0; i <= lim; ++i) {
                ans = (ans + f[i] * a[l + i]) % 1000000000;
            }
            printf("%d\n", (int) ans);
        }
    }

    return 0;
}