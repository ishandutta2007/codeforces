#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;

vector <pair<long long, int> > v0, v1;
long long a[N], b[N];

int main() {
    int i, j, k, n, m, q, x, y, t;
    long long s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> s;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i <= n; ++i)
        cin >> b[i];
    for (i = 1; i <= m; ++i) {
        cin >> t >> j;
        if (t == 1)
            v0.push_back({j, i});
        else
            v1.push_back({j, i});
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    int l = 1, r = n + 2;
    while (r - l > 1) {
        int x = (l + r) / 2 - 1;
        int l1 = 0, l2 = 0;
        long long mnd = 1e6, mnf = 1e6;
        for (i = 1; i <= x; ++i) {
            if (a[i] < mnd)
                mnd = a[i];
            if (b[i] < mnf)
                mnf = b[i];
        }
        long long cnt =  0;
        while (l1 + l2 < k) {
            if (l2 == v1.size() || (l1 != v0.size() && v0[l1].fi * mnd < v1[l2].fi * mnf)) {
                cnt += v0[l1].fi * mnd;
                ++l1;
            } else {
                cnt += v1[l2].fi * mnf;
                ++l2;
            }
        }
        if (cnt <= s)
            r = x + 1;
        else
            l = x + 1;
    }
    if (l > n) {
        cout << -1;
        return 0;
    }
    cout << l << "\n";
    long long mnd = 1e6 + 1, mnf = 1e6 + 1, d1, d2;
    for (i = 1; i <= l; ++i) {
        if (a[i] < mnd) {
            mnd = a[i];
            d1 = i;
        }
        if (b[i] < mnf) {
            mnf = b[i];
            d2 = i;
        }
    }
    int l1 = 0, l2 = 0;
    while (l1 + l2 < k) {
        if (l2 == v1.size() || (l1 != v0.size() && v0[l1].fi * mnd < v1[l2].fi * mnf)) {
            cout << v0[l1].se << ' ' << d1 << "\n";
            ++l1;
        } else {
            cout << v1[l2].se << ' ' << d2 << "\n";
            ++l2;
        }
    }
}