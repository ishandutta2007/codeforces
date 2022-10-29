#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, n, m;
        cin >> x >> n >> m;
        for (int i = 1; i <= n; i++) {
            if (x / 2 + 10 > x) break;
            x = x / 2 + 10;
        }
        x -= 10 * m;
        if (x > 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}