#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin >> q;
    while (q--) {
        ll n;
        cin >> n;
        ll t[n];
        for (int i = 0; i < n; i++) cin >> t[i];

        bool diff = false;
        bool dub = false;
        if (t[0] == t[n-1]) dub = true;
        for (int i = 1; i < n; i++) {
            if (t[i] != t[i-1]) diff = true;
            if (t[i] == t[i-1]) dub = true;
        }

        if (!diff) {
            cout << 1 << endl;
            for (int i = 0; i < n-1; i++) cout << 1 << ' ';
            cout << 1 << endl;
            continue;
        }


        if (!dub) {
            if (n % 2 == 1) {
                cout << 3 << endl;
                for (int i = 0; i < n-1; i++) {
                    if (i % 2 == 0) cout << 1 << ' ';
                    else cout << 2 << ' ';
                }
                cout << 3 << endl;
            } else {
                cout << 2 << endl;
                for (int i = 0; i < n-1; i++) {
                    if (i % 2 == 0) cout << 1 << ' ';
                    else cout << 2 << ' ';
                }
                cout << 2 << endl;
            }
            continue;
        }

        // there is a dub
        if (n % 2 == 0) {
            cout << 2 << endl;
            for (int i = 0; i < n-1; i++) {
                if (i % 2 == 0) cout << 1 << ' ';
                else cout << 2 << ' ';
            }
            cout << 2 << endl;
        } else {
            cout << 2 << endl;
            bool encountereddub = false;
            for (int i = 0; i < n-1; i++) {
                if (encountereddub) {
                    if (i % 2 == 0) cout << 2 << ' ';
                    else cout << 1 << ' ';
                } else {
                    if (i >= 1 && t[i] == t[i-1]) {
                        encountereddub = true;
                        if (i % 2 == 0) cout << 2 << ' ';
                        else cout << 1 << ' ';
                    } else {
                        if (i % 2 == 0) cout << 1 << ' ';
                        else cout << 2 << ' ';
                    }
                }
            }

            if (encountereddub || t[n-1] == t[n-2]) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
        }
    }
}