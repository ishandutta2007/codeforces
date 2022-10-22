#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << -1 << endl;
        }
        else {
            cout << 2;
            for (int i = 1; i < n; i++) cout << 3;
            cout << endl;
        }
    }
}