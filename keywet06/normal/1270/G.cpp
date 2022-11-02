#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i], a[i] = i - a[i];
    vector<int> pos(n, -1), stk;
    int u = 0;
    while (pos[u] == -1) pos[u] = stk.size(), stk.push_back(u), u = a[u];
    cout << stk.size() - pos[u] << "\n";
    for (int i = pos[u]; i < stk.size(); ++i) {
        cout << stk[i] + 1 << " \n"[i == stk.size() - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}