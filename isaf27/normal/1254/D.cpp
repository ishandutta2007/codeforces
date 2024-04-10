#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
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
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; // (int)(1e9 + 7);
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 20);
const int B = 500;
const int X = 150239;

int power(int a, int k)
{
    if (k == 0)
        return 1;
    int t = power(a, k >> 1);
    t = 1LL * t * t % MOD;
    if (k & 1)
        t = 1LL * t * a % MOD;
    return t;
}

int n, q, et[X], pos, f[X], sz[X];
vector<int> v[X];
vector<tuple<int, int, int>> seg[M];

void dfs_et(int p, int pr)
{
    int st = pos;
    et[pos++] = p;
    sz[p] = 1;
    for (int i : v[p])
        if (i != pr)
        {
            int was = pos;
            dfs_et(i, p);
            seg[p].push_back(make_tuple(was, pos - 1, sz[i]));
            sz[p] += sz[i];
        }
    if (st > 0)
        seg[p].push_back(make_tuple(0, st - 1, n - sz[p]));
    if (pos < n)
        seg[p].push_back(make_tuple(pos, n - 1, n - sz[p]));
}

ll tree[X];

void add_tree(int i, ll c)
{
    if (c < 0)
        c += MOD2;
    for (; i < n; i |= i + 1)
    {
        tree[i] += c;
        if (tree[i] >= MOD2)
            tree[i] -= MOD2;
    }
}

void add(int l, int r, ll c)
{
    add_tree(r + 1, -c);
    add_tree(l, c);
}

int getost(int i)
{
    ll ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
    {
        ans += tree[i];
        if (ans >= MOD2)
            ans -= MOD2;
    }
    return (ans % (ll)MOD);
}

const int MG = 200;

int vq[X], dq[X], sq[X], aq[X];

int cf[X];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    dfs_et(0, -1);
    for (int i = 0; i < n; i++)
        f[et[i]] = i;
    vector<int> bg;
    for (int i = 0; i < n; i++)
        if (seg[i].size() > MG)
            bg.push_back(i);
    int s = 0;
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cin >> vq[i] >> dq[i];
            vq[i]--;
            s = (s + dq[i]);
            if (s >= MOD)
                s -= MOD;
            sq[i] = s;
        }
        else
        {
            cin >> vq[i];
            vq[i]--;
            sq[i] = s;
            dq[i] = -1;
        }
    }
    for (int c : bg)
    {
        cf[c] = 0;
        for (tuple<int, int, int> t : seg[c])
            for (int i = get<0>(t); i <= get<1>(t); i++)
                cf[et[i]] = get<2>(t);
        int s = 0;
        for (int i = 0; i < q; i++)
        {
            if (dq[i] == -1)
            {
                aq[i] += 1LL * cf[vq[i]] * s % MOD;
                if (aq[i] >= MOD)
                    aq[i] -= MOD;
            }
            else if (vq[i] == c)
            {
                s += dq[i];
                if (s >= MOD)
                    s -= MOD;
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        if (dq[i] != -1)
        {
            int s = vq[i];
            if (seg[s].size() <= MG)
            {
                for (tuple<int, int, int> t : seg[s])
                    add(get<0>(t), get<1>(t), (ll)dq[i] * (ll)get<2>(t));
            }
        }
        else
        {
            aq[i] += getost(f[vq[i]]);
            if (aq[i] >= MOD)
                aq[i] -= MOD;
        }
    }
    int inv = power(n, MOD - 2);
    for (int i = 0; i < q; i++)
        if (dq[i] == -1)
        {
            sq[i] -= 1LL * inv * aq[i] % MOD;
            if (sq[i] < 0)
                sq[i] += MOD;
            cout << sq[i] << "\n";
        }
    return 0;
}