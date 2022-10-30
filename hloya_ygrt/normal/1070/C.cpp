//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }

#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }


typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 1e6 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
const int pp = 41;

#define next ajksdslk

const ll llinf = 2e18;

struct node {
    ll mn;
    int posmn;
    int sum;
    ll push;
    node() {
        sum = 0;
        mn = llinf;
        posmn = -1;
        push = 0;
    }
};

node tree[4 * maxn];

node combine(node& a, node& b) {
    node res;
    res.mn = min(a.mn, b.mn);
    if (a.mn < b.mn)
        res.posmn = a.posmn;
    else
        res.posmn = b.posmn;
    res.sum = a.sum + b.sum;
    return res;
}

void push(int v) {
    if ((v << 1) < 4 * maxn && tree[v].push) {
        ll d = tree[v].push;
        tree[v << 1].mn -= d;
        tree[v<<1|1].mn -= d;
        tree[v << 1].push += d;
        tree[v<<1|1].push += d;
        tree[v].push = 0;
    }
}

int n, k, m;
ll ans = 0;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].sum = 1;
        tree[v].mn = k;
        tree[v].posmn = tl;
        tree[v].push = 0;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v<<1, tl, tm);
    build(v<<1|1, tm + 1, tr);
    tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

pair<ll, int> get_min(int v, int tl, int tr, int l, int r) {
    if (l > r) return mp(llinf, -1);
    if (tl == l && tr == r)
        return mp(tree[v].mn, tree[v].posmn);
    push(v);
    int tm = (tl + tr) >> 1;

    return min(
        get_min(v<<1, tl, tm, l, min(r, tm)),
        get_min(v<<1|1, tm + 1, tr, max(l, tm + 1), r)
    );
}

void st(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        tree[v].mn = llinf;
        tree[v].sum = 0;
        tree[v].posmn = -1;
        tree[v].push = 0;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        st(v<<1, tl, tm, pos);
    else
        st(v<<1|1, tm + 1, tr, pos);
    tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

int get_sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) return tree[v].sum;
    int tm = (tl + tr) >> 1;
    return get_sum(
        v<<1, tl, tm, l, min(r, tm)
    ) + get_sum(
        v<<1|1,
        tm + 1, tr, max(l, tm + 1), r
    );
}

void decc(int v, int tl, int tr, int l, int r, int c) {
    if (l > r) return;
    if (tl == l && tr == r) {
        tree[v].mn -= c;
        tree[v].push += c;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    decc(v<<1, tl, tm, l, min(r, tm), c);
    decc(v<<1|1, tm + 1, tr, max(l, tm + 1), r, c);
    tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);

    cin >> n >> k >> m;

    vector<pair<int, pair<int, pair<int, int> > > > q;
    for (int i = 0; i < m; i++) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        l--, r--;
        q.pb(mp(p, mp(c, mp(l, r))));
    }

    build(1, 0, n - 1);

    sort(all(q));

    for (int i = 0; i < q.size(); i++) {
        int p = q[i].fst, c = q[i].snd.fst, l = q[i].snd.snd.fst, r = q[i].snd.snd.snd;
        pair<ll, int> wst;
        while (1) {
            wst = get_min(1, 0, n - 1, l, r);
            if (wst.fst < c) {
                ans += 1ll * wst.fst * p;
                st(1, 0, n - 1, wst.snd);
            } else break;
        }
        ans += 1ll * p * c * get_sum(1, 0, n - 1, l, r);
        decc(1, 0, n - 1, l, r, c);
    }
    cout << ans << "\n";
    return 0;
}