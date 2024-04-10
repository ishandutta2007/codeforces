#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
const int N = 1000000;

int m[N], vv, dp[N], pr[N], suf[N], d[N], c[N], dp1[N];

void als(int i, int j) {
    i = i + vv - 2;
    m[i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        m[i] = max(m[2*i+1], m[2*i+2]);
    }
}

int zpr(int v,int vl,int vr, int l,int r) {
    if (l <= vl && vr <= r)
        return m[v];
    else if (l >= vr || vl >= r)
            return 0;
        else
            return max(zpr(2*v + 1, vl, (vl + vr)/2, l, r), zpr(2*v + 2, (vl + vr)/2, vr, l, r));
}

vector <pair<int, int> > v, v1;

int main() {
    int i, j, i1, a, b, n, m;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b + 1, -1});
    }
    sort(v.begin(), v.end());
    j = 0;
    vv = 1;
    while (vv < m) vv *= 2;
    int balance = 0;
    for (i = 1; i <= m; ++i) {
        while (j < v.size() && v[j].first <= i) {
            balance += v[j].second;
            ++j;
        }
        d[i] = balance;
        v1.push_back({d[i], i});
    }
    sort(v1.begin(), v1.end());
    for (i = 0; i < v1.size(); ++i)
        c[v1[i].second] = i + 1;
    pr[0] = 0;
    for (i = 1; i <= m; ++i) {
        int l = 0, r = m;
        while (r - l > 1) {
            int x = (l + r) / 2;
            if (v1[x].first > d[i])
                r = x;
            else
                l = x;
        }
        dp[i] = zpr(0, 1, vv + 1, 1, r + 1) + 1;
        pr[i] = max(pr[i - 1], dp[i]);
        als(c[i], dp[i]);
    }
    for (i = 1; i <= m; ++i)
        als(i, 0);
    suf[m + 1] = 0;
    for (i = m; i > 0; --i) {
        int l = 0, r = m;
        while (r - l > 1) {
            int x = (l + r) / 2;
            if (v1[x].first > d[i])
                r = x;
            else
                l = x;
        }
        dp1[i] = zpr(0, 1, vv + 1, 1, r + 1) + 1;
        suf[i] = max(suf[i + 1], dp1[i]);
        als(c[i], dp1[i]);
    }
    int ans = 0;
    for (i = 1; i <= m; ++i) {
        int ans1 = pr[i - 1] + suf[i + 1];
        if (ans1 > ans)
            ans = ans1;
        ans1 = dp[i] + dp1[i] - 1;
        if (ans1 > ans)
            ans = ans1;
    }
    cout << ans;
}