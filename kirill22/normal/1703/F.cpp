#include <bits/stdc++.h>

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
        long long ans = 0;
        vector<int> a;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x < i) {
                ans += lower_bound(a.begin(), a.end(), x) - a.begin();
                a.push_back(i);
            }
        }
        cout << ans << '\n';
    }
}