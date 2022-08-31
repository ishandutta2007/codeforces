#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ) {
        int j = min_element(p.begin() + i, p.end()) - p.begin();
        for (int k = j - 1; k >= i; --k)
            swap(p[k], p[k + 1]);
        i = max(j, i + 1);
    }
    for (int i = 0; i < n; ++i)
        cout << p[i] << " \n"[i == n - 1];
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