#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 5e5;
const int L = 333;
const long long inf = 1e9;
const long double EPS = 1e-9;
long long k[2][N / L][L], d[2][N / L][L];
long double l[2][N / L][L];
int top[2][N / L], tin[N], tout[N], p[N], pos[2][N];
long long db[2][N / L], c[N], a[N], b[N], t[N], top1 = 0, dx[N];
bool flag = 0;
vector <int> e[N];
int Lt = 0;
int uk[2][N];

void dfs(int u, long long sum, long long sum1) {
    sum += c[u];
    sum1 += t[u];
    tin[u] = ++top1;
    p[tin[u]] = u;
    a[u] = sum;
    b[u] = abs(sum1);
    for (int i = 0; i < e[u].size(); ++i)
        dfs(e[u][i], sum, sum1);
    tout[u] = top1;
}

void build(int u, int v, int vl, int vr) {
    int i, j;
    db[u][v] = 0;
    vector <pair<long long, pair<long long, int> > > fv;
    if (!flag) {
        for (i = vl; i < vr; ++i) {
            ll a1, b1;
            if ((u & 1) > 0)
                a1 = -a[p[i]];
            else
                a1 = a[p[i]];
            b1 = b[p[i]];
            fv.push_back({b1, {a1 * b1, i}});
        }
        sort(fv.begin(), fv.end());
        for (i = 0; i < fv.size(); ++i)
            pos[u][fv[i].se.se] = i;
    } else {
        fv.resize(vr - vl);
        for (i = vl; i < vr; ++i) {
            ll a1, b1;
            if ((u & 1) > 0)
                a1 = -a[p[i]];
            else
                a1 = a[p[i]];
            b1 = b[p[i]];
            fv[pos[u][i]] = {b1, {a1 * b1, i}};
        }
    }
    int tp = -1;
    for (i = 0; i < fv.size(); ++i) {
        long long kx = fv[i].fi, dx = fv[i].se.fi;
        while (tp >= 0 && k[u][v][tp] * l[u][v][tp] + d[u][v][tp] < kx * l[u][v][tp] + dx)
            --tp;
        if (tp >= 0 && k[u][v][tp] == kx)
            continue;
        ++tp;
        k[u][v][tp] = fv[i].fi;
        d[u][v][tp] = fv[i].se.fi;
        if (tp == 0)
            l[u][v][tp] = -inf;
        else {
            l[u][v][tp] = (d[u][v][tp - 1] - d[u][v][tp]) * 1.0 / (k[u][v][tp] - k[u][v][tp - 1]);
        }
    }
    top[u][v] = tp;
    if (u == 0)
        uk[u][v] = 0;
    else
        uk[u][v] = tp;
}

long long get(int u, int v) {
    if (u == 0)
        while (uk[u][v] < top[u][v] && db[u][v] > l[u][v][uk[u][v] + 1])
            ++uk[u][v];
    else
        while (uk[u][v] > 0 && db[u][v] < l[u][v][uk[u][v]])
            --uk[u][v];
    return db[u][v] * k[u][v][uk[u][v]] + d[u][v][uk[u][v]];
}

int main() {
    int i, j, k, n, w, h, q, type;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (i = 2; i <= n; ++i) {
        cin >> j;
        e[j].push_back(i);
    }
    for (i = 1; i <= n; ++i)
        cin >> c[i];
    for (i = 1; i <= n; ++i)
        cin >> t[i];
    dfs(1, 0, 0);
    Lt = max(1, (int)sqrt(n) / 3);
    for (i = 0; i < 2; ++i)
    for (j = 0; j <= n / Lt; ++j)
        build(i, j, max(1, j * Lt), min(Lt * (1 + j), n + 1));
    flag = 1;
    for (i = 0; i < q; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> w >> h;
            for (j = 0; j <= n / Lt; ++j)
            if (tin[w] <= j * Lt && (j + 1) * Lt - 1 <= tout[w]) {
                db[0][j] += h;
                db[1][j] -= h;
            } else if (max(j * Lt, tin[w]) <= min((j + 1) * Lt - 1, tout[w])) {
                    for (int t = max(1, j * Lt); t < (j + 1) * Lt; ++t) {
                        a[p[t]] += db[0][j];
                        if (tin[w] <= t && t <= tout[w])
                            a[p[t]] += h;
                    }
                    for (int p = 0; p < 2; ++p)
                        build(p, j, max(1, j * Lt), min(Lt * (1 + j), n + 1));
                }
        } else {
            cin >> w;
            long long ans = 0;
            for (j = 0; j <= n / Lt; ++j)
                if (tin[w] <= j * Lt && (j + 1) * Lt - 1 <= tout[w]) {
                    for (int p = 0; p < 2; ++p)
                        ans = max(ans, get(p, j));
                } else if (max(j * Lt, tin[w]) <= min((j + 1) * Lt - 1, tout[w])) {
                    for (int t = max(tin[w], j * Lt); t <= min((j + 1) * Lt - 1, tout[w]); ++t)
                            ans = max(ans, abs(a[p[t]] + db[0][j]) * b[p[t]]);
                }
            cout << ans << "\n";
        }

    }
}