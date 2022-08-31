#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n, r;
    cin >> n >> r;
    vector<int> x(n);
    for (int &i : x)
        cin >> i;
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    int ans = x.size();
    for (int i = x.size() - 2; i >= 0; --i)
        if (x[i] <= LL(r) * (x.size() - i - 1)) {
            ans = x.size() - i - 1;
            break;
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