#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i)
        if (ans[i] == -1) {
            ans[i] = 1;
            for (int j = p[i]; j != i; j = p[j])
                ++ans[i];
            for (int j = p[i]; j != i; j = p[j])
                ans[j] = ans[i];
        }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
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