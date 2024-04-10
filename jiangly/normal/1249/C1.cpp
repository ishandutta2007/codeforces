#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int a[50];
void solve() {
    memset(a, 0, sizeof(a));
    LL n;
    cin >> n;
    int cnt = 0;
    while (n > 0) {
        a[cnt++] = n % 3;
        n /= 3;
    }
    for (int i = 0; i < cnt; ++i) {
        if (a[i] == 2) {
            a[i] = 3;
            for (int j = 0; j < i; ++j)
                a[j] = 0;
        }
        if (a[i] == 3) {
            a[i] = 0;
            ++a[i + 1];
        }
    }
    if (a[cnt] > 0)
        ++cnt;
    while (cnt > 0)
        n = 3 * n + a[--cnt];
    cout << n << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}