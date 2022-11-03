#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> p(n + 5, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++p[a[i]];
        }
        for (int i = 1; i < p.size(); ++i) {
            p[i] += p[i - 1];
        }
        int required = (k + n + 1) / 2;
        int best = 998244353;
        int xx = -1;
        int yy = -1;
        for (int x = 1; x <= n; ++x) {
            int y = lower_bound(p.begin(), p.end(), required + p[x - 1]) - p.begin();
            if (y > n) {
                continue;
            }
            if (best > y - x) {
                best = y - x;
                xx = x;
                yy = y;
            }
        }
        cout << xx << " " << yy << "\n";
        int max_bal = 0;
        int bal = 0;
        vector<int> l = {-1};
        vector<int> r = {-1};
        for (int i = 0; i < n; ++i) {
            if (a[i] >= xx && a[i] <= yy) {
                ++bal;
            } else {
                --bal;
            }
            if (max_bal < bal) {
                max_bal = bal;
                if (max_bal <= k) {
                    l.push_back(r.back() + 1);
                    r.push_back(i);
                }
            }
        }
        r.back() = n - 1;
        for (int i = 1; i <= k; ++i) {
            cout << l[i] + 1 << " " << r[i] + 1 << "\n";
        }
    }

}