#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    LL T;
    for (cin >> T; T; T -= 1) {
        LL n, m;
        cin >> n >> m;
        vector<LL> x(n), p(n);
        map<LL, LL> k, b;
        for (LL i = 0; i < n; i += 1) {
            cin >> x[i] >> p[i];
            k[x[i] - p[i]] += 1;
            k[x[i]] -= 1;
            b[x[i] - p[i]] -= x[i] - p[i];
            b[x[i]] += x[i] - p[i];
            k[x[i]] += -1;
            k[x[i] + p[i]] -= -1;
            b[x[i]] += p[i] + x[i];
            b[x[i] + p[i]] -= p[i] + x[i];
        }
        LL pk = 0, pb = 0, px = LLONG_MIN;
        vector<LL> xx, pp;
        for (auto [x, _] : k) {
            if (px != LLONG_MIN) {
                LL x1 = px, x2 = x - 1;
                LL y1 = pk * x1 + pb, y2 = pk * x2 + pb;
                if (y1 <= m and y2 <= m);
                else {
                    if (y1 <= m) {
                        LL L = x1, R = x2;
                        while (L < R) {
                            LL s = L + R;
                            LL M = s / 2;
                            if (s < 0) M = (s - 1) / 2;
                            if (pk * M + pb > m) R = M;
                            else L = M + 1;
                        }
                        x1 = L;
                    }
                    if (y2 <= m) {
                        LL L = x1, R = x2;
                        while (L < R) {
                            LL s = L + R;
                            LL M = (L + R + 1) / 2;
                            if (s < 0) M = s / 2;
                            if (pk * M + pb > m) L = M;
                            else R = M - 1;
                        }
                        x2 = L;
                    }
                    y1 = pk * x1 + pb, y2 = pk * x2 + pb;
                    xx.push_back(x1);
                    pp.push_back(y1);
                    if (x2 > x1) {
                        xx.push_back(x2);
                        pp.push_back(y2);
                    }
                }
            }
            px = x;
            pk += k[x];
            pb += b[x];
        }
        LL nn = xx.size();
        if (nn == 0) {
            cout << string(n, '1') << "\n";
            continue;
        }
        vector<LL> pm(nn), sm(nn);
        //pp - x <= pi - xi + m
        //pp + x <= pi + xi + m
        for (LL i = 0; i < nn; i += 1) {
            pm[i] = pp[i] - xx[i];
            if (i) pm[i] = max(pm[i], pm[i - 1]);
        }
        for (LL i = nn - 1; i >= 0; i -= 1) {
            sm[i] = pp[i] + xx[i];
            if (i + 1 < nn) sm[i] = max(sm[i], sm[i + 1]);
        }
        for (LL i = 0; i < n; i += 1) {
            LL ok = 1;
            if (xx[0] < x[i] - p[i] + 1) ok = 0;
            if (xx.back() > x[i] + p[i] - 1) ok = 0;
            LL pp = lower_bound(xx.begin(), xx.end(), x[i]) - xx.begin();
            if (pp < nn and sm[pp] > p[i] + x[i] + m) ok = 0;
            if ((pp < nn and xx[pp] > x[i]) or pp == nn) pp -= 1;
            if (pp >= 0 and pm[pp] > p[i] - x[i] + m) ok = 0;
            cout << ok;
        }
        cout << "\n";
    }
    return 0;
}