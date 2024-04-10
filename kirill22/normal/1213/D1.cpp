#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> ans(2 * 100000 + 5);
    for (int i = 0; i < n; i++) {
        int t = 0;
        while (a[i] != 0) {
            ans[a[i]].push_back(t);
            a[i] /= 2;
            t++;
        }
        ans[0].push_back(t);
    }
    int ansj = 1e17;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].size() >= k) {
            sort(ans[i].begin(), ans[i].end());
            int ansi = 0;
            for (int j = 0; j < k; j++) {
                ansi += ans[i][j];
            }
            ansj = min(ansj, ansi);
        }
    }
    cout << ansj;
}