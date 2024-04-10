#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int n;
vector<int> l, r;
LL work(LL x_0) {
    priority_queue<LL> lh;
    priority_queue<LL, vector<LL>, greater<LL>> rh;
    LL dl = 0LL, dr = 0LL, val = abs(x_0);
    for (int i = 0; i <= n; ++i) {
        lh.push(x_0);
        rh.push(x_0);
    }
    for (int i = 1; i < n; ++i) {
        dl -= r[i];
        dr -= l[i];
        LL pl = lh.top() + dl;
        LL pr = rh.top() + dr;
        assert(pl <= pr);
        if (pl <= 0 && pr >= 0) {
            lh.push(-dl);
            rh.push(-dr);
        } else if (pl > 0) {
            val += pl;
            rh.push(pl - dr);
            lh.pop();
            lh.push(-dl);
            lh.push(-dl);
        } else {
            val -= pr;
            lh.push(pr - dl);
            rh.pop();
            rh.push(-dr);
            rh.push(-dr);
        }
    }
    dl -= x_0;
    dr -= x_0;
    LL pl = lh.top() + dl;
    LL pr = rh.top() + dr;
    if (pl <= r[0] && pr >= l[0]) return val;
    else if (l[0] > pr) {
        LL slope = 0, lst = pr;
        while (l[0] > rh.top() + dr) {
            val += slope++ * (rh.top() + dr - lst);
            lst = rh.top() + dr;
            rh.pop();
        }
        return val + slope * (l[0] - lst);
    } else {
        LL slope = 0, lst = pl;
        while (r[0] < lh.top() + dl) {
            val += slope++ * (lst - lh.top() - dl);
            lst = lh.top() + dl;
            lh.pop();
        }
        return val + slope * (lst - r[0]);
    }
    assert(false);
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    l.resize(n);
    r.resize(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a >> l[i] >> r[i];
        l[i] -= a;
        r[i] -= a;
    }
    LL le = -2E9, ri = 2E9;
    while (ri - le >= 4) {
        LL md = (le + ri) / 2;
        if (work(md) < work(md + 1)) ri = md + 1;
        else le = md;
    }
    LL ans = 1E18;
    for (LL i = le; i <= ri; ++i) ans = min(ans, work(i));
    cout << ans << "\n";
    return 0;
}