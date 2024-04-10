#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<LL> s(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        s[i % m] += a[i];
        ans += s[i % m];
        cout << ans << " \n"[i == n - 1];
    }
    return 0;
}