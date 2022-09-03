/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 1e9 + 239;
const int MOD = 1e9 + 7; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //rnd(chrono::high_resolution_clock::now().time_since_epoch().count())

//constants
const int M = 5e5 + 239;
const int N = 2e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

int n, q;
bool used[M];
int l[M], r[M], bef, k;
vector<pair<int, ll> > v[M];
vector<int> id;
vector<tuple<int, int, int> > ask[M];
ll ans[M], h[M];

ll mx[T], add[T], mn[T];

void push(int i, int l, int r)
{
    if (add[i] == -INF) return;
    mx[i] = add[i] - mn[i];
    if (r - l != 1)
    {
        add[2 * i + 1] = add[i];
        add[2 * i + 2] = add[i];
    }
    add[i] = -INF;
}

void build(int i, int l, int r)
{
    if (r - l == 1)
    {
        mn[i] = h[id[l]];
        add[i] = -INF;
        mx[i] = -h[id[l]];
        return;
    }
    add[i] = -INF;
    int mid = (l + r) >> 1;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    mn[i] = min(mn[2 * i + 1], mn[2 * i + 2]);
    mx[i] = max(mx[2 * i + 1], mx[2 * i + 2]);
}

void setval(int i, int l, int r, int ql, int qr, ll x)
{
    push(i, l, r);
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr)
    {
        add[i] = x;
        push(i, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    setval(2 * i + 1, l, mid, ql, qr, x);
    setval(2 * i + 2, mid, r, ql, qr, x);
    mx[i] = max(mx[2 * i + 1], mx[2 * i + 2]);
}

ll getmax(int i, int l, int r, int ql, int qr)
{
    push(i, l, r);
    if (qr <= l || r <= ql) return -INF;
    if (ql <= l && r <= qr) return mx[i];
    int mid = (l + r) >> 1;
    return max(getmax(2 * i + 1, l, mid, ql, qr), getmax(2 * i + 2, mid, r, ql, qr));
}

void dfs_st(int p, ll d)
{
    h[p] = d;
    l[p] = bef;
    if (!used[p])
        bef++;
    for (pair<int, ll> t : v[p])
        dfs_st(t.first, t.second + d);
    r[p] = bef;
}

void dfs(int p, int pr)
{
    setval(0, 0, k, l[p], r[p], 2LL * h[p]);
    for (tuple<int, int, int> t : ask[p])
    {
        int l = get<1>(t);
        int r = get<2>(t);
        int i = get<0>(t);
        ans[i] = h[p] - getmax(0, 0, k, l, r);
    }
    for (pair<int, ll> t : v[p])
        dfs(t.first, p);
    if (pr != -1) setval(0, 0, k, l[p], r[p], 2LL * h[pr]);
}

int32_t main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int p, w;
        cin >> p >> w;
        p--;
        v[p].push_back(make_pair(i, w));
        used[p] = 1;
    }
    for (int i = 0; i < n; i++)
        if (!used[i])
            id.push_back(i);
    for (int i = 0; i < q; i++)
    {
        int p, l, r;
        cin >> p >> l >> r;
        p--, l--, r--;
        l = lower_bound(id.begin(), id.end(), l) - id.begin();
        r = upper_bound(id.begin(), id.end(), r) - id.begin();
        ask[p].push_back(make_tuple(i, l, r));
    }
    k = id.size();
    bef = 0;
    dfs_st(0, 0);
    build(0, 0, k);
    dfs(0, -1);
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;
}