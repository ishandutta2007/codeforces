#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> remove(n);
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; i += 1) {
            cin >> a[i];
            q.emplace(a[i] + i, i);
        }
        for (int i = 0; i < k; i += 1) {
            remove[q.top().second] = 1;
            q.pop();
        }
        LL ans = 0;
        for (int i = 0, j = 0; i < n; i += 1)
            if (remove[i]) j += 1;
            else ans += a[i] + j;
        cout << ans << "\n";
    }
    return 0;
}