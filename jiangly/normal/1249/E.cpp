#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 2E5;
int n, c;
int a[MAX_N], b[MAX_N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c;
    for (int i = 1; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        cin >> b[i];
    for (int i = 2; i < n; ++i)
        a[i] += a[i - 1];
    for (int i = 2; i < n; ++i)
        b[i] += b[i - 1];
    int ma = 0, mb = 0;
    for (int i = 0; i < n; ++i) {
        int f = min(ma + a[i], mb + b[i] + c);
        ma = min(ma, f - a[i]);
        mb = min(mb, f - b[i]);
        cout << f << " \n"[i == n - 1];
    }
    return 0;
}