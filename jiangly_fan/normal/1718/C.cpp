#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i += 1)
            cin >> a[i];
        int m = n;
        vector<vector<LL>> v;
        for (int i = 2; i <= m; i += 1)
            if (m % i == 0) {
                v.push_back(vector<LL>(n / i));
                while (m % i == 0) m /= i;
            }
        if (m > 1) v.push_back(vector<LL>(n / m));
        vector<multiset<LL, greater<LL>>> vms(v.size());
        for (int i = 1; i <= n; i += 1)
            for (int j = 0; j < v.size(); j += 1) {
                int d = v[j].size();
                v[j][i % d] += a[i];
            }
        for (int i = 0; i < v.size(); i += 1)
            for (LL vij : v[i]) vms[i].insert(vij);
        auto ans = [&](){
            LL res = 0;
            for (int i = 0; i < v.size(); i += 1)
                res = max(res, *vms[i].begin() * (int)v[i].size());
            return res;
        };
        cout << ans() << "\n";
        for (int i = 0, p, x; i < q; i += 1) {
            cin >> p >> x;
            for (int j = 0; j < v.size(); j += 1) {
                int d = v[j].size();
                vms[j].erase(vms[j].find(v[j][p % d]));
                v[j][p % d] -= a[p];
            }
            a[p] = x;
            for (int j = 0; j < v.size(); j += 1) {
                int d = v[j].size();
                v[j][p % d] += a[p];
                vms[j].insert(v[j][p % d]);
            }
            cout << ans() << "\n";
        }
    }
}