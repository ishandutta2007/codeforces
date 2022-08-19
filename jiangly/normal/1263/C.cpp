#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> f;
    for (int l = 1, r; l <= n; l = r + 1) {
        f.push_back(n / l);
        r = n / (n / l);
    }
    f.push_back(0);
    reverse(f.begin(), f.end());
    cout << f.size() << "\n";
    for (int i : f)
        cout << i << " \n"[i == f.back()];
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