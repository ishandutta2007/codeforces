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

const int mod = 1e9+7;

int add() { return 0; }
int add(int x) { return x; }
template<typename... Args> int add(int x, Args... args) {
    x += add(args...);
    if (x >= mod) x -= mod;
    return x;
}
template<typename... Args> void udd(int &x, Args... args) {
    x = add(x, args...);
}

int mul() { return 1; }
int mul(int x) { return x; }
template<typename... Args> int mul(int x, Args... args) {
    return 1ll * x * mul(args...) % mod;
}
template<typename... Args> void uul(int &x, Args... args) {
    x = mul(x, args...);
}

int mpow(int x, int k) {
    int a = 1;
    while (true) {
        if (k&1) a = mul(a, x);
        k /= 2;
        if (k == 0) break;
        x = mul(x, x);
    }
    return a;
}

int inv(int x) {
    return mpow(x, mod - 2);
}

const int maxn = 200500;

int n;
vi e[maxn];
int b[maxn];
int res = 1;

void scan() {
    cin >> n;
    forn(i, n) {
        int u, v;
        cin >> u >> v;
        e[--u].push_back(--v);
        e[v].push_back(u);
    }
}

void dfs(int v, int &cc, int &d3, int &nn, int anc = -1) {
    b[v] = 1;
    ++nn;
    // if (e[v].size() >= 3) d3 = 1;
    for (int to: e[v]) if (to != anc) {
        if (to == v) d3 = 1, cc = 1;
        else if (b[to]) cc = 1;
        else dfs(to, cc, d3, nn, v);
    }
}

void solve() {
    forn(i, n*2) {
        if (!b[i]) {
            int cc = 0, d3 = 0, nn = 0;
            dfs(i, cc, d3, nn);
            if (cc) {
                if (d3 == 0 && nn > 1) uul(res, 2);
            } else {
                uul(res, nn);
            }
        }
    }
    cout << res << endl;
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