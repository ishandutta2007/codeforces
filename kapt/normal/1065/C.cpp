#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5;
int hs[maxn];
int sl_cost[maxn];

main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> hs[i];
    }
    sort(hs, hs + n);
    int cnt = 0, ind = n - 1;
    sl_cost[maxn - 1] = 0;
    for (int i = maxn - 2; i >= 0; --i) {
        while (hs[ind] == i) {
            ind--;
            cnt++;
        }
        sl_cost[i] = sl_cost[i + 1] + cnt;
    }
    int maxh = hs[n - 1] + 1;
    int ans = 0;
    while (maxh > hs[0] + 1) {
        int now_h = maxh;
        while (now_h >= 0 && sl_cost[now_h] - sl_cost[maxh] <= k) {
            now_h--;
        }
        now_h++;
        ans++;
        maxh = now_h;
    }
    cout << ans;
    return 0;
}