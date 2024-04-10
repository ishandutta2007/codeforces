#include <bits/stdc++.h>
using namespace std;
const int N = 5e4;
const int F = 56;
const int W = 4 * 9 * F + 1;
bool can[2 * W];

int main() {
    int i, j, k, n, l;
    long long w, cnt[9], y = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> w;
    for (i = 1; i <= 8; ++i) {
        cin >> cnt[i];
        if (cnt[i] >= F && w >= W) {
            long long x = min((w - W) / i, cnt[i] - F);
            cnt[i] -= x;
            w -= x * (long long) i;
            y += x * (long long) i;
        }
    }
    if (w >= 2 * W)
        w = 2 * W - 1;
    for (i = 1; i <= 8; ++i)
        cnt[i] = min(cnt[i], w / i);
    can[0] = 1;
    for (i = 1; i <= 8; ++i)
        for (j = 1; j <= cnt[i]; ++j)
            for (l = w - i; l >= 0; --l)
                can[l + i] |= can[l];
    j = w;
    while (!can[j])
        --j;
    cout << y + j;
}