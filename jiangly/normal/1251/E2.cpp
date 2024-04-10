#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int MAX_N = 2E5;
int n;
int m[MAX_N], p[MAX_N];
vector<int> a[MAX_N];
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> m[i] >> p[i];
    for (int i = 0; i < n; ++i)
        a[m[i]].push_back(p[i]);
    LL ans = 0;
    priority_queue<int, vector<int>, greater<int>> h;
    for (int i = n - 1; i >= 0; --i) {
        for (int j : a[i])
            h.push(j);
        while (h.size() > n - i) {
            ans += h.top();
            h.pop();
        }
    }
    for (int i = 0; i < n; ++i)
        a[i].clear();
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}