#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    ll ans = 0;
    vector<ll> x, y, v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++) {
        ll g;
        cin >> g;
        ans += g;
        if(v[i] == 0) x.push_back(g);
        else y.push_back(g);
    }
    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());
    if(x.size() > y.size()) swap(x, y);
    if(x.size() == y.size()) {
        ans *= 2;
        ans -= min(x[x.size() - 1], y[y.size() - 1]);
    }
    else {
        for(int i = 0; i < x.size(); i++) {
            ans += (x[i] + y[i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}