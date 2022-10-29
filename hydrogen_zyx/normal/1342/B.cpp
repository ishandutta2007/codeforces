#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool f = 1;
        for (int i = 1; i < s.length(); i++)
            if (s[i] != s[i - 1]) f = 0;
        if (f) {
            cout << s << endl;
            continue;
        }
        for (int i = 1; i <= 2 * s.length(); i++) {
            cout << (i & 1);
        }
        cout << endl;
    }
}