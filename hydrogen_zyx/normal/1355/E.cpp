#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, r, m;
ll h[100010];
ll cal(ll k) {
    ll shao = 0, duo = 0, cost = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] > k)
            duo += h[i] - k;
        else
            shao += k - h[i];
    }
    if (m < a + r) {
        ll mmin = min(duo, shao);
        duo -= mmin;
        shao -= mmin;
        cost += mmin * m;
    }
    cost += duo * r;
    cost += shao * a;
    return cost;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> a >> r >> m;
    for (ll i = 0; i < n; i++) cin >> h[i];
    ll l = 0, r = 1000000000, m1, m2;
    while (l < r) {
        m1 = (l * 2 + r) / 3;
        m2 = (2 * r + l + 2) / 3;
        if (cal(m1) > cal(m2))
            l = m1 + 1;
        else
            r = m2 - 1;
    }
    cout << cal(l);
}