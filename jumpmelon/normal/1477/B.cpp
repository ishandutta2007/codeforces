#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000, MAXQ = 200000;
int n;
char S[MAXN + 2], F[MAXN + 2];
struct opt { int l, r; } Q[MAXQ + 1];
struct node { int tag, sum; } T[(MAXN << 2) + 10];

#define lt (p << 1)
#define rt (p << 1 | 1)

inline void modify(int v, int p, int a, int b)
{
    T[p].tag = v;
    T[p].sum = (b - a + 1) * v;
}

inline void maintain(int p)
{
    T[p].sum = T[lt].sum + T[rt].sum;
}

void build(int p = 1, int a = 1, int b = n)
{
    if (a == b)
        modify(F[a] - '0', p, a, b);
    else
    {
        int mid = (a + b) >> 1;
        T[p].tag = -1;
        build(lt, a, mid);
        build(rt, mid + 1, b);
        maintain(p);
    }
}

int query(int x, int y, int p = 1, int a = 1, int b = n)
{
    if (T[p].tag != -1)
        return T[p].tag * (y - x + 1);
    else if (x <= a && b <= y)
        return T[p].sum;
    else
    {
        int mid = (a + b) >> 1;
        if (y <= mid)
            return query(x, y, lt, a, mid);
        else if (x > mid)
            return query(x, y, rt, mid + 1, b);
        else
            return query(x, mid, lt, a, mid) + query(mid + 1, y, rt, mid + 1, b);
    }
}

void pushdown(int p, int a, int b)
{
    if (T[p].tag != -1)
    {
        int mid = (a + b) >> 1;
        modify(T[p].tag, lt, a, mid);
        modify(T[p].tag, rt, mid + 1, b);
        T[p].tag = -1;
    }
}

void update(int x, int y, int v, int p = 1, int a = 1, int b = n)
{
    if (x <= a && b <= y)
        modify(v, p, a, b);
    else
    {
        int mid = (a + b) >> 1;
        pushdown(p, a, b);
        if (x <= mid)
            update(x, y, v, lt, a, mid);
        if (y > mid)
            update(x, y, v, rt, mid + 1, b);
        maintain(p);
    }
}

int main()
{
    // freopen("B.in", "r", stdin);
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        set<int> V;
        int q;
        scanf("%d%d", &n, &q);
        scanf("%s", S + 1);
        scanf("%s", F + 1);
        for (int i = 1; i <= q; i++)
            scanf("%d%d", &Q[i].l, &Q[i].r);
        build();
        bool fl = 1;
        for (int i = q; i >= 1; i--)
        {
            int l = Q[i].l, r = Q[i].r, len = r - l + 1, lim = (len + 1) >> 1;
            int s = query(l, r);
            if (s < lim)
                update(l, r, 0);
            else if (len - s < lim)
                update(l, r, 1);
            else
                fl = 0;
        }
        for (int i = 1; i <= n; i++)
            if (query(i, i) != S[i] - '0')
                fl = 0;
        puts(fl ? "YES" : "NO");
    }
    return 0;
}