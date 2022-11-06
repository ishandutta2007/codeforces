#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

const int mod = 998244353;

void add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int mul(int x, int y) {
    return 1ll * x * y % mod;
}

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = mul(r, x);
        x = mul(x, x);
        p >>= 1;
    }
    return r;
}

int n, m;
int L[300001], R[300001];
int A[21], B[21];
vector<int> in[300001], out[300001];
int fac[300001], rev[300001];

int nCr(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;
    return mul(fac[n], mul(rev[r], rev[n - r]));
}

vector<int> edge[300001];
bool vis[300001];
void init(int x) {
    edge[x].clear();
    vis[x] = 0;
}

vector<int> lst;
void dfs(int x) {
    lst.push_back(x);
    vis[x] = 1;
    for (int i : edge[x]) {
        if (vis[i]) continue;
        dfs(i);
    }
}

int cc[50] = { 1 }, all;
void init() {
    cc[0] = 1;
    for (int i = 1; i < 50; ++i) cc[i] = 0;
    all = 0;
}

int idx[300001];
void solve(int x) {
    if (vis[x]) return;
    lst.clear();
    dfs(x);
    int n = lst.size();
    for (int i = 0; i < n; ++i) idx[lst[i]] = i;
    all += n;
    int cs[50] = {};
    for (int b = 0; b < (1 << n); ++b) {
        int cnt = __builtin_popcount(b);
        bool pos = 1;
        for (int i : lst) {
            for (int j : edge[i]) if (((b >> idx[i]) & 1) && ((b >> idx[j]) & 1)) {
                pos = 0;
                break;
            }
            if (!pos) break;
        }
        cs[cnt] += pos;
    }
    int nxt[50] = {};
    for (int i = 0; i < 50; ++i) for (int j = 0; i + j < 50; ++j) {
        add(nxt[i + j], mul(cc[i], cs[j]));
    }
    memcpy(cc, nxt, sizeof(cc));
}

bool on[300001], en[21];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> m;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
    rev[n] = pw(fac[n], mod - 2);
    for (int i = n; i > 0; --i) rev[i - 1] = mul(rev[i], i);
    for (int i = 1; i <= n; ++i) {
        cin >> L[i] >> R[i];
        in[L[i]].push_back(i);
        out[R[i]].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        cin >> A[i] >> B[i];
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j : in[i]) on[j] = 1, ++cnt;
        bool ch = 0;
        for (int i = 0; i < m; ++i) {
            bool o = on[A[i]] && on[B[i]];
            if (en[i] != o) ch = 1;
            en[i] = o;
        }
        if (ch) {
            init();
            for (int i = 0; i < m; ++i) if (en[i]) init(A[i]), init(B[i]);
            for (int i = 0; i < m; ++i) if (en[i]) {
                edge[A[i]].push_back(B[i]);
                edge[B[i]].push_back(A[i]);
            }
            for (int i = 0; i < m; ++i) if (en[i]) solve(A[i]), solve(B[i]);
        }
        for (int j = 0; j < 50; ++j) add(ans, mul(cc[j], nCr(cnt - all, i - j)));
        for (int j : out[i]) on[j] = 0, --cnt;
    }
    printf("%d\n", ans);
    return 0;
}