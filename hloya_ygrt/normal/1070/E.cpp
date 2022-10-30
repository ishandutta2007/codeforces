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

const int maxn = (int) 2e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
const int pp = 41;

#define next ajksdslk

ll tree[4 * maxn];
int cnt[4 * maxn];

int a[maxn];

int n, m;
ll t;

void on(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        tree[v] = a[tl];
        cnt[v] = 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        on(v<<1, tl, tm, pos);
    else
        on(v<<1|1, tm + 1, tr, pos);
    tree[v] = tree[v<<1] + tree[v<<1|1];
    cnt[v] = cnt[v<<1] + cnt[v<<1|1];
}

pair<ll, int> get_sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return mp(0, 0);
    if (tl == l && tr == r) return mp(tree[v], cnt[v]);
    int tm = (tl + tr) >> 1;
    auto a = get_sum(v<<1, tl, tm, l, min(r, tm));
    auto b = get_sum(v<<1|1, tm + 1, tr, max(l, tm + 1), r);
    return mp(a.fst + b.fst, a.snd + b.snd);
}

ll sum_first(int v, int tl, int tr, int need) {
    assert(tl <= tr && cnt[v] >= need);
    if (need == 0) return 0;
    if (cnt[v] == need) return tree[v];
    int tm = (tl + tr) >> 1;
    if (cnt[v<<1] > need) {
        return sum_first(v<<1, tl, tm, need);
    }
    return tree[v<<1] + sum_first(v<<1|1, tm + 1, tr, need - cnt[v<<1]);
}

bool can(int c) {
    pair<ll, int> kek = get_sum(1, 0, n - 1, 0, c);
    if (kek.snd == 0)
        return true;
//    cout << kek.fst << ' ' << kek.snd << endl;
    int full_blocks = kek.snd / m;
//    cout << full_blocks << endl;
    ll kek_sum, rest_sum;
    if (full_blocks * m != kek.snd) {
         kek_sum = sum_first(1, 0, n - 1, full_blocks * m);
    //    cout << kek_sum << endl;
         rest_sum = kek.fst - kek_sum;

    } else {
         kek_sum = sum_first(1, 0, n - 1, (full_blocks - 1) * m);
         rest_sum = sum_first(1, 0, n - 1, full_blocks * m);
        rest_sum -= kek_sum;
    }
    return kek_sum * 2 + rest_sum <= t;
}

int get_ans() {
    int l = 0, r = n - 1;
//    cout << can(2) << endl;
//    can(2);
//    exit(0);
    while (l < r) {
        int c = (l + r + 1) >> 1;
        if (can(c))
            l = c;
        else
            r = c - 1;
    }
    if (can(l))
        return get_sum(1, 0, n - 1, 0, l).snd;
    return 0;
}

void solve() {
    cin >> n >> m >> t;
    for (int i = 0; i <= 4 * n; i++)
        tree[i] = 0, cnt[i] = 0;
    // clear tree
    vector<pair<int, int> > p;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p.pb(mp(a[i], i));
    }
    sort(all(p));

    int ans = -1;
    int kek_res;
    for (int i = 0; i < p.size(); ) {
        int j = i;
        on(1, 0, n - 1, p[i].snd);
        while (j + 1 < p.size() && p[j + 1].fst == p[j].fst) {
            j++;
            on(1, 0, n - 1, p[j].snd);
        }

        int cur_ans = get_ans();
        if (cur_ans > ans) {
            ans = cur_ans;
            kek_res = p[i].fst;
        }

//        ans = max(ans, get_ans());

        i = j + 1;
    }

    if (ans == 0) {
          kek_res = 1;
    }

    cout << ans << ' ' << kek_res << "\n";
}

int main() {
//    freopen ("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
    return 0;
}