#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt[1000];

void jud(ll x, ll k) {
    ll ans = 0;
    ll p = 1;
    while (x) {
        cnt[p++] += x % k;
        x /= k;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        ll n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            ll a;
            cin >> a;
            jud(a, k);
        }
        bool f = 1;
        for (int i = 1; i < 1000; i++)
            if (cnt[i] > 1) f = 0;
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}