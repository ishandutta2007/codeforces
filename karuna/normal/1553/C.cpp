#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

void solve() {
    string S; cin >> S;

    string T; int ans = 11;
    for (int i = 0; i < (1 << 10); i++) {
        T = S; int f = 1;
        for (int j = 0; j < 10; j++) {
            if (T[j] == '1' && (~i >> j & 1)) f = 0;
            if (T[j] == '0' && (i >> j & 1)) f = 0;
            if (T[j] == '?') {
                if (i >> j & 1) T[j] = '1';
                else T[j] = '0';
            }
        }
        if (f == 0) continue;

        int a = 0, b = 0, c = 10;
        for (int j = 0; j < 10; j++) {
            if (j % 2 == 0) {
                if (j % 2 == 0 && T[j] == '1') a += 1;
                if (a + (9 - j) / 2 < b || a > b + (10 - j) / 2) {
                    c = j + 1; break;
                }
            }
            else {
                if (T[j] == '1') b += 1;
                if (a + (9 - j) / 2 < b || a > b + (9 - j) / 2) {
                    c = j + 1; break;
                }
            }
        }
        ans = min(ans, c);
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}