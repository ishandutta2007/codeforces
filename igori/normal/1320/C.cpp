#include <bits/stdc++.h>

// \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ \\
// "We created a community that can control itself." \\
// \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ \\

// TechnoRush

using namespace std;

#define int long long

#define all(x) (x).begin(), (x).end()

const long long MOD = 1e9 + 7;
const long long INFLL = 1e18;
const long long INF = 1e9;
const int N = 1200000;

long long ans = -INFLL;

long long n, m, k;
long long a[N], ca[N];
long long b[N], cb[N];
long long x[N], y[N], z[N];

long long tree[4 * N];
long long push[4 * N];

void Push(int V, int L, int M, int R)
{
    push[2 * V + 1] += push[V], tree[2 * V + 1] += push[V];
    push[2 * V + 2] += push[V], tree[2 * V + 2] += push[V];
    push[V] = 0;
}

void Add(int l, int r, int val, int L = 0, int R = N, int V = 0)
{
    if (r <= L || R <= l) return;
    if (l <= L && R <= r)
    {
        tree[V] += val;
        push[V] += val;
        return;
    }
    int M = (L + R) / 2;
    Push(V, L, M, R);
    Add(l, r, val, L, M, 2 * V + 1);
    Add(l, r, val, M, R, 2 * V + 2);
    tree[V] = max(tree[2 * V + 1], tree[2 * V + 2]);
}

long long Get(int l, int r, int L = 0, int R = N, int V = 0)
{
    if (r <= L || R <= l) return -INFLL;
    if (l <= L && R <= r)
    {
        return tree[V];
    }
    int M = (L + R) / 2;
    Push(V, L, M, R);
    tree[V] = max(tree[2 * V + 1], tree[2 * V + 2]);
    return max(Get(l, r, L, M, 2 * V + 1), Get(l, r, M, R, 2 * V + 2));
}

struct Point{
    int x, y, z;
};

bool comp2(Point A, Point B)
{
    return A.x < B.x;
}

Point p[N];

struct Q{
    int x, w;
};

bool comp1(Q A, Q B)
{
    return A.x < B.x;
}

Q q[N];

pair<int, int> ss[N];

long long ar[N];

long long AddSlow(int l, int r, int z)
{
    for (int i = l; i < r; i++) ar[i] += z;
}

long long GetSlow(int l, int r)
{
    long long mx = -INFLL;
    for (int i = l; i < r; i++) mx = max(mx, ar[i]);
    return mx;
}

void ReallySlow()
{
    long long c = -INFLL;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long g = - ca[i] - cb[j];
            for (int mu = 0; mu < k; mu++)
            {
                if (x[mu] < a[i] && y[mu] < b[j]) g += z[mu];
            }
            c = max(c, g);
        }
    }
    cout << c << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int mnca = 1e9, mncb = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> ca[i];
        mnca = min(mnca, ca[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i] >> cb[i];
        mncb = min(mncb, cb[i]);
    }
    ans = - mnca - mncb;
    for (int i = 0; i < k; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }
    for (int i = 0; i < m; i++)
    {
        ss[i] = {b[i], cb[i]};
    }
    sort(ss, ss + m);
    ss[m] = {N, INFLL};
    for (int i = 0; i < m; i++)
    {
        ss[i].second = min(ss[i].second, ss[i + 1].second);
    }
    int ls = 0;
    for (int i = 0; i < m; i++)
    {
        Add(ls, ss[i].first, -ss[i].second);
        ls = ss[i].first;
    }
    Add(ls, N, -INFLL);
    for (int i = 0; i < n; i++)
    {
        q[i] = {a[i], ca[i]};
    }
    for (int i = 0; i < k; i++)
    {
        p[i] = {x[i], y[i], z[i]};
    }
    sort(q, q + n, comp1);
    sort(p, p + k, comp2);
    for (int i = 0, j = 0; i < n;)
    {
        int cas = 0;
        if (j < k && p[j].x < q[i].x)
        {
            cas = 1;
        }
        if (cas == 0)
        {
            ans = max(ans, Get(0, N) - q[i].w);
            i++;
        }
        else
        {
            Add(p[j].y, N, p[j].z);
            j++;
        }
    }
    cout << ans << "\n";
}

/*
4 4 16
1 1
2 2
3 3
4 4
1 1
2 2
3 3
4 4

1 1 1
1 2 1
1 3 1
1 4 1
2 1 1
2 2 1
2 3 1
2 4 1
3 1 1
3 2 1
3 3 1
3 4 1
4 1 1
4 2 1
4 3 1
4 4 1

3 2 7
2 5
3 4
4 1
1 10
2 1013
1 7 1000
1 1 1
2 1 1000
3 1 1
4 1 1
1 2 1000
5 2 1

*/