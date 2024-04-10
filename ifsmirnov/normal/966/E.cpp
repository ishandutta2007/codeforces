#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 200500;

const int K = 400;

int n, q;
vi e[maxn];
int val[maxn];
bool on[maxn];
int delta[maxn];
int p[maxn];
int s[maxn];
int h[maxn];

void scan() {
    cin >> n >> q;
    forn(i, n) if (i) {
        int p;
        cin >> p;
        ::p[i] = p-1;
        e[p-1].push_back(i);
    }
    forn(i, n) cin >> val[i];
}

int root[maxn]; // for verts
bool last[maxn];

int ans;

struct Block {
    vi verts;
    int p;
    vi srt;
    int hdelta;

    int getcnt(int x) const {
        auto its = equal_range(all(srt), x);
        return its.se - its.fi;
    }

    void inc() {
        ans += getcnt(hdelta);
        ++hdelta;
    }

    void dec() {
        --hdelta;
        ans -= getcnt(hdelta);
    }

    int getSum() {
        int d = 0;
        int s = 0;
        for (int v: verts) {
            d += delta[v];
            if (!on[v] && val[v] < hdelta + d) ++s;
        }
        return s;
    }

    void rebuild() {
        srt.clear();
        int d = 0;
        for (int v: verts) {
            d += delta[v];
            if (!on[v]) srt.push_back(val[v] - d);
        }
        sort(all(srt));
    }
};

Block bs[maxn];

void dfs1(int v) {
    s[v] = 1;
    for (int to: e[v]) {
        h[to] = h[v] + 1;
        dfs1(to);
        s[v] += s[to];
    }
}


void dfs2(int v, int rt) {
    bs[rt].verts.push_back(v);
    root[v] = rt;

    if (h[rt] + K < h[v]) {
        last[v] = true;
    }
    if (e[v].empty()) {
        last[v] = true;
    }
    if (last[v]) {
        reverse(all(bs[rt].verts));
        // for (auto x: bs[rt].verts) cerr << x << " "; cerr << endl;
        bs[rt].rebuild();
    }
    if (e[v].empty()) {
        return;
    }

    int mx = *max_element(all(e[v]), [](int x, int y) { return s[x] < s[y]; });

    for (int to: e[v]) {
        if (to == mx && !last[v]) {
            dfs2(to, rt);
        } else {
            dfs2(to, to);
        }
    }
}

void inc(int v) {
    int r = root[v];
    ans -= bs[r].getSum();
    on[v] = true;
    ++delta[v];
    bs[r].rebuild();
    ans += bs[r].getSum();
    v = p[r];

    while (v != -1) {
        int r = root[v];
        if (last[v]) {
            bs[r].inc();
        } else {
            ans -= bs[r].getSum();
            ++delta[v];
            bs[r].rebuild();
            ans += bs[r].getSum();
        }
        v = p[r];
    }
}

void dec(int v) {
    int r = root[v];
    ans -= bs[r].getSum();
    on[v] = false;
    --delta[v];
    bs[r].rebuild();
    ans += bs[r].getSum();
    v = p[r];

    while (v != -1) {
        int r = root[v];
        if (last[v]) {
            bs[r].dec();
        } else {
            ans -= bs[r].getSum();
            --delta[v];
            bs[r].rebuild();
            ans += bs[r].getSum();
        }
        v = p[r];
    }
}

void solve() {
    dfs1(0);
    dfs2(0, 0);
    p[0] = -1;

    forn(i, q) {
        int x;
        cin >> x;
        if (x > 0) inc(x-1);
        else dec(-x-1);
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    scan();
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}