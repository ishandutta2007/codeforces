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
    const int INF = 1002002002;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        for (char& c: a) {
            c -= '0';
        }
        for (char& c: b) {
            c -= '0';
        }
        int a1 = 0;
        int b1 = 0;
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                ++a1;
            }
        }
        int ans = INF;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 1) {
                ++b1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                ++diff;
            }
        }
        if (a1 == b1) {
            ans = min(ans, diff);
        }
        diff = 0;
        for (int i = 0; i < n; ++i) {
            a[i] ^= 1;
            diff += (a[i] == b[i] ? 0 : 1);
        }
        a1 = n - a1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                diff -= (a[i] == b[i] ? 0 : 1);
                ++a1;
                a[i] = 1;
                diff += (a[i] == b[i] ? 0 : 1);

                if (a1 == b1) {
                    ans = min(ans, 1 + diff);
                }

                diff -= (a[i] == b[i] ? 0 : 1);
                --a1;
                a[i] = 0;
                diff += (a[i] == b[i] ? 0 : 1);
            }
        }
        if (ans == INF) {
            cout << -1;
        } else {
            cout << ans;
        }
        cout << "\n";
    }
    
    
}