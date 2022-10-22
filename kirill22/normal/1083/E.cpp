#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second

struct line {
    int k, b;
    line() {};
    line(int k, int b) : k(k), b(b) {};
};

deque<line> kht;

long double X(line a, line b) {
    return ((long double) b.b - a.b) / ((long double) a.k - b.k);
}

void update(line a) {
    while (kht.size() > 1) {
        line b = kht.front();
        kht.pop_front();
        line c = kht.front();
        if (X(a, b) < X(b, c)) {
            kht.push_front(b);
            break;
        }
    }
    kht.push_front(a);
}

int get(int x) {
    if (kht.size() == 0) return 0;
    int l = 0, r = kht.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (x < X(kht[m], kht[m - 1])) r = m;
        else l = m;
    }
    return kht[l].k * x + kht[l].b;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<pii, int>> a(n + 1);
    a[0] = {{1e18, 0}, 0};
    for (int i = 1; i <= n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        a[i] = {{x, y}, c};
    }
    sort(a.rbegin(), a.rend());
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = -a[i].se + a[i].fi.se * a[i].fi.fi + max(0ll, get(a[i].fi.fi));
        update(line(-a[i].fi.se, dp[i]));
    }
    cout << *max_element(dp.begin(), dp.end());
}