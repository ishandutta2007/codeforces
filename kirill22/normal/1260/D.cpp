#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second

int m, n, k, t;
vector<pair<int, pair<int, int>>> d;
vector<int> a;

bool check(int x) {
    vector<pair<int, int>> b;
    for (int i = 0; i < k; i++) {
        if (d[i].se.se > x) {
            b.push_back({d[i].fi, d[i].se.fi});
        }
    }
    int y = 0, i = 0;
    int res = 0;
    set<int> tmp;
    while (y < n + 1) {
        //cout << y << " a " << res << " " << i << endl;
        if (i == b.size() || b[i].fi > y + 1) {
            y++;
            res++;
            continue;
        }
        tmp.insert(b[i].se);
        int r = y;
        i++;
        while (tmp.size() > 0) {
            auto it = *tmp.begin();
            tmp.erase(tmp.begin());
            r = max(r, it);
            while (i < b.size() && b[i].fi <= r) {
                tmp.insert(b[i].se);
                i++;
            }
        }
    //cout << r << endl;
        res += (r - y) * 2;
        y++;
        res++;
    }
    if (res <= t) {
        return true;
    }
    return false;
}

signed main() {
    cin >> m >> n >> k >> t;
    d.resize(k);
    a.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++) {
        cin >> d[i].first >> d[i].se.fi >> d[i].se.se;
    }
    sort(d.begin(), d.end());
    int l = 0, r = m + 1;
    while (l + 1 < r) {
        int M = (l + r) / 2;
        //cout << M  << " " << l << " " << r<< endl;
        if (check(a[m - M])) {
            l = M;
        }
        else {
            r = M;
        }
    }
    cout << l;
}