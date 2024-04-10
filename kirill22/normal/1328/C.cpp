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
        string s;
        cin >> s;
        string a = "", b = "";
        bool f = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '2') {
                if (!f) {
                    a += '1';
                    b += '1';
                }
                else {
                    a += '0';
                    b += '2';
                }
            }
            else if (s[i] == '0') {
                a += '0';
                b += '0';
            }
            else {
                if (!f) {
                    a += '1';
                    b += '0';
                    f = true;
                }
                else {
                    a += '0';
                    b += '1';
                }
            }
        }
        cout << a << '\n' << b << '\n';
    }
}