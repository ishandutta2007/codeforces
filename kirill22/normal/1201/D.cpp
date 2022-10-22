#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<vector<int>> a(n);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x].push_back(y);
    }
    for (int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    vector<int> b(q);
    for (int i = 0; i < q; i++) {
        cin>> b[i];
        b[i]--;
    }
    sort(b.begin(), b.end());
    vector<pair<int, int>> tmp;
    if (a[0].size() == 0) {
        tmp.push_back({0, 0});
    }
    else {
        tmp.push_back({a[0].back(), a[0].back()});
        tmp.push_back({a[0][0], a[0].back() + a[0].back() - a[0][0]});
    }
    int tmp2 = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].size() == 0) {
            tmp2++;
            continue;
        }
        int x = a[i][0];
        int ansx = 1e18;
        int y = a[i].back();
        int ansy = 1e18;
        for (auto c : tmp) {
            int t = tmp2 + c.second + 1;
            int ind = (upper_bound(b.begin(), b.end(), c.first) - b.begin() - 1);
            if (ind != -1) {
                int t2 = t + c.first - b[ind];
                if (a[i].back() > b[ind]) {
                    t2 += a[i].back() - b[ind] + a[i].back() - a[i][0];
                }
                else {
                    t2 += b[ind] - a[i][0];
                }
                ansx = min(ansx, t2);
            }
            ind = (upper_bound(b.begin(), b.end(), c.first) - b.begin());
            if (ind != q) {
                int t2 = t + abs(c.first - b[ind]);
                if (a[i].back() > b[ind]) {
                    t2 += a[i].back() - b[ind] + a[i].back() - a[i][0];
                }
                else {
                    t2 += b[ind] - a[i][0];
                }
                ansx = min(ansx, t2);
            }
        }
        for (auto c : tmp) {
            int t = tmp2 + c.second + 1;
            int ind = (upper_bound(b.begin(), b.end(), c.first) - b.begin() - 1);
            if (ind != -1) {
                int t2 = t + c.first - b[ind];
                if (a[i][0] < b[ind]) {
                    t2 += (- a[i][0] + b[ind]) + a[i].back() - a[i][0];
                }
                else {
                    t2 += (-b[ind] + a[i].back());
                }
                ansy = min(ansy, t2);
            }
            ind = (upper_bound(b.begin(), b.end(), c.first) - b.begin());
            if (ind != q) {
                int t2 = t + abs(c.first - b[ind]);
                if (a[i][0] < b[ind]) {
                    t2 += (- a[i][0] + b[ind]) + a[i].back() - a[i][0];
                }
                else {
                    t2 += (-b[ind] + a[i].back());
                }
                ansy = min(ansy, t2);
            }
        }
        tmp.clear();
        tmp2 = 0;
        tmp.push_back({x, ansx});
        tmp.push_back({y, ansy});
    }
    int ans = 1e18;
    for (auto c : tmp) {
        ans = min(ans, c.second);
    }
    cout << ans;
}