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

const int maxn = 20050;

int n;
vi a[2];

enum { NONE, WIN, LOSE };

int d[maxn], st[maxn];
vi e[maxn];
int deg[maxn];
int lq, rq;
int q[maxn];

void scan() {
    cin >> n;
    forn(k, 2) {
        int x;
        cin >> x;
        a[k].resize(x);
        forn(i, x) cin >> a[k][i];
    }
}

void build() {
    forn(t, 2) forn(i, n) {
        int v = i*2+t;
        for (int x: a[t]) {
//             int ni = (i+x)%n;
//             int nt = t^1;
//             int nv = ni*2+nt;
//             e[nv].pb(v);
            ++deg[v];
        }
    }
}

vi edges(int v) {
    int t = (v%2)^1;
    int i = v/2;
    vi res;
    for (int x: a[t]) {
        int nt = t;
        int ni = (i + n - x) % n;
        res.pb(ni*2+nt);
    }
    return res;
}

void solve() {
    memset(d, -1, sizeof d);
    st[0] = st[1] = LOSE;
    d[0] = d[1] = 0;
    q[0] = 0;
    q[1] = 1;
    rq = 2;
    while (lq != rq) {
        int v = q[lq++];
        for (auto to: edges(v)) if (d[to] == -1) {
//         for (auto to: e[v]) if (d[to] == -1) {
            if (st[v] == LOSE || (st[v] == WIN && !--deg[to])) {
                d[to] = d[v] + 1;
                st[to] = 3 - st[v];
                q[rq++] = to;
            }
        }
    }
    forn(t, 2) {
        forn(i, n) if (i) {
            int x = st[i*2+t];
            if (x == NONE) cout << "Loop ";
            else if (x == WIN) cout << "Win ";
            else cout << "Lose ";
        }
        cout << "\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    scan();
    build();
//     for (int x:1]) cerr << x << " "; cerr << endl;
//     for (int x: edges(1)) cerr << x << " "; cerr << endl;
//     return 0;

    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}