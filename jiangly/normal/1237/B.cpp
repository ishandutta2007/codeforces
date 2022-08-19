#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p[x - 1] = i;
    }
    int ans = 0, mx = -1;
    for (int i = 0; i < n; ++i) {
        if (mx > p[a[i]])
            ++ans;
        mx = max(mx, p[a[i]]);
    }
    cout << ans << "\n";
    return 0;
}