#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 200000;

int n;
int m[N], p[N];

vector<int> a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> m[i] >> p[i];
    for (int i = 0; i < n; ++i) a[m[i]].push_back(p[i]);
    int64 ans = 0;
    priority_queue<int, vector<int>, greater<int>> h;
    for (int i = n - 1; i >= 0; --i) {
        for (int j : a[i]) h.push(j);
        while (h.size() > n - i) ans += h.top(), h.pop();
    }
    for (int i = 0; i < n; ++i) a[i].clear();
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}