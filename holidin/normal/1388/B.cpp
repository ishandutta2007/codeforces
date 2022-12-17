#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int mod = 1e9 + 7;


void solve() {
    int n, i, j;
    cin >> n;
    string ans = "";
    int sum = n;
    for (int i = 0; i < n; ++i)
    if (sum >= 1) {
        sum -= 4;
        ans += "8";
    } else {
        ans += "9";
    }
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i];
    cout << "\n";
}

signed main() {
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test = 0;
    cin >> test;
    for (int i = 0; i < test; ++i)
    solve();
}