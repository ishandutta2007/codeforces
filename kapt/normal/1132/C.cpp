#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;
int arr[MAXN];
int cnt1[MAXN], cnt2[MAXN];

main() {
    int n, q;
    cin >> n >> q;
    int l, r;
    vector<pair<int, int>> vec;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        l--; r--;
        vec.push_back({l, r});
        for (int i = l; i <= r; ++i) {
            arr[i]++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt1[i + 1] = cnt1[i] + (arr[i] == 1);
        cnt2[i + 1] = cnt2[i] + (arr[i] == 2);
        cnt += (arr[i] != 0);
    }
    /*for (int i = 0; i <= n; ++i) {
        cout << cnt1[i] << " " << cnt2[i] << endl;
    }
    cout << cnt << endl;*/
    int glans = 1e9;
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < i; ++j) {
            int l1 = vec[i].first, l2 = vec[j].first, r1 = vec[i].second, r2 = vec[j].second;
            int l = max(l1, l2);
            int r = min(r1, r2);
            int ans = 0;
            // cout << r1 << " " << l1 << " " << r2 << " " << l2 << " " << r << " " << l << endl;
            if (l <= r) {
                ans += cnt2[r + 1] - cnt2[l];
            }
            ans += cnt1[r1 + 1] - cnt1[l1];
            ans += cnt1[r2 + 1] - cnt1[l2];
            // cout << ans << endl;
            glans = min(glans, ans);
        }
    }
    cout << cnt - glans;
    return 0;
}