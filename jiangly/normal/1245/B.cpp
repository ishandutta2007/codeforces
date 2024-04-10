#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    vector<char> t(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R' && b > 0) {
            t[i] = 'P';
            --b;
        }
        if (s[i] == 'P' && c > 0) {
            t[i] = 'S';
            --c;
        }
        if (s[i] == 'S' && a > 0) {
            t[i] = 'R';
            --a;
        }
    }
    int cnt = n - a - b - c;
    if (2 * cnt < n) {
        cout << "NO" << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (t[i] == 0) {
            if (a > 0) {
                t[i] = 'R';
                --a;
            } else if (b > 0) {
                t[i] = 'P';
                --b;
            } else {
                t[i] = 'S';
                --c;
            }
        }
    }
    cout << "YES" << "\n";
    cout << string(t.begin(), t.end()) << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}