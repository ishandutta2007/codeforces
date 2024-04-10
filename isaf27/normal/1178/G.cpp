#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00

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
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(1e3 + 239);
const int L = 18;
const int T = (1 << 20);
const int B = 200;
const int X = 1000;

#define tm kekekek

ll a[M], b[M], sa[M], sb[M];
vector<int> ch[M];
vector<pair<ll, ll> > al;
int lg[M], rg[M], tm;

void dfs(int p)
{
    lg[p] = tm++;
    sa[p] += a[p];
    sb[p] += b[p];
    al.push_back(make_pair(sa[p], sb[p]));
    for (int i : ch[p])
    {
        sa[i] += sa[p];
        sb[i] += sb[p];
        dfs(i);
    }
    rg[p] = tm;
}

int n, q;
pair<ll, ll> l[M];
int id[M];


ll cur_x[X], sum[X], mx[X];
vector<pair<ld, int> > st[X];

bool cmp(int i, int j)
{
    return l[i] < l[j];
}

ld inter(int i, int j)
{
    return (ld)(l[j].second - l[i].second) / (ld)(l[i].first - l[j].first);
}

void add(int nm, int i)
{
    while (!st[nm].empty())
    {
        int j = st[nm].back().second;
        if (l[i].first == l[j].first)
        {
            if (l[i].second <= l[j].second)
                return;
            st[nm].pop_back();
            continue;
        }
        ld nx = inter(i, j);
        if (nx <= st[nm].back().first)
        {
            st[nm].pop_back();
            continue;
        }
        st[nm].push_back(make_pair(nx, i));
    }
    st[nm].push_back(make_pair(-INF, i));
}

ll getcur(int nm)
{
    int it = upper_bound(st[nm].begin(), st[nm].end(), make_pair((ld)cur_x[nm], n)) - st[nm].begin() - 1;
    it = st[nm][it].second;
    return l[it].first * cur_x[nm] + l[it].second;
}

void remake_block(int nm)
{
    st[nm].clear();
    int r = min(n, (nm + 1) * B);
    sort(id + (nm * B), id + r, cmp);
    for (int x = nm * B; x < min(n, (nm + 1) * B); x++)
        add(nm, id[x]);
}

ll slow_one_block(int nm, int ls, int rs)
{
    ll ans = 0;
    for (int x = nm * B; x < min(n, (nm + 1) * B); x++)
        if (ls <= x && x <= rs)
            ans = max(ans, l[x].first * cur_x[nm] + l[x].second);
    return ans;
}

ll getans(int ls, int rs)
{
    ll ans = 0;
    int bl = (ls / B);
    int br = (rs / B);
    ans = max(ans, slow_one_block(bl, ls, rs));
    if (br != bl)
        ans = max(ans, slow_one_block(br, ls, rs));
    for (int i = bl + 1; i < br; i++)
        ans = max(ans, getcur(i));
    return ans;
}

void upd_one_block(int nm, int ls, int rs, int xp)
{
    for (int x = nm * B; x < min(n, (nm + 1) * B); x++)
    {
        sb[x] = abs(sb[x]);
        sa[x] += sum[nm];
    }
    sum[nm] = 0;
    mx[nm] = -INF;
    for (int x = nm * B; x < min(n, (nm + 1) * B); x++)
        if (ls <= x && x <= rs)
            sa[x] += xp;
    for (int x = nm * B; x < min(n, (nm + 1) * B); x++)
    {
        if (sa[x] < 0)
        {
            sb[x] = -sb[x];
            mx[nm] = max(mx[nm], sa[x]);
        }
        l[x] = make_pair(sb[x], sa[x] * sb[x]);
        id[x] = x;
    }
    cur_x[nm] = 0;
    remake_block(nm);
}

void upd(int nm, int xp)
{
    if (mx[nm] + sum[nm] + xp >= 0)
    {
        upd_one_block(nm, 0, n, xp);
        return;
    }
    sum[nm] += xp;
    cur_x[nm] += xp;
}

void upd(int ls, int rs, int x)
{
    int bl = (ls / B);
    int br = (rs / B);
    upd_one_block(bl, ls, rs, x);
    if (br != bl)
        upd_one_block(br, ls, rs, x);
    for (int i = bl + 1; i < br; i++)
        upd(i, x);
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        ch[p].push_back(i);
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    tm = 0;
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        sa[i] = al[i].first;
        sb[i] = al[i].second;
    }
    for (int i = 0; i < n; i++)
        sb[i] = abs(sb[i]);
    for (int i = 0; i < X; i++)
        mx[i] = -INF;
    for (int i = 0; i < n; i++)
    {
        if (sa[i] < 0)
        {
            sb[i] = -sb[i];
            mx[i / B] = max(mx[i / B], sa[i]);
        }
        l[i] = make_pair(sb[i], sa[i] * sb[i]);
        id[i] = i;
    }
    for (int i = 0; i < n; i += B)
        remake_block(i / B);
    for (int z = 0; z < q; z++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int vn, x;
            cin >> vn >> x;
            vn--;
            int ls = lg[vn];
            int rs = rg[vn];
            upd(ls, rs - 1, x);
        }
        else
        {
            int vn;
            cin >> vn;
            vn--;
            int ls = lg[vn];
            int rs = rg[vn];
            cout << getans(ls, rs - 1) << "\n";
        }
    }
    return 0;
}