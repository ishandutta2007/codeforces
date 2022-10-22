#include<bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a == b) cout << "0\n";
        else if (a > b) {
            if ((a - b) % 2 == 0) {
                cout << "1\n";
            }
            else {
                cout << "2\n";
            }
        }
        else {
            if ((b - a) % 2 == 1) {
                cout << "1\n";
            }
            else {
                cout << "2\n";
            }
        }
    }
}