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
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) == 1) {
            cout << "Finite";
        }
        else {
            cout << "Infinite";
        }
        cout << endl;
    }
}