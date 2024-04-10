#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, z, ans = 0;
        cin >> n >> z;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            ans = max(ans, a | z);
        }
        cout << ans << "\n";
    }
    return 0;
}