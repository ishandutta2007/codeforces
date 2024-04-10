#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;


//mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 6e5 + 5;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = 1e18;
const int inf = 2e9;

void add(ll& x, ll y) {
     x += y;
     if (x >= base)
        x -= base;
}

void sub(ll& x, ll y) {
     x -= y;
     if (x < 0)
        x += base;
}


ll mul(ll x, ll y) {
    return 1ll * x * y % base;
}

int a[maxn];

struct item {
    ll p, n, i, c, pi, pn;
    item() {
        p = 0, n = 0, i = 0, c = 0;
        pi = 0, pn = 0;
    }
    item(ll _p, ll _n, ll _i, ll _c) {
        p = _p, n = _n, i = _i, c = _c;
        pi = p * i;
        pn = p * n;

        // p = p % base, n = n % base, i = i % base, c = c % base;
        // pi = mul(p, i);
        // pn = mul(p, n);
    }
    item(ll _p, ll _n, ll _i, ll _c, ll _pi, ll _pn) {
        p = _p, n = _n, i = _i, c = _c;
        pi = _pi, pn = _pn;
        // p = p % base, n = n % base, i = i % base, c = c % base;
        // pi = pi % base, pn = pn % base;
    } 

    bool operator < (const item& T) const {
        return p < T.p;
    }
};

item sum(const item& a, const item& b) {
    return item(a.p + b.p, a.n + b.n, a.i + b.i, a.c + b.c, a.pi + b.pi, a.pn + b.pn);
}

item sub(const item& a, const item& b) {
    return item(a.p - b.p, a.n - b.n, a.i - b.i, a.c - b.c, a.pi - b.pi, a.pn - b.pn);
}

int maxprev[maxn], minnext[maxn];
item tree[4 * maxn];

void add(int v, int tl, int tr, int l, int r, item x) {
    if (l > r) return;

    if (tl == l && tr == r) {
        // v -> sum = sum(v -> sum, x);
        tree[v] = sum(tree[v], x);
        return;
    }

    int tm = (tl + tr) >> 1;
    add(v << 1, tl, tm, l, min(r, tm), x);
    add(v<<1|1, tm + 1, tr, max(l, tm + 1), r, x);
}


void clear(int v, int tl, int tr, int l, int r) {
    if (l > r) return;

    if (tl == l && tr == r) {
        tree[v] = item();
        return;
    }

    int tm = (tl + tr) >> 1;
    clear(v << 1, tl, tm, l, min(r, tm));
    clear(v<<1|1, tm + 1, tr, max(l, tm + 1), r);
}

item get(int v, int tl, int tr, int pos) {
    assert(tl <= tr);
    if (tl == tr) {
        return tree[v];
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        return sum(get(v<<1, tl, tm, pos), tree[v]);
    } else {
        return sum(get(v<<1|1, tm + 1, tr, pos), tree[v]);
    }
}


#define prev asflkjfsljka
#define next afkljjlkfas

int prev[maxn], next[maxn];
ll ans = 0;

#define left kgslsgs
#define right fsalkflksj
vector<item> left, right;

int n;

vector<pair<int, int > > q[maxn];
item re[maxn][2];

void go(int l, int r) {
    // cout << l << ' ' << r << endl;
    if (l == r) {
        int a = l - prev[l], b = next[l] - r;
        if (a >= 0 && b >= 0)
            add(ans, mul(a, b));
        return;
    }

    int m = (l + r) >> 1;
    
    go(l, m);
    go(m + 1, r);


    left.clear();
    right.clear();
    // solve 

    for (int i = m; i >= l; i--) {
        maxprev[i] = prev[i];
        if (i != m)
            maxprev[i] = max(maxprev[i], maxprev[i + 1]);
        minnext[i] = next[i];
        if (i != m)
            minnext[i] = min(minnext[i], minnext[i + 1]);

        item z = item(maxprev[i], minnext[i], i, 1);
        if (z.i <= z.p) {
        } else left.push_back(z);
    }

    for (int i = m + 1; i <= r; i++) {
        maxprev[i] = prev[i];
        if (i != m + 1)
            maxprev[i] = max(maxprev[i], maxprev[i - 1]);
        minnext[i] = next[i];
        if (i != m + 1)
            minnext[i] = min(minnext[i], minnext[i - 1]);

        item z = item(maxprev[i], minnext[i], i, 1);
        if (z.i >= z.n) {
        } else right.push_back(z);
    }

    sort(all(left));
    sort(all(right));   

    ll curans = 0;

    for (int i = 0; i < left.size(); i++) {
        int pos1 = upper_bound(all(right), item(left[i].p, inf, inf, inf)) - right.begin();
        int pos2 = upper_bound(all(right), item(left[i].i, inf, inf, inf)) - right.begin() - 1;
 
        if (pos1 - 1 >= 0) {
            q[pos1 - 1].pb(mp(i, 0));
        }
        if (pos1 <= pos2) {
            q[pos2].pb(mp(i, +1));
        }

        re[i][0] = re[i][1] = item();
    }

    for (int i = 0; i < right.size(); i++) {
        add(1, 0, n + 1, right[i].i, right[i].n - 1, right[i]);

        for (auto e : q[i]) {
            int it, val_v;
            it = e.f, val_v = e.s;
            re[it][val_v] = get(1, 0, n + 1, left[it].n);
        }
    }

    for (int i = 0; i < left.size(); i++) {
        int pos1 = upper_bound(all(right), item(left[i].p, inf, inf, inf)) - right.begin();
        int pos2 = upper_bound(all(right), item(left[i].i, inf, inf, inf)) - right.begin() - 1;        
        item val;
        if (pos1 - 1 >= 0) {
            val = re[i][0];
            add(curans, mul(mul(left[i].i, left[i].n), val.c));
            sub(curans, mul(left[i].i, val.i));
            sub(curans, mul(left[i].n, mul(left[i].p, val.c)));
            add(curans, mul(left[i].p, val.i));
        }
        if (pos1 <= pos2) {
            item val2 = re[i][1];
            val2 = sub(val2, val);

            add(curans, mul(mul(left[i].i, left[i].n), val2.c));
            sub(curans, mul(left[i].i, val2.i));
            sub(curans, mul(left[i].n, val2.p));
            add(curans, mul(val2.pi, 1));
        }
    }

    for (int i = 0; i < right.size(); i++) {
        clear(1, 0, n + 1, right[i].i, right[i].n - 1);
        q[i].clear();
    }

    for (int i = 0; i < left.size(); i++) {
        int pos1 = upper_bound(all(right), item(left[i].p, inf, inf, inf)) - right.begin();
        int pos2 = upper_bound(all(right), item(left[i].i, inf, inf, inf)) - right.begin() - 1;

        if (pos1 - 1 >= 0) {
            q[pos1 - 1].pb(mp(i, 0));
        }
        if (pos1 <= pos2) {
            q[pos2].pb(mp(i, +1));
        }

        re[i][0] = re[i][1] = item();
    }

    for (int i = 0; i < right.size(); i++) {
        add(1, 0, n + 1, right[i].n, n + 1, right[i]);

        for (auto e : q[i]) {
            int it, val_v;
            it = e.f, val_v = e.s;
            re[it][val_v] = get(1, 0, n + 1, left[it].n);
        }
    }

    for (int i = 0; i < left.size(); i++) {
        int pos1 = upper_bound(all(right), item(left[i].p, inf, inf, inf)) - right.begin();
        int pos2 = upper_bound(all(right), item(left[i].i, inf, inf, inf)) - right.begin() - 1;        
        item val;
        if (pos1 - 1 >= 0) {
            val = re[i][0];
            add(curans, mul(left[i].i, val.n));
            sub(curans, mul(left[i].i, val.i));
            sub(curans, mul(left[i].p, val.n));
            add(curans, mul(left[i].p, val.i));
        }
        if (pos1 <= pos2) {
            item val2 = re[i][1];
            val2 = sub(val2, val);

            add(curans, mul(left[i].i, val2.n));
            sub(curans, mul(left[i].i, val2.i));
            sub(curans, mul(val2.pn, 1));
            add(curans, mul(val2.pi, 1));
        }
    }

    for (int i = 0; i < right.size(); i++) {
        clear(1, 0, n + 1, right[i].n, n + 1);
        q[i].clear();
    }

    add(ans, curans);
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> sot;

    for (int i = 1; i <= n; i++) {
        if (!sot.count(a[i])) {
            sot[a[i]] = 0;
        }
        prev[i] = sot[a[i]];
        sot[a[i]] = i;
    }

    sot.clear();
    for (int i = n; i > 0; i--) {
        if (!sot.count(a[i])) {
            sot[a[i]] = n + 1;
        }
        next[i] = sot[a[i]];
        sot[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        next[i] -= 1;
        prev[i] += 1;
    }

    go(1, n);
    cout << ans;
    return 0;
}