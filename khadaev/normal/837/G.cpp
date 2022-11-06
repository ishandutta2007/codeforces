#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000000;

struct Function {
    int sz;
    vector<ll> bnds, a, b;

    Function () : sz (0) {}
    Function (int x1, int x2, int y1, int _a, int _b, int y2) {
        bnds = {-1, x1, x2};
        a = {0, _a, 0};
        b = {y1, _b, y2};
        sz = 3;
    }

    ll get(ll val) {
        int pos = lower_bound(all(bnds), val) - bnds.begin() - 1;
        //cerr << "Q: ";
        //cerr << val << ' ' << a[pos] << ' ' << b[pos] << '\n';
        return a[pos] * val + b[pos];
    }

    void getInfo() {
        trace(bnds);
        trace(a);
        trace(b);
        cerr << '\n';
    }
};

Function merge(Function x, Function y) {
    if (x.sz == 0) return y;
    if (y.sz == 0) return x;
    //x.getInfo();
    //y.getInfo();
    vector<ll> bounds, as, bs;
    bounds.eb(-1);
    int i = 1, j = 1;
    while (i < x.sz || j < y.sz) {
        as.eb(x.a[i - 1] + y.a[j - 1]);
        bs.eb(x.b[i - 1] + y.b[j - 1]);
        if (i == x.sz) {
            bounds.eb(y.bnds[j]);
            ++j;
        } else if (j == y.sz) {
            bounds.eb(x.bnds[i]);
            ++i;
        } else {
            if (x.bnds[i] < y.bnds[j]) {
                bounds.eb(x.bnds[i]);
                ++i;
            } else {
                bounds.eb(y.bnds[j]);
                ++j;
            }
        }
    }
    as.eb(x.a.back() + y.a.back());
    bs.eb(x.b.back() + y.b.back());
    Function ans;
    ans.a = as;
    ans.b = bs;
    ans.bnds = bounds;
    ans.sz = bounds.size();
    //ans.getInfo();
    //cerr << '\n';
    return ans;
}

const int N = 1 << 17;
Function tree[2 * N];

void init () {
    ford(i, 1, N)
        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}

ll get(int l, int r, ll val) {
    ll ans = 0;
    l += N, r += N;
    while (l < r) {
        if (l % 2) {
            ans += tree[l].get(val);
            ++l;
        }
        if (r % 2) {
            --r;
            ans += tree[r].get(val);
        }
        l /= 2;
        r /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n) {
        int x1, x2, y1, a, b, y2;
        cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        tree[i + N] = Function(x1, x2, y1, a, b, y2);
    }
    int m;
    cin >> m;
    init();
    ll last = 0;
    forn(i, 0, m) {
        int l, r, x;
        cin >> l >> r >> x;
        x = (x + last) % MOD;
        --l;
        last = get(l, r, x);
        cout << last << '\n';
    }
}