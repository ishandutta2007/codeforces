#include <bits/stdc++.h>

using namespace std;

const int maxw = 1024;

int cnt[2][maxw];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        ++cnt[0][t];
    }
    for (int i = 0; i < k; ++i) {
        int cur = i & 1;
        int next = cur ^ 1;
        for (int j = 0; j < maxw; ++j) {
            cnt[next][j] = 0;
        }
        int num = 0;
        for (int j = 0; j < maxw; ++j) {
            int a = cnt[cur][j] >> 1;
            cnt[next][j] += a;
            cnt[next][j ^ x] += a;
            if (cnt[cur][j] & 1) {
                if (num == 1) ++cnt[next][j];
                else ++cnt[next][j ^ x];
                num ^= 1;
            }
        }
    }
    int mi = maxw, ma = 0;
    int cur = k & 1;
    for (int i = 0; i < maxw; ++i) {
        if (cnt[cur][i]) {
            mi = min(mi, i);
            ma = max(ma, i);
        }
    }
    cout << ma << ' ' << mi << '\n';
}