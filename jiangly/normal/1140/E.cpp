#include <bits/stdc++.h>
using namespace std;
constexpr int P = 998244353, N = 2E5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int f[N][2] {};
    f[0][0] = 0;
    f[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        f[i][0] = (f[i - 1][1] + 1LL * f[i - 1][0] * (k - 2)) % P;
        f[i][1] = 1LL * f[i - 1][0] * (k - 1) % P;
    }
    int ans = 1;
    int lst = -1;
    for (int i = 0; i < n; i += 2) {
        if (a[i] != -1) {
            if (lst == -1)
                ans = 1LL * ans * (1LL * (k - 1) * f[i / 2][0] % P + f[i / 2][1]) % P;
            else
                ans = 1LL * ans * f[(i - lst) / 2][a[lst] == a[i]] % P;
            lst = i;
        }
    }
    if (lst == -1)
        ans = 1LL * ans * k * (1LL * (k - 1) * f[(n - 1) / 2][0] % P + f[(n - 1) / 2][1]) % P;
    else
        ans = 1LL * ans * (1LL * (k - 1) * f[(n - 1 - lst) / 2][0] % P + f[(n - 1 - lst) / 2][1]) % P;
    lst = -1;
    for (int i = 1; i < n; i += 2) {
        if (a[i] != -1) {
            if (lst == -1)
                ans = 1LL * ans * (1LL * (k - 1) * f[i / 2][0] % P + f[i / 2][1]) % P;
            else
                ans = 1LL * ans * f[(i - lst) / 2][a[lst] == a[i]] % P;
            lst = i;
        }
    }
    if (lst == -1)
        ans = 1LL * ans * k * (1LL * (k - 1) * f[(n - 1) / 2][0] % P + f[(n - 1) / 2][1]) % P;
    else
        ans = 1LL * ans * (1LL * (k - 1) * f[(n - 1 - lst) / 2][0] % P + f[(n - 1 - lst) / 2][1]) % P;
    cout << ans << endl;
    return 0;
}