// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, q;
int w0[30005], h0[30005];
int w1[30005], h1[30005];

vector<int> invert(const vector<int>& p) {
    vector<int> q = p;
    for (int i : ra(0, n)) q[p[i]] = i;
    return q;
}

const ll inf = 1e18;

ll ta(int i, int j) {
    return w1[i] * 1ll * h1[j];
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> q;
    const auto N = ra(0, n);
    for (int i : N) cin >> w0[i];
    for (int i : N) cin >> h0[i];

    vector<int> p0(n);
    iota(begin(p0), end(p0), 0);
    R::sort(p0, [&](int i, int j) {
        return w0[i] < w0[j];
    });
    auto p0inv = invert(p0);

    for (int i : N) {
        w1[i] = w0[p0[i]];
        h1[i] = h0[p0[i]];
    }

    auto p1 = p0;
    R::sort(p1, [&](int i, int j) {
        return h1[i] < h1[j];
    });

    sort(h1, h1+n);    
    vector<int> banned = invert(p1);
    // bear i is banned from using horse banned[i]
    // because he owns it

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        x = p0inv[x];
        y = p0inv[y];
        // swap something?
        swap(banned[x], banned[y]);

        // dp
        {
            ll w = -inf, x = -inf, y = 0;
            for (int i : N) {
                ll z = -inf;
                // single
                if (i != banned[i]) z = max(z, y + ta(i, i));
                // double
                if (i && i != banned[i-1] && i-1 != banned[i]) z = max(z, x + ta(i, i-1) + ta(i-1, i));
                // triple
                if (i >= 2 && i != banned[i-1] && i-1 != banned[i-2] && i-2 != banned[i]) {
                    z = max(z, w + ta(i-1, i) + ta(i-2, i-1) + ta(i, i-2));
                }
                if (i >= 2 && i-1 != banned[i] && i-2 != banned[i-1] && i != banned[i-2]) {
                    z = max(z, w + ta(i, i-1) + ta(i-1, i-2) + ta(i-2, i));
                }

                w = x;
                x = y;
                y = z;
            }

            cout << y << '\n';
        }
    }
}