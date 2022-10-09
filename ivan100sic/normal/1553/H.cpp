// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int inf = 1e9;

struct the_tree {
    struct node {
        struct kec {};
        struct nula {};
        int l, r, s, g;

        node() : l(-1), r(-1), s(0), g(1e9) {}
        node(kec) : l(0), r(0), s(1), g(1e9) {}
        node(nula) : l(-1), r(-1), s(1), g(1e9) {}
        node(int l, int r, int s, int g) : l(l), r(r), s(s), g(g) {}

        node operator+ (const node& b) const {
            if (l == -1 && b.l == -1) {
                return node{-1, -1, s + b.s, inf};
            } else if (l == -1) {
                return {s + b.l, s + b.r, s + b.s, b.g};
            } else if (b.l == -1) {
                return {l, r, s + b.s, g};
            } else {
                return {l, s + b.r, s + b.s, min({g, b.g, s + b.l - r})};
            }
        }
    };

    vector<node> a;
    vector<int> fl;
    int k, n;

    the_tree(int k, const vector<int>& b) {
        this->k = k;
        n = 1 << k;
        a.resize(2*n, node::nula());
        fl.resize(k);
        for (int x : b) {
            a[x+n] = node::kec();
        }
        for (int i=n-1; i; i--) a[i] = a[2*i] + a[2*i+1];
    }

    int operator() () const {
        return a[1].g;
    }

    void fetch(int x) {
        if (x >= n) return;
        int lvl = k - 1 - (31 - __builtin_clz(x));

        if (fl[lvl]) {
            a[x] = a[2*x+1] + a[2*x];
        } else {
            a[x] = a[2*x] + a[2*x+1];
        }
    }

    void flip(int b) {
        fl[b] ^= 1;
        for (int x=(1<<(k-b))-1; x; x--) {
            fetch(x);
        }
    }
};

int n, k;
int ans[1 << 19];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    the_tree drvo(k, a);
    ans[0] = drvo();

    for (int i=1, mask=0; i<(1<<k); i++) {
        int b = k - 1 - __builtin_ctz(i);
        // cerr << mask << ' ' << b << '\n';
        mask ^= 1 << b;
        drvo.flip(b);
        ans[mask] = drvo();
    }
    
    for (int i=0; i<(1<<k); i++) {
        cout << ans[i] << " \n"[i == (1<<k) - 1];
    }
}