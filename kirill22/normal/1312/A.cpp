#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        if (n % m == 0) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}