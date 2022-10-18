#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    int pos = 0;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        string s;
        cin >> s;

        if (s == "North") {
            pos -= t;
        }
        if (s == "South") {
            pos += t;
        }

        if (pos < 0 || pos > 20000) {
            cout << "NO" << endl;
            return 0;
        }

        if ((pos == 0 || pos == 20000) && (s == "East" || s == "West")) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (pos == 0) 
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    return 0;
}