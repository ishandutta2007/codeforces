#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1)
        [&](){
            int n;
            cin >> n;
            vector<int> a(n), s(n + 1);
            for (int i = 0; i < n; i += 1) {
                cin >> a[i];
                s[i + 1] = s[i] + a[i];
            }
            int ans = n - 1;
            for (int i = 0; i <= n; i += 1)
                ans = min(ans, max(s[i], (n - i) - (s[n] - s[i])));
            cout << ans << "\n";
        }();
}