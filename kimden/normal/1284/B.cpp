#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pii> a;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        int last = 998244353;
        int fir = -1;
        bool ok = true;
        for (int j = 0; j < l; ++j) {
            int x;
            cin >> x;
            if (x > last) {
                ok = false;
            }
            if (j == 0) {
                fir = x;
            }
            last = x;
        }
        if (ok) {
            a.emplace_back(fir, last);
        }
    }
    sort(a.begin(), a.end());
    ll ans = n * (ll)n;
    for (int i = 0; i < a.size(); ++i) {
        ans -= (upper_bound(a.begin(), a.end(), make_pair(a[i].second, 998244353)) - a.begin());
    }
    cout << ans << "\n";
}