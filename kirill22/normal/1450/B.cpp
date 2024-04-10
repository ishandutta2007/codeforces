#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) <= k);
            }
            ans |= (cnt == n);
        }
        cout << (ans == 0 ? -1 : 1) << '\n';
    }
}