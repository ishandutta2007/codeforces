#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll l[1000], r[1000];
ll bit[505][505];
void add(ll d, ll k, ll x) {
    k++;
    while (k < 505) {
        bit[d][k] += x;
        k += k & -k;
    }
}

ll query(ll d, ll k) {
    k++;
    ll ans = 0;
    while (k) {
        ans += bit[d][k];
        k -= k & -k;
    }
    return ans;
}

void ad(ll d, ll l, ll r) {
    add(d, l, 1);
    add(d, r + 1, -1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    ll a = 0, b = 0;
    for (ll i = 1; i <= n; i++) {
        ll aa, bb;
        cin >> aa >> bb;
        a += aa, b += bb;
        aa = min(k - 1, aa);
        bb = min(k - 1, bb);
        if (aa + bb < k)
            l[i] = r[i] = -1;
        else {
            l[i] = k - bb;
            r[i] = aa;
        }
    }
    ad(0, 0, 0);
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < k; j++) {
            if (query(i - 1, j) != 0) {
                ad(i, j, j);
                if (l[i] == -1) continue;
                ll s = l[i] + j, e = r[i] + j;
                if (e < k) {
                    ad(i, s, e);
                } else if (s >= k) {
                    ad(i, s - k, e - k);
                } else {
                    ad(i, s, k - 1);
                    ad(i, 0, e - k);
                }
            }
        }
    }
    bool f = 0;
    if (a % k + b % k < k) f = 1;
    ll s = k - b % k;
    ll e = a % k;
    for (ll i = s; i <= e; i++) {
        if (query(n, i) != 0) f = 1;
    }
    if (f) {
        cout << (a + b) / k;
    } else {
        cout << (a + b) / k - 1;
    }
}