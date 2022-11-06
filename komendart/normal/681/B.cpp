#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i <= n; i += 1234567) {
        for (int j = 0; i + j <= n; j += 123456) {
            if ((n - i - j) % 1234 == 0) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}