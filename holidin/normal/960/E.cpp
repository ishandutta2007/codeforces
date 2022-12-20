
 #include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 1;
const long long mod = 1e9 + 7;
long long ch[N], nch[N], a[N], ans = 0, sz[N];
vector <long long> e[N];

void dfs(long long u, long long pr) {
    ch[u] = 1;
    nch[u] = 0;
    sz[u] = 1;
    for (long long i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs(e[u][i], u);
        sz[u] += sz[e[u][i]];
        ch[u] += nch[e[u][i]];
        nch[u] += ch[e[u][i]];
    }
}

long long f(long long a) {
    return (a + mod * mod) % mod;
}

void dfs1(long long u, long long pr, long long chv, long long nchv) {
    ans = f(ans + f(f(f(chv - nchv) * a[u]) * sz[u]));
    for (long long i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        ans = f(ans + f(f(f(ch[u] - nch[e[u][i]] - nch[u] + ch[e[u][i]]) * sz[e[u][i]]) * a[u]));
        ans = f(f(f(nch[e[u][i]] - ch[e[u][i]]) * a[u]) + ans);
        dfs1(e[u][i], u, nchv + nch[u] - ch[e[u][i]], chv + ch[u] - nch[e[u][i]]);
    }
    ans = f(ans + f(f(f(ch[u] - nch[u]) * a[u]) * f(chv + nchv)));
}

int main() {
    long long i, j, n, x, y;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = (a[i] + mod) % mod;
         ans += a[i];
    }
    for (i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(2, 0);
    dfs1(2, 0, 0, 0);
    cout << f(ans);
}