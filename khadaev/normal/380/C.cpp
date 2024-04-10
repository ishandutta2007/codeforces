#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1 << 20;
struct vertex {
    int len, lft, rgt;

    vertex () : len(0), lft(0), rgt(0) {};
    vertex (int _len, int _lft, int _rgt) : len(_len), lft(_lft), rgt(_rgt) {};
    vertex (char c) {
        len = lft = rgt = 0;
        if (c == '(') rgt = 1;
        else lft = 1;
    }
};

vertex unite (vertex a, vertex b) {
    int nw = min(a.rgt, b.lft);
    return vertex(a.len + b.len + nw, a.lft + b.lft - nw, a.rgt + b.rgt - nw);
}

vertex tree[2 * N];

int get(int l, int r) {
    l += N, r += N;
    vertex lp, rp;
    while (l < r) {
        if (l % 2) {
            lp = unite(lp, tree[l]);
            ++l;
        }
        if (r % 2) {
            --r;
            rp = unite(tree[r], rp);
        }
        l /= 2;
        r /= 2;
    }
    return unite(lp, rp).len;
}

int main() {
    string s;
    getline(cin, s);
    int n = s.length();
    forn(i, 0, n) tree[i + N] = vertex(s[i]);
    ford(i, 1, N) tree[i] = unite(tree[2 * i], tree[2 * i + 1]);

    int m;
    scanf("%d", &m);
    forn(i, 0, m) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l;
        printf("%d\n", 2 * get(l, r));
    }
}