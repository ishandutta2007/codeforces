#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int ans = -1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'R' && s[i + 1] == 'L') {
            if (ans == -1 || ans > (x[i + 1] - x[i]) / 2) ans = (x[i + 1] - x[i]) / 2;
        }
    }

    cout << ans << endl;
}