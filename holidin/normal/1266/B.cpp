#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;

void solve() {
    int i, j, k, n, t;
    string s;
    cin >> n;
    int x = 3 * 7;
    for (i = 0; i < n; ++i) {
        cin >> t;
        int ct = x - 7;
        int f = t / ct;
        if (t % ct >= 1 && t % ct <= 6 && t >= 15) {
            cout << "YES\n";
        } else
            cout << "NO\n";
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();
}