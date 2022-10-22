#include<bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    int x1, y1;
    int g = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<long long> ans(n + 1);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += b[i];
        a[i] -= b[i];
    }
    sort(a.rbegin(), a.rend());
    ans[0] = sum;
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + a[i - 1];
    }
    int pos = 0;
    while (pos + 1 <= n && ans[pos + 1] >= ans[pos]) {
        pos++;
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int x2, y2;
        int g = gcd(x, y, x2, y2);
        //cout << x << " " << y << " " << x2 << " " << y2 << endl;
        if (n % g != 0) {
            cout << -1 << '\n';
            continue;
        }
        int d = n / g;
        x2 *= d, y2 *= d;
        x2 *= x;
        int upd = y / g * x;
        //cout << x2 << " " << y2 << " " << upd << endl;
        if (x2 <= pos) {
            int cnt = (pos - x2) / upd;
            x2 += upd * cnt;
        } else {
            int cnt = (x2 - pos) / upd;
            x2 -= cnt * upd;
            if (x2 > pos) {
                x2 -= upd;
            }
        }
        long long res = (long long) -1e18;
        //cout << x2 << endl;
        for (auto v : {x2, x2 + upd}) {
            if (v >= 0 && v <= n) {
                res = max(res, ans[v]);
            }
        }
        if (res == (long long) -1e18) {
            cout << -1 << '\n';
            continue;
        }
        //assert(res != (long long) -1e18);
        cout << res << endl;
    }
}