#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        bool found = false;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] + s[i + 1] - 2 * '0' >= 10) {
                for (int j = 0; j < i; ++j) {
                    cout << s[j];
                }
                cout << (int)(s[i] + s[i + 1] - 2 * '0');
                for (int j = i + 2; j < n; ++j) {
                    cout << s[j];
                }
                found = true;
                break;
            }
        }
        if (!found) {
            cout << (int)(s[0] + s[1] - 2 * '0');
            for (int i = 2; i < n; ++i) {
                cout << s[i];
            }
        }
//        cout << endl;
        cout << "\n";
    }
}