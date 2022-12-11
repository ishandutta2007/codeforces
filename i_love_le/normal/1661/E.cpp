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
const int LG = 100;

struct dsu {
    vector<int> dsu;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        range(i, n)dsu[i] = i;
    }

    bool unio(int a, int b) {
        if (a == -1 || b == -1) return false;
        a = get_dsu(a), b = get_dsu(b);
        if (a == b) return false;
        if (rand() % 2) {
            swap(a, b);
        }
        dsu[a] = b;
        return true;
    }
};

struct FSegTree {
    struct Node {
        ar<int, 3> comp[2];
        int ans;

        Node() {
            rep(i, 2) rep(j, 3) comp[i][j] = -1;
            ans = -1;
        }

        void compress() {
            vi have;
            rep(i, 2) rep(j, 3) if (comp[i][j] != -1) have.push_back(comp[i][j]);
            sort(all(have));
            have.resize(unique(all(have)) - have.begin());
            rep(i, 2) rep(j, 3) if (comp[i][j] != -1)
                        comp[i][j] =
                                lower_bound(all(have), comp[i][j]) -
                                have.begin();
        }

        void combine(const Node &a, const Node &b) {
            if (a.ans == -1) {
                ans = b.ans;
                rep(i, 2) rep(j, 3) comp[i][j] = b.comp[i][j];
                return;
            }
            if (b.ans == -1) {
                ans = a.ans;
                rep(i, 2) rep(j, 3) comp[i][j] = a.comp[i][j];
                return;
            }
            ans = a.ans + b.ans;
            dsu d;
            d.build(12);
            rep(j, 3) {
                if (b.comp[0][j] == -1 || a.comp[1][j] == -1) continue;
                if (d.unio(a.comp[1][j], b.comp[0][j] + 6)) ans--;
            }
            rep(j, 3) {
                if (a.comp[0][j] == -1) comp[0][j] = -1;
                else comp[0][j] = d.get_dsu(a.comp[0][j]);
                if (b.comp[1][j] == -1) comp[1][j] = -1;
                else comp[1][j] = d.get_dsu(b.comp[1][j] + 6);
            }
            compress();
        }

        void apply(int mask) {
            int last = -1;
            int ct = 0;
            rep(i, 3) {
                if (mask & (1 << i)) {
                    if (last == -1) {
                        comp[0][i] = comp[1][i] = ct++;
                    } else {
                        comp[0][i] = comp[1][i] = last;
                    }
                }
                last = comp[0][i];
            }
            ans = ct;
        }
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
    int n; cin >> n;
    vi a(n);
    rep(i, 3) {
        rep(j, n) {
            char x; cin >> x;
            if (x == '1') a[j] |= (1 << i);
        }
    }
    FSegTree st;
    st.build(a);
    int q; cin >> q;
    rep(_, q) {
        int l, r; cin >> l >> r;
        cout << st.get(l - 1, r).ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}