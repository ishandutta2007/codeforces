#include<bits/stdc++.h>

using namespace std;

// fuck life

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string ans = "NO";
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (auto x : {a[0], a[0] - 1, a[0] + 1}) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                if (abs(a[i] - x - i) > 1) {
                    ok = 0;
                }
            }
            if (ok) {
                ans = "YES";
            }
        }
        cout << ans << '\n';
    }
}