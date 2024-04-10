 #include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
// #include <algorithm>
using namespace std;

#define f first
#define s second
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

const int maxn = (int) 3e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
//const int pp = 41;
const int inf = 2e9;
const ll llinf = 1e18;

ll s[maxn];
struct node {
    ll mn, delta;
    node() {
        mn = 0;
        delta = 0;
    }
} tree[4 * maxn];

void push(int v) {
    if (tree[v].delta) {
        tree[v<<1].delta += tree[v].delta;
        tree[v<<1|1].delta += tree[v].delta;
        tree[v<<1].mn += tree[v].delta;
        tree[v<<1|1].mn += tree[v].delta;
        tree[v].delta = 0;
    }
}

void dec(int v, int tl, int tr, int l, int r, ll x) {
    if (l > r) return;
    if (tl == l && tr == r) {
        tree[v].delta -= x;
        tree[v].mn -= x;
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v);
    dec(v<<1, tl, tm, l, min(r, tm), x);
    dec(v<<1|1, tm + 1, tr, max(l, tm + 1), r, x);
    tree[v].mn = min(tree[v<<1].mn, tree[v<<1|1].mn);
}

pair<ll, int> get(int v, int tl, int tr) {
    if (tl == tr) {
        ll ans = llinf;
        swap(ans, tree[v].mn);
        return {ans, tl};
    }
    int tm = (tl + tr) >> 1;
    push(v);
    pair<ll, int> res;
    if (tree[v<<1|1].mn == 0) {
        res = get(v<<1|1, tm + 1, tr);
    } else {
        res = get(v<<1, tl, tm);
    }
    tree[v].mn = min(tree[v<<1].mn, tree[v<<1|1].mn);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);

    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        dec(1, 0, n - 1, i, i, -s[i]);
    }

    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        auto e = get(1, 0, n - 1);
        // cout << e.first << ' ' << e.second << endl;
        ans[e.second] = i;
        dec(1, 0, n - 1, e.second, n - 1, i);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}