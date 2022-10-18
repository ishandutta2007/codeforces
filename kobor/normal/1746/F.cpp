#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: a)
#define SZ(x) ((int)x.size())
using K = long double;
using vi = vector<int>;
using ii = pair<int, int>;
using ll = long long;
#define X first
#define Y second
#define PB push_back
constexpr int INF = 0x3f3f3f3f;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int los(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

int n, q;
vi arr, ans, vals;
vector<pair<ii, ii>> que;

struct Tree {
    vector<ll> bit;
    int nn;

    Tree(vi a) {
        nn = 1;
        while(nn < SZ(a)) nn *= 2;
        bit.resize(nn * 2);
        FOR(i, 0, SZ(a)) bit[i + nn] = a[i];
        for(int i = nn - 1; i > 0; i--) bit[i] = bit[i << 1] + bit[(i << 1) + 1];
    }

    ll sum(int l, int r) {
        ll ret = 0;
        l += nn, r += nn;
        while(l <= r) {
            if(l & 1) ret += bit[l++];
            if((r & 1) ^ 1) ret += bit[r--];
            l >>= 1, r >>= 1;
        }
        return ret;
    }

    void sett(int idx, int val) {
        idx += nn;
        bit[idx] = val;
        for(idx >>= 1; idx > 0; idx >>= 1) bit[idx] = bit[idx << 1] + bit[(idx << 1) + 1];
    }
};

void flaj() {
    vi nvals(SZ(vals));
    TRAV(x, nvals) x = los(0, INF);
    vi narr = arr;
    TRAV(x, narr) x = nvals[x];
    Tree wonsz(narr);
    int cnt = 0;
    TRAV(x, que) {
        if(x.X.X == 1) {
            wonsz.sett(x.X.Y, nvals[x.Y.X]);
        }
        else {
            if(ans[cnt] == 1) {
                if(wonsz.sum(x.X.Y, x.Y.X) % x.Y.Y != 0) ans[cnt] = 0;
            }
            cnt++;
        }
    }
}

void solve() {
    cin >> n >> q;
    arr.resize(n);
    TRAV(x, arr) cin >> x;
    TRAV(x, arr) vals.PB(x);
    que.resize(q);
    TRAV(x, que) {
        int t, a, b, c = 0;
        cin >> t >> a >> b;
        a--;
        if(t == 1) vals.PB(b);
        if(t == 2) {
            b--;
            cin >> c;
            ans.PB(((b - a + 1) % c == 0));
        }
        x = {{t, a}, {b, c}};
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    TRAV(x, arr) x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    TRAV(x, que) {
        if(x.X.X == 1) x.Y.X = lower_bound(vals.begin(), vals.end(), x.Y.X) - vals.begin();
    }
    FOR(it, 0, 50) flaj();
    TRAV(x, ans) cout << (x ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int tt; cin >> tt;
    // FOR(te, 0, tt) solve();
    solve();
    return 0;
}