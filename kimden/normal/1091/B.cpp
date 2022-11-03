#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;




int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> x(n), y(n), a(n), b(n);
    map<pll, int> mp;
    for( int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ++mp[{x[i] + a[j], y[i] + b[j]}];
        }
    }
    for(auto x: mp) {
        if(x.second == n) {
            cout << x.first.first << " " << x.first.second << endl;
            return 0;
        }
    }
}