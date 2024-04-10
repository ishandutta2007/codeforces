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
        string a, b;
        cin >> a >> b;
        int x = 1, y = -1;
        for (auto &c : a) {
            if (c == '1' || c == '2') {
                c = '0';
            }
            else {
                c = '1';
            }
        }
        for (auto &c : b) {
            if (c == '1' || c == '2') {
                c = '0';
            }
            else {
                c = '1';
            }
        }
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (x == 1) {
                if (a[i] == '1' && b[i] == '1') {
                    y = 1;
                    x = -1;
                }
                else if (a[i] == '1') {
                    f = false;
                }
                else {
                    x = 1;
                    y = -1;
                }
            }
            else {
                if (a[i] == '1' && b[i] == '1') {
                    x = 1;
                    y = -1;
                }
                else if (b[i] == '1') {
                    f = false;
                }
                else {
                    y = 1;
                    x = -1;
                }
            }
        }
        if (y == -1) {
            f = false;
        }
        if (f) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}