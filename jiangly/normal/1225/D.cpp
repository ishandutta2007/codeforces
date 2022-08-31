#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int MAX_N = 1E5;
int n, k;
int cnt[MAX_N + 1];
LL pw[MAX_N + 1][101];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    LL ans = 0;
    for (int i = 1; i <= MAX_N; ++i) {
        pw[i][0] = 1;
        for (int j = 1; j <= 100; ++j)
            pw[i][j] = min(MAX_N + 1LL, pw[i][j - 1] * i);
    }
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        int y = x;
        LL p = 1;
        for (int j = 2; j * j <= x; ++j) {
            int t = 0;
            while (x % j == 0) {
                x /= j;
                ++t;
            }
            y /= pw[j][t / k * k];
            p = min(MAX_N + 1LL, p * pw[j][(k - t % k) % k]);
        }
        p = min(MAX_N + 1LL, p * pw[x][k - 1]);
        if (p <= MAX_N)
            ans += cnt[p];
        ++cnt[y];
    }
    cout << ans << endl;
    return 0;
}