//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int two = 2;
const ld eps = 1e-10;
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(5e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 510;
const int X = 1e4 + 239;

int n;
int s[M], f[M], c[M];
vector<int> v[M];

int h[M], da[M], db[M];

void dfs_h(int p, int pr, int gl)
{
    h[p] = gl;
    for (int i : v[p])
    {
        int to = s[i] ^ f[i] ^ p;
        if (to != pr)
            dfs_h(to, p, gl + 1);
    }
}

int order[M], k, pos[M], init[M];
int l[M], r[M];

void dfs_order(int p, int pr, int go)
{
    init[p] = go;
    pos[p] = k;
    order[k++] = p;
    for (int i : v[p])
    {
        int to = s[i] ^ f[i] ^ p;
        if (to != pr)
        {
            l[i] = k;
            dfs_order(to, p, go ^ c[i]);
            r[i] = k;
        }
    }
}

int mx[2][2][T];
int add[T], color[T];

void push(int i, int l, int r)
{
    if (add[i] == 0)
        return;
    color[i] ^= 1;
    swap(mx[0][0][i], mx[0][1][i]);
    swap(mx[1][0][i], mx[1][1][i]);
    if (r - l != 1)
    {
        add[2 * i + 1] ^= 1;
        add[2 * i + 2] ^= 1;
    }
    add[i] = 0;
}

void sum(int i, int l, int r)
{
    if (r - l == 1)
        return;
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            mx[x][y][i] = max(mx[x][y][2 * i + 1], mx[x][y][2 * i + 2]);
}

void upd(int i, int l, int r, int ql, int qr)
{
    push(i, l, r);
    if (qr <= l || r <= ql)
        return;
    if (ql <= l && r <= qr)
    {
        add[i] ^= 1;
        push(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(2 * i + 1, l, mid, ql, qr);
    upd(2 * i + 2, mid, r, ql, qr);
    sum(i, l, r);
}

int getsign(int i, int l, int r, int p)
{
    push(i, l, r);
    if (r - l == 1)
        return color[i];
    int mid = (l + r) / 2;
    if (p < mid)
        return getsign(2 * i + 1, l, mid, p);
    return getsign(2 * i + 2, mid, r, p);
}

void build(int i, int l, int r)
{
    if (r - l == 1)
    {
        mx[0][init[order[l]]][i] = da[order[l]];
        mx[1][init[order[l]]][i] = db[order[l]];
        color[i] = init[order[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    sum(i, l, r);
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> s[i] >> f[i] >> c[i];
        s[i]--;
        f[i]--;
        v[s[i]].push_back(i);
        v[f[i]].push_back(i);
    }
    dfs_h(0, -1, 0);
    int A = 0;
    for (int i = 0; i < n; i++)
        if (h[A] < h[i])
            A = i;
    dfs_h(A, -1, 0);
    for (int i = 0; i < n; i++)
        da[i] = h[i];
    int B = 0;
    for (int i = 0; i < n; i++)
        if (h[B] < h[i])
            B = i;
    dfs_h(B, -1, 0);
    for (int i = 0; i < n; i++)
        db[i] = h[i];
    dfs_order(0, -1, 0);
    build(0, 0, n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int id;
        cin >> id;
        id--;
        upd(0, 0, n, l[id], r[id]);
        int sa = getsign(0, 0, n, pos[A]);
        int sb = getsign(0, 0, n, pos[B]);
        cout << max(mx[0][sa][0], mx[1][sb][0]) << "\n";
    }
    return 0;
}