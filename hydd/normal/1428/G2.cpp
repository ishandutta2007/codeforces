#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int V = 1e6;

int main() {
    int k = 0;
    cin >> k;
    k = 3 * (k - 1);
    array<int, 6> p{};
    array<ll, 1100000> f{};

    for (int i = 0; i <= 5; i++)
        cin >> p[i];
    for (int i = 0; i <= 1000000; i++) {
        int x = i;
        for (int pos = 0; x; pos++) {
            if ((x % 10) % 3 == 0) f[i] += 1ll * p[pos] * ((x % 10) / 3);
            x /= 10;
        }
    }

    auto upd = [&f](int v, ll w) {
        for (int i = V; i >= v; i--) f[i] = max(f[i], w + f[i - v]);
    };

    auto update = [&k, &upd](int v, int w) {
        int tot = min(k, 1000000 / v);
        for (int i = 1; i < tot; i <<= 1) {
            tot -= i;
            upd(v * i, 1ll * w * i);
        }
        upd(v * tot, 1ll * w * tot);
    };

    int val = 3;
    for (int i = 0; i <= 5; i++) {
        update(val, p[i]);
        val *= 10;
    }

    int q = 0, x = 0;
    cin >> q;
    while (q--) {
        cin >> x;
        cout << f[x] << '\n';
    }
    return 0;
}