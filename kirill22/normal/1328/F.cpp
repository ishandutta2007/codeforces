#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int _n = n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<pair<int, int>> b;
    int tmp = a[0], s = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == tmp) {
            s++;
            continue;
        }
        b.emplace_back(tmp, s);
        if (s >= k) {
            cout << 0; return 0;
        }
        tmp = a[i];
        s = 1;
    }
    b.emplace_back(tmp, s);
    if (s >= k) {
        cout << 0; return 0;
    }
    n = b.size();
    int res = 1e18;
    int res2 = 0;
    pair<int, int> t = b[0];
    for (int i = 1; i < n; i++) {
        res2 += (b[i].first - t.first) * t.second;
        t.second += b[i].second;
        if (t.second >= k) {
            res2 -= (t.second - k) * (b[i].first - t.first);
            res = min(res, res2);
            break;
        }
        t.first = b[i].first;
    }
    res2 = 0;
    t = b[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        res2 += abs(b[i].first - t.first) * t.second;
        t.second += b[i].second;
        if (t.second >= k) {
            res2 -= (t.second - k) * abs(b[i].first - t.first);
            res = min(res, res2);
            break;
        }
        t.first = b[i].first;
    }
    res2 = 0;
    pair<int, int> l = b[0], r = {0, 0};
    int L = 0, R = 0;
    for (int i = 0; i < n; i++) {
        r.second += b[i].second;
        r.first = b[0].first;
        R += b[i].second * (b[i].first - b[0].first);
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            L += l.second * (b[i].first - l.first);
            l.first = b[i].first;
            l.second += b[i].second;
            r.second -= b[i - 1].second;
            R -= r.second * (b[i].first - r.first);
            r.first = b[i].first;
        }
        res = min(res, L + R - (_n - k));
    }
    cout << res;
}