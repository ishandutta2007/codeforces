#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name; int b, a;
        cin >> name >> b >> a;
        if (b >= 2400 && a > b) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}