#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = -1;



int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (cin >> n) {
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;

        int t;
        cin >> t;
        vector<ll> p(t);
        for (int i = 0; i < t; i++) cin >> p[i];
        p.push_back((ll)(1e18));

        sort(a.begin(), a.end());

        ll ans = 0;
        ll cur = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (a[i].second > 0) {
                ll x = min((ll)a[i].second, p[j] - cur);
                ans += x * a[i].first * (j + 1);
                a[i].second -= x;
                cur += x;
                if (cur == p[j]) j++;
            } 
        }
        cout << ans << endl;
    }

    return 0;
}