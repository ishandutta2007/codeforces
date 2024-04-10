#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long N = 3e5 + 1;
const long long inf = 1e18;
const long long LogN = 20;

long long m[LogN][N], c[LogN][N], p[N], ans[N], top = 0, c1[N];
long long d[N];
vector <pair<long long, long long> > e[N];
vector <long long> e1[N], nm[N];

set <pair<long long, long long> > s;


void dfs(long long u, long long pr) {
    m[0][u] = pr;
    c[0][u] = d[u];
    for (long long i = 1; i < LogN; ++i) {
        m[i][u] = m[i - 1][m[i - 1][u]];
        c[i][u] = max(c[i - 1][u], c[i - 1][m[i - 1][u]]);
    }
    for (long long i = 0; i < e1[u].size(); ++i) {
        p[e1[u][i]] = p[u] + 1;
        dfs(e1[u][i], u);
    }
}

long long mxe(long long a, long long b) {
    long long ans = 0;
    if (p[b] < p[a])
        swap(a, b);
    for (long long i = LogN - 1; i >= 0; --i)
    if (p[m[i][b]] >= p[a]) {
        ans = max(ans, c[i][b]);
        b = m[i][b];
    }
    if (a == b)
        return ans;
    for (long long i = LogN - 1; i >= 0; --i)
    if (m[i][a] != m[i][b]) {
        ans = max(ans, max(c[i][b], c[i][a]));
        b = m[i][b];
        a = m[i][a];
    }
    ans = max(ans, max(c[0][a], c[0][b]));
    return ans;
}

bool use[N];

int main() {
    long long i, j, n, k, a, b, cc;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= k; ++i) {
        cin >> a >> b >> cc;
        e[a].push_back({b, cc});
        nm[a].push_back(i);
        e[b].push_back({a, cc});
        nm[b].push_back(i);
    }
    for (i = 1; i <= n; ++i)
        d[i] = inf;
    d[1] = 0;
    for (i = 1; i <= n; ++i)
        s.insert({d[i], i});
    long long cs = 0;
    while (s.size() > 0) {
        pair <long long, long long> p = *s.begin();
        s.erase(s.begin());
        long long u = p.se;
        cs += p.fi;
        use[u] = true;
        for (i = 0; i < e[u].size(); ++i)
        if (e[u][i].se < d[e[u][i].fi] && !use[e[u][i].fi]) {
            s.erase({d[e[u][i].fi], e[u][i].fi});
            d[e[u][i].fi] = e[u][i].se;
            c1[e[u][i].fi] = u;
            s.insert({d[e[u][i].fi], e[u][i].fi});
        }
    }
    for (i = 2; i <= n; ++i) {
        e1[c1[i]].push_back(i);
    }
    dfs(1, 1);
    for (i = 1; i <= n; ++i)
    for (j = 0; j < e[i].size(); ++j) {
        ans[nm[i][j]] = cs + e[i][j].se - mxe(i, e[i][j].fi);
    }
    for (i = 1; i <= k; ++i)
        cout << ans[i] << "\n";
}