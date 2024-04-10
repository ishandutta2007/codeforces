// Hydro submission #633e32676d08baa0485db2f3@1665020520471
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define lson (p << 1)
#define rson ((p << 1) | 1)
#define mid ((l + r) >> 1)

const int MAXN = 35005;
int n, k, f[MAXN][55], a[MAXN], pre[MAXN], cur[MAXN];

struct _segment
{
    int val, tag;
} t[MAXN << 2];

struct _segmentTree
{
    void reset()
    {
        memset(t, 0, sizeof t);
    }
    void pushup(int p)
    {
        t[p].val = max(t[lson].val, t[rson].val);
    }
    void pushdown(int p)
    {
        t[lson].tag += t[p].tag;
        t[lson].val += t[p].tag;
        t[rson].tag += t[p].tag;
        t[rson].val += t[p].tag;
        t[p].tag = 0;
    }
    void build(int p, int l, int r, int x)
    {
        if (l == r)
        {
            t[p].val = f[l - 1][x];
            return;
        }
        build(lson, l, mid, x);
        build(rson, mid + 1, r, x);
        pushup(p);
    }
    void modify(int p, int l, int r, int L, int R, int x)
    {
        if (L <= l && r <= R)
        {
            t[p].val += x;
            t[p].tag += x;
            return;
        }
        pushdown(p);
        if (L <= mid)
        {
            modify(lson, l, mid, L, R, x);
        }
        if (R > mid)
        {
            modify(rson, mid + 1, r, L, R, x);
        }
        pushup(p);
    }
    int query(int p, int l, int r, int L, int R)
    {
        if (L <= l && r <= R)
            return t[p].val;
        pushdown(p);
        int ret = 0;
        if (L <= mid)
        {
            ret = max(ret, query(lson, l, mid, L, R)) ;
        }
        if (R > mid)
        {
            ret = max(ret, query(rson, mid + 1, r, L, R));
        }
        return ret;
    }
} T;

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pre[i] = cur[a[i]] + 1;
        cur[a[i]] = i;
    }
    for (int i = 1; i <= k; ++i)
    {
        T.reset();
        T.build(1, 1, n, i - 1);
        for (int j = 1; j <= n; ++j)
        {
            T.modify(1, 1, n, pre[j], j, 1);
            f[j][i] = T.query(1, 1, n, 1, j);
        }
    }
    cout << f[n][k] << endl;
    return 0;
}