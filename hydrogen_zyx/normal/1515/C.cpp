#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
ll a[N], b[N];

signed main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, x;
        cin >> n >> m >> x;
        for (ll i = 1; i <= n; i++) cin >> a[i];
        priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > que;
        for (ll i = 1; i <= m; i++) que.push(pair<ll, ll>(0, i));
        for (ll i = 1; i <= n; i++) {
            pair<ll, ll> p = que.top();
            que.pop();
            p.first += a[i];
            b[i] = p.second;
            que.push(p);
        }
        cout << "YES" << endl;
        for (ll i = 1; i <= n; i++) cout << b[i] << ' ';
        cout << endl;
    }
}