#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string ans = v[0];
    for (int j = 0; j < m; j++) {
        char save = ans[j];
        for (char d = 'a'; d <= 'z'; d++) {
            ans[j] = d;
            bool flag = true;
            for (int z = 0; z < n; z++) {
                int cntErrors = 0;
                for (int c = 0; c < m; c++) {
                    if (v[z][c] != ans[c]) {
                        cntErrors++;
                    }
                }
                if (cntErrors > 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << ans << endl;
                return;
            }
        }
        ans[j] = save;
    }
    cout << "-1" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}