#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1'000'000'007;
const ll i2 = mod + 1 >> 1;

vector<ll> p2;
struct state {
    int b0, b1, w0, w1;
    bool operator<(const state& o) const {
        if (b0 != o.b0) return b0 < o.b0;
        if (b1 != o.b1) return b1 < o.b1;
        if (w0 != o.w0) return w0 < o.w0;
        if (w1 != o.w1) return w1 < o.w1;
        return false;
    }
    bool operator==(const state& o) const {
        if (b0 != o.b0) return false;
        if (b1 != o.b1) return false;
        if (w0 != o.w0) return false;
        if (w1 != o.w1) return false;
        return true;
    }
    int size() const {
        return b0 + b1 + w0 + w1;
    }
    int parity() const {
        return b1 + w1 & 1;
    }
};

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    int nn = n << 5;
    p2 = vector<ll>(nn);
    p2[0] = 1;
    for (int i = 1; i < nn; i++) p2[i] = (p2[i - 1] << 1) % mod;
    map<state, ll> states;
    states[{0, 0, 0, 0}] = 1;
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        map<state, ll> nstates;
        for (auto it : states) {
            const state& s = it.first;
            ll nct = it.second % mod * p2[s.size()] % mod * i2 % mod;
            for (int x = 0; x < 2; x++) {
                if (v == 0 || v == -1) {
                    int nb0 = s.b0 + (min(x, s.w1) == 1);
                    int nb1 = s.b1 + (min(x, s.w1) == 0);
                    int nw0 = s.w0;
                    int nw1 = s.w1;
                    nstates[{nb0, nb1, nw0, nw1}] += nct;
                }
                if (v == 1 || v == -1) {
                    int nw0 = s.w0 + (min(x, s.b1) == 1);
                    int nw1 = s.w1 + (min(x, s.b1) == 0);
                    int nb0 = s.b0;
                    int nb1 = s.b1;
                    nstates[{nb0, nb1, nw0, nw1}] += nct;
                }
            }
        }
        states = nstates;
    }
    ll ans = 0;
    for (auto it : states) {
        if (it.first.parity() == p) {
            ans += it.second;
        }
    }
    if ((ans %= mod) < 0) ans += mod;
    printf("%lld\n", ans);
}