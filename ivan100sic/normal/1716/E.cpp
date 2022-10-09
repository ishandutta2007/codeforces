// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct maxsum {
    ll l, r, s, a;

    maxsum() : l(0), r(0), s(0), a(0) {}
    
    maxsum(ll x) {
        l = r = a = max(x, 0ll);
        s = x;
    }

    maxsum operator+ (const maxsum& b) const {
        maxsum c;
        c.l = max(l, s + b.l);
        c.r = max(b.r, b.s + r);
        c.s = s + b.s;
        c.a = max({a, b.a, r + b.l});
        return c;
    }
};

int lg2n, n, lg2_block;
int a[1 << 18];
vector<vector<maxsum>> blocks[9];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> lg2n;
    n = 1 << lg2n;
    for (int i : ra(0, n)) cin >> a[i];

    lg2_block = min(8, lg2n);

    // level 0
    blocks[0].resize(1);
    blocks[0][0].resize(n);
    for (int i : ra(0, n)) {
        blocks[0][0][i] = maxsum(a[i]);
    }

    for (int lvl=1; lvl<=lg2_block; lvl++) {
        blocks[lvl].resize(1 << lvl);
        const int low_mask = (1 << (lvl - 1)) - 1;
        const int high_bit = 1 << (lvl - 1);
        for (int mask : ra(0, 1 << lvl)) {
            blocks[lvl][mask].resize(n >> lvl);
            for (int i : ra(0, n >> lvl)) {
                auto bl = blocks[lvl-1][mask & low_mask][2*i+0];
                auto br = blocks[lvl-1][mask & low_mask][2*i+1];
                
                if (mask & high_bit) {
                    swap(bl, br);
                }

                blocks[lvl][mask][i] = bl + br;
            }
        }
    }

    int total = 0;
    const int low_mask = (1 << lg2_block) - 1;
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        total ^= 1 << k;

        maxsum sum;
        for (int i : ra(0, n >> lg2_block)) {
            sum = sum + blocks[lg2_block][total & low_mask][i ^ (total >> lg2_block)];
        }

        cout << sum.a << '\n';
    }
}