#include <bits/stdc++.h>

using namespace std;

const int P = int(1e9) + 7;
const int T = 1 << 20;

int n;
int cnt[T], pw2[T];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    pw2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw2[i] = pw2[i - 1] * 2 % P;
    }
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < T; ++j) {
            if (j >> i & 1) cnt[j - (1 << i)] += cnt[j];
        }
    }
    int ans = pw2[n];
    for (int i = 1; i < T; ++i) {
        int tot = 0;
        for (int j = 0; j < 20; ++j) {
            if (i >> j & 1) ++tot;
        }
        if (tot % 2 == 1) {
            ans += P - pw2[cnt[i]];
        } else {
            ans += pw2[cnt[i]];
        }
        if (ans >= P) ans -= P;
    }
    cout << ans << endl;
    return 0;
}