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

struct E {
    int cnt[5];
    i64 res;

    E() {
        memset(cnt, 0, sizeof cnt);
        res = 0;
    }

    E(const E& other) {
        memcpy(cnt, other.cnt, sizeof cnt);
        res = other.res;
    }
};

int n, k;

E inc(E a) {
    a.res += a.cnt[0];
    rotate(a.cnt, a.cnt+1, a.cnt+k);
    return a;
}

E add(E a, E b) {
    forn(i, k) a.cnt[i] += b.cnt[i];
    a.res += b.res;
    return a;
}

E sub(E a, E b) {
    forn(i, k) a.cnt[i] -= b.cnt[i];
    a.res -= b.res;
    return a;
}

vi e[maxn];
E d[maxn];
i64 res;
const int ROOT = 0;

void dfs1(int v, int anc) {
    E res;
    for (int to: e[v]) if (to != anc) {
        dfs1(to, v);
        res = add(res, d[to]);
    }
    res = inc(res);
    ++res.cnt[0];
    d[v] = res;
}

void dfs2(int v, int anc, E up) {
    E s;
    for (int to: e[v]) if (to != anc) {
        s = add(s, d[to]);
    }
    s = inc(add(s, up));
    res += s.res;

    ++s.cnt[0];
    for (int to: e[v]) if (to != anc) {
        E t = sub(s, inc(d[to]));
        dfs2(to, v, t);
    }
}

void solve() {
    cin >> n >> k;
    forn(i, n-1) {
        int u, v;
        cin >> u >> v;
        e[--u].pb(--v);
        e[v].pb(u);
    }
    dfs1(ROOT%n, -1);
    dfs2(ROOT%n, -1, E());
    assert(res%2 == 0);
    cout << res/2 << endl;
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}