#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;



int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }
    sort(rall(a));
    sort(all(b));
    if (b[0] < a[0]) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i];
    }
    ans *= m;
    if (b[0] == a[0]) {
        for (int i = 1; i < m; ++i) {
            ans += b[i] - a[0];
        }
    } else {
        if (n == 1) {
            cout << -1 << endl;
            return 0;
        }
        for (int i = 1; i < m; ++i) {
            ans += b[i] - a[0];
        }
        ans += b[0] - a[1];
    }
    cout << ans << endl;

}