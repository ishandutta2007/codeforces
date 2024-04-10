#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string ans = "YES";
        for (int i = 0; i + 2 < n; i++) {
            if (a[i] % 2 != a[i + 2] % 2) {
                ans = "NO";
            }
        }
        cout << ans << '\n';
    }
}