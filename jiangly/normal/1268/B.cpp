#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long ans = 0;
    int c[2] = {};
    for (int i = 0; i < n; ++i) {
        ans += a[i] / 2;
        if (a[i] % 2 == 1)
            ++c[i % 2];
    }
    ans += min(c[0], c[1]);
    cout << ans << "\n";
    return 0;
}