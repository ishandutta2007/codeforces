#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define sz(x) ((int) (x).size())

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t; ++cnt[-t];
    }
    for (int i = 0; i < m; ++i) {
        int t; cin >> t; --cnt[-t];
    }
    int sum = 0;
    for (auto i: cnt) {
        sum += i.second;
        if (sum > 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

}