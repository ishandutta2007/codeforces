#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        char x[n];
        for (int i = 0; i < n; i++) cin >> x[i];

        string a, b;
        a.push_back('1');
        b.push_back('1');
        bool maxed = false;
        for (int i = 1; i < n; i++) {
            if (x[i] == '0') {
                a.push_back('0');
                b.push_back('0');
            } else if (x[i] == '1') {
                if (maxed) {
                    a.push_back('0');
                    b.push_back('1');
                } else {
                    maxed = true;
                    a.push_back('1');
                    b.push_back('0');
                }
            } else if (x[i] == '2') {
                if (maxed) {
                    a.push_back('0');
                    b.push_back('2');
                } else {
                    a.push_back('1');
                    b.push_back('1');
                }
            }
        }
        cout << a << endl;
        cout << b << endl;
    }
}