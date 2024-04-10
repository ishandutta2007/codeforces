#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> l(n, -1), r(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        if (l[a[i]] == -1)
            l[a[i]] = i;
        r[a[i]] = i;
    }
    int ans = 0, tot = 0;
    for (int i = 0; i < n; ++i)
        if (l[i] != -1)
            ++tot;
    int cnt = 0, last = -1;
    for (int i = 0; i < n; ++i) {
        if (l[i] == -1)
            continue;
        if (last == -1 || l[i] > r[last])
            ++cnt;
        else
            cnt = 1;
        last = i;
        ans = max(ans, cnt);
    }
    cout << tot - ans << "\n";
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}