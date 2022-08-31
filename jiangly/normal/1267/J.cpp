#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        ++cnt[x];
    }
    vector<int> a(n + 1);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 0)
            continue;
        ++tot;
        for (int j = 1; j <= min(n, cnt[i] + 1); ++j)
            if (cnt[i] >= (cnt[i] + j - 1) / j * (j - 1))
                ++a[j];
    }
    int s = n;
    while (a[s] != tot)
        --s;
    int m = 0;
    for (int i = 0; i < n; ++i)
        m += (cnt[i] + s - 1) / s;
    cout << m << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}