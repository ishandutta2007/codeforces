#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int nul = 0, jen = 0;
        for (auto c : s) {
            if (c == '0') nul++; else jen++;
        }
        if (s[0] != '1' || s.back() != '1' || nul % 2 == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int curr_nul = 0, curr_jen = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') curr_nul++; else curr_jen++;
                if (s[i] == '0') {
                    if (curr_nul % 2 == 0) cout << '('; else cout << ')';
                } else {
                    if (curr_jen * 2 <= jen) cout << '('; else cout << ')';
                }
            }
            cout << '\n';
            curr_nul = 0, curr_jen = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') curr_nul++; else curr_jen++;
                if (s[i] == '0') {
                    if (curr_nul % 2 == 1) cout << '('; else cout << ')';
                } else {
                    if (curr_jen * 2 <= jen) cout << '('; else cout << ')';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}