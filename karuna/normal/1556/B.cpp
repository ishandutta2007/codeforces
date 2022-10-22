#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 1e5 + 10;
int n, A[M];

void solve() {
    cin >> n;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i]; A[i] %= 2;
        if (A[i] & 1) x += 1;
        else y += 1;
    }
    if (abs(x - y) > 1) {
        cout << -1 << '\n'; return;
    }
    lint ans = -1, ans2 = -1;
    if (x == (n + 1) / 2) {
        int pos = 1; ans = 0;
        for (int i = 1; i <= n; i++) if (A[i] == 1) {
            ans += abs(i - pos); pos += 2;
        }
    }
    if (x == n / 2) {
        int pos2 = 2; ans2 = 0;
        for (int i = 1; i <= n; i++) if (A[i] == 1) {
            ans2 += abs(i - pos2); pos2 += 2;
        }
    }
    if (ans == -1) cout << ans2 << '\n';
    else if (ans2 == -1) cout << ans << '\n';
    else cout << min(ans, ans2) << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}