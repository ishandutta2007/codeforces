#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int mx = 131072;
    int k;
    cin >> k;
    if (k == 0) {
        cout << 1 << " " << 1 << endl << 1 << endl;
        return 0;
    }
    cout << 3 << " " << 3 << endl;
    cout << (mx | k) << " " << mx << " " << mx << endl;
    cout << k << " " << (mx | k) << " " << (mx | k) << endl;
    cout << k << " " << (mx | k) << " " << k << endl;
}