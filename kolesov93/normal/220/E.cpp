#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <deque>
#include <memory.h>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

const int N = 211111;
int a[N];
int b[N];
int n;
ll k;
int prv[N], nxt[N];

ll sum1[N], sum2[N];


void modify(ll* sum, int pos, int val) {
    while (pos <= n) {
        sum[pos] += val;
        pos = nxt[pos];
    }
}
ll findsum(ll* sum, int l, int r) {
    if (l > r) return 0;
    ll ans = 0;
    for (; r; r = prv[r]) ans += sum[r];
    for (--l; l; l = prv[l]) ans -= sum[l];
    return ans;
}


int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d%I64d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    sort(b, b + n);

    for (int i = 0; i < n; ++i) {
        a[i] = (lower_bound(b, b + n, a[i]) - b) + 1;
    }

    for (int i = 0; i <= n; ++i) {
        prv[i] = i & (i - 1);
        nxt[i] = i + i - prv[i];
    }

    ll curi = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        curi += findsum(sum1, a[i] + 1, n);
        modify(sum1, a[i], 1);
    }
    memset(sum1, 0, sizeof(sum1));

    for (int i = 1; i < n; ++i) {
        modify(sum2, a[i], 1);
    }
    modify(sum1, a[0], 1);

    int r = 1;
    for (int l = 0; l + 1 < n; ++l) {
        while (curi > k && r + 1 < n) {
            curi -= findsum(sum1, a[r] + 1, n);
            curi -= findsum(sum2, 1, a[r] - 1);

            modify(sum2, a[r], -1);
            ++r; 
        }

        if (curi > k) break;

        //cerr << l << " " << r << endl;
        ans += ll(n - r);

        if (l + 2 < n) {
            if (r == l + 1) {
                curi -= findsum(sum1, a[r] + 1, n);
                curi -= findsum(sum2, 1, a[r] - 1);

                modify(sum2, a[r], -1);
                ++r;
            }

            curi += findsum(sum1, a[l + 1] + 1, n);
            curi += findsum(sum2, 1, a[l + 1] - 1);
            modify(sum1, a[l + 1], 1);
        }
    }

    cout << ans << endl;
    
    return 0;
}