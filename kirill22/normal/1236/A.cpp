#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    while (n--) {
            int a, b, c;
            cin >> a >> b >> c;
            int mx = min(b, c / 2);
            b -= mx;
            int mx2 = min(a, b / 2);
            cout << mx * 3 + mx2 * 3 << endl;
    }
}