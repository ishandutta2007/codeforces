#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int h, n;
    cin >> h >> n;
    vector<int> p(n);
    for (int &i : p)
        cin >> i;
    p.push_back(0);
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (p[i + 1] - p[i + 2] == 1)
            ++i;
        else {
            p[i + 1] = p[i] - 2;
            ++ans;
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}