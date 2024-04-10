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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

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

const int md = 1e9 + 7;


inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, ll b) {
    int res = 1;
    for(; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

struct Node {
    Node *l, *r;
    int c;

    Node() : l(nullptr), r(nullptr), c(-1) {}
};

void add(Node *&r, ll b, ll v, ll x, int d) {
    if (!r) r = new Node();
    if (v == x) {
        r->c = d;
        return;
    }
    if (b & x) {
        add(r->r, b >> 1ll, v << 1ll | 1ll, x, d);
    } else {
        add(r->l, b >> 1ll, v << 1ll, x, d);
    }
}

ar<int, 3> dfs(Node *v, ll b) {
    if (!v) {
        int res = 2;
        res = mul(res, binpow(4, b - 2));
        return {res, res, res};
    }
    if (b == 2) {
        ar<int, 3> res = {0, 0, 0};
        res[v->c]++;
        return res;
    }
    ar<int, 3> res = {0, 0, 0};
    auto dp1 = dfs(v->l, b / 2);
    auto dp2 = dfs(v->r, b / 2);
    rep(i, 3) {
        rep(j, 3) {
            int kek = mul(dp1[i], dp2[j]);
            rep(t, 3) {
                if (v->c != -1 && v->c != t) continue;
                if (i == t || j == t) continue;
                res[t] = add(res[t], kek);
                if (v->c == -1) res[t] = add(res[t], kek);
            }
        }
    }
    return res;
}

void solve() {
    Node *root = nullptr;
    ll k, n; cin >> k >> n;
    rep(_, n) {
        ll v; cin >> v;
        string s; cin >> s;
        int c = -1;
        if (s[0] == 'y' || s[0] == 'w') {
            c = 0;
        } else if (s[0] == 'g' || s[0] == 'b') {
            c = 1;
        } else {
            c = 2;
        }
        ll t = 1;
        while(t <= v) t *= 2;
        t /= 2;
        t /= 2;
        add(root, t, 1, v, c);
    }
    auto res = dfs(root, 1ll << k);
    cout << add(add(res[0], res[1]), res[2]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}