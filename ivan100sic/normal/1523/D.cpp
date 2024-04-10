// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
using uid = uniform_int_distribution<ll>;
using urd = uniform_real_distribution<double>;

int n, m, p;
ll a[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> p;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            if (s[j] == '1') {
                a[i] += 1ll << j;
            }
        }
    }

    int reps = 13;
    ll sol = 0;
    while (reps--) {
        int id = uid(0, n-1)(eng);

        ll base = a[id];
        int w = bitset<64>(base).count();
        map<ll, ll> mp;
        vector<ll> inv(1 << w);
        mp[0] = 0;
        for (ll x=base, y=(1ll<<w)-1; x; x=(x-1)&base, y--) {
            mp[x] = y;
            inv[y] = x;
        }

        vector<int> c(1 << w);
        for (int i=0; i<n; i++) {
            c[mp[a[i] & base]]++;
        }

        for (int i=0; i<w; i++) {
            for (int j=0; j<(1<<w); j++) {
                if (j & (1 << i)) {
                    c[j - (1 << i)] += c[j];
                }
            }
        }

        for (int i=0; i<(1<<w); i++) {
            if (c[i] >= (n+1) / 2) {
                if (bitset<64>(inv[i]).count() > bitset<64>(sol).count()) {
                    sol = inv[i];
                }
            }
        }
    }

    for (int i=0; i<m; i++) {
        cout << (1 & (sol >> i));
    }
    cout << '\n';
}