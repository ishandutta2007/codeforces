#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using int128 = __int128;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 4e5 + 10;
const int LG = 17;
const int md = 998244353;

struct FSegTree {
    struct Node {
        int value;

        void apply(int x) {
            value = max(value, x);
        }

        void combine(const Node &a, const Node &b) {
            value = max(a.value, b.value);
        }

        Node() : value(-INFi) {}
    };

    Node combine(const Node &a, const Node &b) {
        Node res;
        res.combine(a, b);
        return res;
    }

    vector<Node> t;
    int n;

    template<typename T>
    void build(vector<T> &v) {
        n = v.size();
        t.resize(n * 2);
        range(i, n) t[i + n].apply(v[i]);
        for (int i = n - 1; i >= 1; --i) t[i].combine(t[i << 1], t[i << 1 | 1]);
    }

    void upd(int i, int x) {
        for (t[i += n].apply(x); i > 1; i >>= 1) t[i >> 1].combine(t[i], t[i ^ 1]);
    }

    // [l, r)
    Node get(int l, int r) {
        Node resultL, resultR;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resultL = combine(resultL, t[l++]);
            if (r & 1) resultR = combine(t[--r], resultR);
        }
        return combine(resultL, resultR);
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    FSegTree stm, stp;
    vi kek(n + 1, -INFi);
    stm.build(kek);
    stp.build(kek);
    vl b(n + 1);
    rep(i, n) b[i + 1] = b[i] + a[i];
    sort(all(b));
    vi c(n + 1);
    ll v = 0;
    rep(i, n + 1) {
        c[i] = lower_bound(all(b), v) - b.begin();
        if (i != n) v += a[i];
    }
    stp.upd(c[0], 0);
    stm.upd(c[0], 0);
    vi d(n + 1, -INFi);
    d[c[0]] = 0;
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        int val = d[c[i]];
        int x = c[i];
        if (x > 0) {
            val = max(val, i + stm.get(0, x).value);
        }
        if (x < n) {
            val = max(val, stp.get(x + 1, n + 1).value - i);
        }
        assert(-n <= val && val <= n);
        d[x] = val;
        stp.upd(x, val + i);
        stm.upd(x, val - i);
        res = val;
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}