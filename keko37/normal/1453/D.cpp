#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint t, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> k;
        if (k & 1) {
            cout << -1 << '\n';
            continue;
        }
        string s;
        for (int i = 0; i < 62; i++) {
            if (k & (1LL << i)) {
                if (i == 1) {
                    s += '1';
                } else {
                    s += '1'; s += '1';
                    for (int j = 0; j < i - 2; j++) s += '0';
                }
            }
        }
        cout << s.size() << '\n';
        for (auto c : s) cout << c << " "; cout << '\n';
    }
    return 0;
}