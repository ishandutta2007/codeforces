// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ull generic_hash(ull x) {
    return x;
    // return ((x ^ 4'354'537'817'845'147'851ull) * 435783457854780781ull) ^ 4'574'691'568'685'398'581ull;
}

ull cool_hash(int x, int i, int b) {
    return generic_hash(
        ((ull(x ^ i) >> (b + 1)) << 32) | (b << 2) | ((x >> b) & 1) | (((i >> b) & 1) << 1)
    );
}

ull target_hash(int x, int i, int b) {
    return generic_hash(
        ((ull(x ^ i) >> (b + 1)) << 32) | (b << 2) | ((i >> b) & 1) | ((((x >> b) & 1) ^ 1) << 1)
    );
}

void mx(int& x, int y) {
    x = max(x, y);
}

namespace screw_you {
    const int mod = 10000011;
    pair<ull, int> a[mod + 100];
    vector<int> dirty;

    int get(ull key) {
        auto pos = key % mod;
        while (1) {
            if (a[pos].second == 0) {
                return 0;
            }

            if (a[pos].first == key) {
                return a[pos].second;
            }

            pos++;
        }
    }

    void put_max(ull key, int val) {
        auto pos = key % mod;
        while (1) {
            if (a[pos].second == 0) {
                a[pos] = {key, val};
                dirty.push_back(pos);
                return;
            }

            if (a[pos].first == key) {
                mx(a[pos].second, val);
                return;
            }

            pos++;
        }
    }

    void clear() {
        for (int x : dirty) {
            a[x] = {0, 0};
        }
        dirty.clear();
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, sol = 0;
        cin >> n;
        
        for (int i : ra(0, n)) {
            int x;
            cin >> x;

            int di = 1;
            for (int b : ra(0, 30)) {
                ull h = target_hash(x, i, b);
                mx(di, screw_you::get(h) + 1);
            }

            mx(sol, di);
            for (int b : ra(0, 30)) {
                ull h = cool_hash(x, i, b);
                screw_you::put_max(h, di);
            }
        }

        cout << sol << '\n';
        screw_you::clear();
    }
}