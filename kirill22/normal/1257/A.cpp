#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        cout << b - a + min(x, (a - 1) + (n - b)) << endl;
    }
}