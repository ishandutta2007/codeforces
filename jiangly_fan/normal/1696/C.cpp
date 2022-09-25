#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, m, k;
        cin >> n >> m;
        vector<LL> a(n);
        for (LL& ai : a) cin >> ai;
        cin >> k;
        vector<LL> b(k);
        for (LL& bi : b) cin >> bi;
        auto f = [&](vector<LL> v) {
            vector<pair<LL, LL>> vp;
            for (LL vi : v) {
                LL c = 1;
                while (vi % m == 0) {
                    vi /= m;
                    c *= m;
                }
                if (not vp.empty() and vp.back().first == vi)
                    vp.back().second += c;
                else vp.emplace_back(vi, c);
            }
            return vp;
        };
        cout << (f(a) == f(b) ? "Yes\n" : "No\n");
    }
    return 0;
}