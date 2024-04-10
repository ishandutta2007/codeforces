#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
typedef long long ll;
typedef long double ld;

const int M = 2e5 + 239;

int mxl[M];
int n, m, q;
vector<pair<int, int>> edges, queries;

pair<int, int> par[M];
int rg[M];

pair<int, int> find_set(int s)
{
    if (s == par[s].first)
        return par[s];
    pair<int, int> cur = find_set(par[s].first);
    cur.second = (cur.second + par[s].second) & 1;
    return cur;
}

vector<tuple<int, int, int, int, int>> changes; // s, f, par[s].f, par[s].s, rg[f]

int merge(int s, int f)
{
    pair<int, int> ts = find_set(s);
    pair<int, int> tf = find_set(f);
    if (ts.first == tf.first)
    {
        if (ts.second == tf.second)
            return -1;
        return 0;
    }
    s = ts.first;
    f = tf.first;
    if (rg[s] > rg[f])
        swap(s, f);
    changes.push_back(make_tuple(s, f, par[s].first, par[s].second, rg[f]));
    par[s] = make_pair(f, (1 + ts.second + tf.second) & 1);
    if (rg[s] == rg[f])
        rg[f]++;
    return 1;
}

void cut()
{
    int s = get<0>(changes.back());
    int f = get<1>(changes.back());
    par[s] = make_pair(get<2>(changes.back()), get<3>(changes.back()));
    rg[f] = get<4>(changes.back());
    changes.pop_back();
}

void clear()
{
    for (int i = 0; i < n; i++)
    {
        par[i] = make_pair(i, 0);
        rg[i] = 0;
    }
}

void upd(int lc)
{
    clear();
    for (int i = 0; i < lc; i++)
        if (merge(edges[i].first, edges[i].second) < 0)
        {
            mxl[lc] = m;
            return;
        }
    for (int i = m - 1; i >= 0; i--)
        if (merge(edges[i].first, edges[i].second) < 0)
        {
            mxl[lc] = i;
            return;
        }
    mxl[lc] = 0;
}

void solve(int l, int r, int ql, int qr)
{
    if (l == r)
        return;
    if (r - l == 1)
    {
        int cnt = 0;
        mxl[l] = ql;
        for (int i = qr - 1; i >= ql; i--)
        {
            int now = merge(edges[i].first, edges[i].second);
            if (now < 0)
            {
                mxl[l] = i;
                break;
            }
            if (now == 1)
                cnt++;
        }
        while (cnt)
        {
            cnt--;
            cut();
        }
        return;
    }
    int mid = (l + r) >> 1;
    int cnt = 0;
    for (int i = l; i < mid; i++)
    {
        int now = merge(edges[i].first, edges[i].second);
        if (now == 1)
            cnt++;
    }
    mxl[mid] = ql;
    for (int i = qr - 1; i >= ql; i--)
    {
        int now = merge(edges[i].first, edges[i].second);
        if (now < 0)
        {
            mxl[mid] = i;
            break;
        }
        if (now == 1)
            cnt++;
    }
    while (cnt)
    {
        cnt--;
        cut();
    }
    for (int i = qr - 1; i > mxl[mid]; i--)
    {
        int now = merge(edges[i].first, edges[i].second);
        if (now == 1)
            cnt++;
    }
    solve(l, mid, ql, mxl[mid] + 1);
    while (cnt)
    {
        cnt--;
        cut();
    }
    for (int i = l; i < mid; i++)
    {
        int now = merge(edges[i].first, edges[i].second);
        if (now == 1)
            cnt++;
    }
    solve(mid, r, mxl[mid], qr);
    while (cnt)
    {
        cnt--;
        cut();
    }
}

int main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        edges.push_back(make_pair(s, f));
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries.push_back(make_pair(l, r));
    }
    clear();
    int cnt = 0;
    int rg = m - 1;
    for (int i = 0; i < m; i++)
    {
        int now = merge(edges[i].first, edges[i].second);
        if (now < 0)
        {
            rg = i;
            break;
        }
        if (now == 1)
            cnt++;
    }
    while (cnt)
    {
        cnt--;
        cut();
    }
    for (int i = rg + 1; i < m; i++)
        mxl[i] = m;
    solve(0, rg + 1, 0, m);
    for (pair<int, int> t : queries)
        cout << (t.second >= mxl[t.first] ? "NO\n" : "YES\n");
    return 0;
}