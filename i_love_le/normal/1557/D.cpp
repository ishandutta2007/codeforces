#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
#define rep1n(i, n) for(int i = 1; i <= (n); ++i)
#define repr(i, n) for(int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for(auto &x : a)
#define ar array

using namespace std;

using ll = long long;
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

const int mxN = 2e5;
const ll INF = 1e18;
const int md = 1e9 + 7;

struct segment_tree {
    struct Node {
        pl val = {0, -INF};
        pl upd = {0, -INF};
    };

    int n{};
    vector<Node> tree{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void upd(int v, int l, int r, int lq, int rq, pl x) {
        if (l >= rq || r <= lq) return;
        tree[v].val = max(tree[v].val, x);
        if (lq <= l && r <= rq) {
            tree[v].upd = max(tree[v].upd, x);
            return;
        }
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq, x);
    }

    pl get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return {-INF, -INF};
        if (lq <= l && r <= rq) return tree[v].val;
        return max(tree[v].upd, max(get(v << 1, l, (l + r) >> 1, lq, rq),
                                    get((v << 1) + 1, (l + r) >> 1, r, lq, rq)));
    }

    void upd(int lq, int rq, pl x) {
        upd(1, 0, n, lq, rq, x);
    }

    pl get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi xx;
    vector<vpi> sg(n);
    rep(_, m) {
        int i, l, r;
        cin >> i >> l >> r;
        sg[i - 1].emplace_back(l, r);
        xx.push_back(l);
        xx.push_back(r);
    }
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());
    segment_tree st;
    st.build(xx.size());
    vl p(n);
    rep(i, n) {
        pl res = {-INF, -INF};
        for (auto &[l, r] : sg[i]) {
            l = lower_bound(all(xx), l) - xx.begin();
            r = lower_bound(all(xx), r) - xx.begin();
            res = max(res, st.get(l, r + 1));
        }
        p[i] = res.second;
        for (auto &[l, r] : sg[i]) {
            st.upd(l, r + 1, {res.first + 1, i});
        }
    }
    auto res = st.get(0, sz(xx));
    cout << n - res.first << '\n';
    vector<bool> us(n);
    ll j = res.second;
    while (j >= 0) {
        us[j] = true;
        j = p[j];
    }
    rep(i, n) if (!us[i]) cout << i + 1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}