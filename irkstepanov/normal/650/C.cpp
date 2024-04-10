#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

vector<int> cols, rows;
vector<char> used;
vector<int> l, r, u, d;
vector<int> ans;
int n, m;

int dfs(int v)
{
    used[v] = true;
    int x = max(rows[v / m], cols[v % m]);
    if (l[v] != -1 && !used[l[v]]) {
        x = max(x, dfs(l[v]));
    }
    if (r[v] != -1 && !used[r[v]]) {
        x = max(x, dfs(r[v]));
    }
    if (d[v] != -1 && !used[d[v]]) {
        x = max(x, dfs(d[v]));
    }
    if (u[v] != -1 && !used[u[v]]) {
        x = max(x, dfs(u[v]));
    }
    return x;
}

void paint(int v, int color)
{
    ans[v] = color;
    rows[v / m] = max(rows[v / m], color + 1);
    cols[v % m] = max(cols[v % m], color + 1);
    if (l[v] != -1 && ans[l[v]] == 0) {
        paint(l[v], color);
    }
    if (r[v] != -1 && ans[r[v]] == 0) {
        paint(r[v], color);
    }
    if (u[v] != -1 && ans[u[v]] == 0) {
        paint(u[v], color);
    }
    if (d[v] != -1 && ans[d[v]] == 0) {
        paint(d[v], color);
    }
}

int main()
{

    scanf("%d%d", &n, &m);
    vector<int> a(n * m);
    vector<int> sorted(n * m);
    used.assign(n * m, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i * m + j]);
            sorted[i * m + j] = a[i * m + j];
        }
    }

    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    int s = sz(sorted);
    vector<vector<int> > pos(s);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i * m + j] = lower_bound(all(sorted), a[i * m + j]) - sorted.begin();
            pos[a[i * m + j]].pb(i * m + j);
        }
    }

    l.assign(n * m, -1);
    r.assign(n * m, -1);
    d.assign(n * m, -1);
    u.assign(n * m, -1);

    vector<int> v(s, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = a[i * m + j];
            if (v[x] != -1) {
                r[v[x]] = i * m + j;
                l[i * m + j] = v[x];
            }
            v[x] = i * m + j;
        }
        for (int j = 0; j < m; ++j) {
            v[a[i * m + j]] = -1;
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            int x = a[i * m + j];
            if (v[x] != -1) {
                d[v[x]] = i * m + j;
                u[i * m + j] = v[x];
            }
            v[x] = i * m + j;
        }
        for (int i = 0; i < n; ++i) {
            v[a[i * m + j]] = -1;
        }
    }

    cols.assign(m, 1);
    rows.assign(n, 1);

    ans.resize(n * m);

    for (int val = 0; val < s; ++val) {
        for (int c : pos[val]) {
            if (!used[c]) {
                int x = dfs(c);
                paint(c, x);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", ans[i * m + j]);
        }
        printf("\n");
    }

}