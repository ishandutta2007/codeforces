#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int n, Q;
vector<pi> v[300005];

int s[500005], e[500005], w[500005];
int r[500005], xr[300005];
int p[300005], in[300005], out[300005], ck;
int parent[300005][21];
vector<int> F;
int log_n = 19;
vector<int> par, rk;

void init(int n) {
    par.assign(n, 0);
    iota(par.begin(), par.end(), 0);
    rk.assign(n, 1);
}

int top(int v) {
    if (par[v] != v)
        return par[v] = top(par[v]);
    return v;
}

bool unite(int u, int v) {
    u = top(u);
    v = top(v);
    if (u == v)
        return false;
    if (rk[u] < rk[v])
        swap(u, v);
    par[v] = u;
    rk[u] += rk[v];
    return true;
}

;

void dfs(int x, int y, int cur) {
    xr[x] = cur;
    p[x] = y;
    in[x] = ck++;

    parent[x][0] = y;
    for (int i = 1; i < log_n; i++) {
        parent[x][i] = parent[parent[x][i - 1]][i - 1];
    }

    for (auto[z, t] : v[x]) {
        if (z != y) dfs(z, x, cur ^ t);
    }
    out[x] = ck;
}



void inc(int pos, int val) {
    for (; pos < F.size(); pos |= pos + 1)
        F[pos] += val;
}

int sum(int pos) {
    int ans = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ans += F[pos];
    return ans;
}

void addOnPath(int v, int l) {
    while (v != l) {
        inc(in[v], 1);
        inc(out[v], -1);
        v = p[v];
    }
}

int isPar(int p, int v) {
    return in[p] <= in[v] && out[v] <= out[p];
}

int lca2(int u, int v) {
    if (isPar(u, v)) return u;
    if (isPar(v, u)) return v;

    for (int pw = log_n-1; pw >= 0; pw--) {
        if (!isPar(parent[v][pw], u))
            v = parent[v][pw];
    }
    return parent[v][0];
}

void solve() {
    cin >> n >> Q;
    init(n);
    for (int i = 0; i < Q; i++) {
        cin >> s[i] >> e[i] >> w[i];
        s[i]--;
        e[i]--;

        if (unite(s[i], e[i])) {
            v[s[i]].pb({e[i], w[i]});
            v[e[i]].pb({s[i], w[i]});
        } else r[i] = 1;

    }

    F.assign(2 * n + 5, 0);

    memset(in, -1, sizeof(in));
    memset(out, -1, sizeof(out));

    for (int i = 0; i < n; i++)
        if (in[i] == -1) dfs(i, i, 0);

    for (int i = 0; i < Q; i++) {
        if (r[i] == 0) {
            cout << "YES" << endl;
        } else {
            int x = s[i], y = e[i];
            int t = xr[x] ^ xr[y] ^ w[i];
            if (t != 1) {
                cout << "NO" << endl;
                continue;
            }

            int a = lca2(x, y);
            t = sum(in[x]) + sum(in[y]) - 2 * sum(in[a]);
            if (t > 0) {
                cout << "NO" << endl;
                continue;
            }

            addOnPath(x, a);
            addOnPath(y, a);
            cout << "YES" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}