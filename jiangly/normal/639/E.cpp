#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> p(n), t(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    vector<int> perm_e(n), perm_p(n);
    iota(perm_e.begin(), perm_e.end(), 0);
    iota(perm_p.begin(), perm_p.end(), 0);
    sort(perm_e.begin(), perm_e.end(), [&](int i, int j) {return 1LL * p[i] * t[j] > 1LL * p[j] * t[i];});
    sort(perm_p.begin(), perm_p.end(), [&](int i, int j) {return p[i] < p[j];});
    vector<double> mn(n), mx(n);
    LL total = accumulate(t.begin(), t.end(), 0LL);
    
    double l = 0, r = 1;
    for (int i = 0; i < 25; ++i) {
        double c = (l + r) / 2;
        LL sum_t = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            LL res = 0;
            while (j < n && 1LL * p[perm_e[i]] * t[perm_e[j]] == 1LL * p[perm_e[j]] * t[perm_e[i]]) {
                mx[perm_e[j]] = p[perm_e[j]] * (1 - c * (sum_t + t[perm_e[j]]) / total);
                res += t[perm_e[j]];
                ++j;
            }
            sum_t += res;
            while (i < j) {
                mn[perm_e[i]] = p[perm_e[i]] * (1 - c * sum_t / total);
                ++i;
            }
        }
        double m = 0;
        bool ok = true;
        for (int i = 0; i < n; ) {
            int j = i;
            double res = 0;
            while (j < n && p[perm_p[j]] == p[perm_p[i]]) {
                if (mn[perm_p[j]] < m)
                    ok = false;
                res = max(res, mx[perm_p[j]]);
                ++j;
            }
            m = max(m, res);
            i = j;
        }
        if (ok)
            l = c;
        else
            r = c;
    }
    
    cout << setprecision(7) << fixed << l << endl;
    return 0;
}