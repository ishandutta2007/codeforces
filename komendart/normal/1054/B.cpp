#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > cur) {
            cout << i + 1 << '\n';
            return 0;
        }
        cur = max(cur, x + 1);
    }
    cout << -1 << '\n';
}