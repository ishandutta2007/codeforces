#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 2222;
int a[N];
int f[N];

ll myabs(ll x) {
    if (x < 0) return -x;
    return x;
}


int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    if (k >= n - 1) {
        puts("0");
        return 0;
    }

    ll l = 0, r = 2000000000;
    while (l < r) {
        ll center = (l + r) >> 1;

        memset(f, 63, sizeof(f));
        int ans = n - 1;
        for (int i = 0; i < n; ++i) {
            f[i] = i;

            for (int j = 0; j < i; ++j) {
                int diff = myabs(a[i] - a[j]);
                int cnt = i - j - 1;

                if (ll(cnt + 1) * center >= diff) {
                    f[i] = min(f[i], f[j] + cnt);
                }
            }
            ans = min(ans, n - i - 1 + f[i]);
            if (ans <= k) break;
        }

        if (ans <= k) r = center;
        else l = center + 1;
    }

    cout << l << endl;


    return 0;
}