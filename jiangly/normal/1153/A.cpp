#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    int ans = -1, x = 1E9;
    for (int i = 0; i < n; ++i) {
        int s, d;
        cin >> s >> d;
        int k = max(0, (t - s + d - 1) / d);
        s += k * d;
        if (s < x) {
            x = s;
            ans = i;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}