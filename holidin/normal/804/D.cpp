#include <bits/stdc++.h>
using namespace std;
const int N  = 5e5 + 1;
vector <int> v[N], e[N];
vector <long long> lnt[N], prsum[N];
int c[N], deep[N], t[N], lenp[N], diam[N];
map <pair<int, int>, long double> m;

void dfs(int u, int pr, int typ) {
    deep[u] = 0;
    t[u] = typ;
    v[typ].push_back(u);
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs(e[u][i], u, typ);
        deep[u] = max(deep[u], deep[e[u][i]] + 1);
    }
}

void dfsp(int u, int pr, int h) {
    int mxp1 = h, mxp2 = 0;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr)
        if (mxp1 < deep[e[u][i]] + 1) {
            mxp2 = mxp1;
            mxp1 = deep[e[u][i]] + 1;
        } else if (mxp2 < deep[e[u][i]] + 1)
                mxp2 = deep[e[u][i]] + 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr)
        if (deep[e[u][i]] == mxp1 - 1)
            dfsp(e[u][i], u, mxp2 + 1);
        else
            dfsp(e[u][i], u, mxp1 + 1);
    lenp[u] = mxp1;
}

int main() {
    int i, j, k, n, a, b, q, top = 0, edge;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> edge >> q;
    for (i = 0; i < edge; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (i = 1; i <= n; ++i)
    if (t[i] == 0) {
        ++top;
        dfs(i, 0, top);
        dfsp(i, 0, 0);
    }
    for (i = 1; i <= top; ++i) {
        diam[i] = 0;
        for (j = 0; j < v[i].size(); ++j) {
            lnt[i].push_back(lenp[v[i][j]]);
            diam[i] = max(diam[i], lenp[v[i][j]]);
        }
        sort(lnt[i].begin(), lnt[i].end());
        prsum[i].resize(lnt[i].size() + 1);
        prsum[i][0] = 0;
        for (j = 0; j < lnt[i].size(); ++j)
            prsum[i][j + 1] = prsum[i][j] + lnt[i][j];
    }
    for (int y = 0; y < q; ++y) {
        cin >> a >> b;
        a = t[a];
        b = t[b];
        if (v[a].size() > v[b].size())
            swap(a, b);
        if (a == b)
            cout << -1 << "\n";
        else {
            if (m.count({a, b}) == 0) {
                long double ans = 0;
                int mnd = max(diam[a], diam[b]);
                for (i = 0; i < lnt[a].size(); ++i) {
                    int l = 0, r = lnt[b].size() + 1;
                    while (r - l > 1) {
                        int mid = (l + r) / 2 - 1;
                        if (lnt[a][i] + lnt[b][mid] < mnd)
                            l = mid + 1;
                        else
                            r = mid + 1;
                    }
                    ans += l * 1.0 * mnd + prsum[b][v[b].size()] - prsum[b][l] + (v[b].size() - l) * (lnt[a][i] + 1);
                }
                ans /= v[a].size();
                m[{a, b}] = ans / v[b].size();
            }
            cout << fixed << setprecision(12) << m[{a, b}] << "\n";
        }
    }
}