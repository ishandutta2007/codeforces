#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
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
const ld eps = 1e-9;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 1e9 + 7; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(5e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = (int)sqrt(M);
const int X = 1e3 + 239;

int n, m, q, kol[M], a, g, ans[M], idx[M];
vector<int> f[M];
ll k, pref[M];
vector<pair<int, int> > al;

int sum[T];

void upd(int i, int l, int r, int p)
{
    sum[i]++;
    if (r - l == 1) return;
    int mid = (l + r) >> 1;
    if (p < mid)
        upd(2 * i + 1, l, mid, p);
    else
        upd(2 * i + 2, mid, r, p);
}

int gett(int i, int l, int r, int p)
{
    if (r - l == 1) return l;
    int mid = (l + r) >> 1;
    if (sum[2 * i + 1] > p)
        return gett(2 * i + 1, l, mid, p);
    return gett(2 * i + 2, mid, r, p - sum[2 * i + 1]);
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        kol[a - 1]++;
    }
    for (int i = 0; i < m; i++)
        al.push_back(make_pair(kol[i], i));
    sort(al.begin(), al.end());
    vector<pair<int, int> > s;
    int l = 0;
    for (int i = 0; i < m; i++)
    {
        if (i == 0 || al[i].first == al[i - 1].first)
            continue;
        s.push_back(make_pair(l, i));
        l = i;
    }
    s.push_back(make_pair(l, m));
    g = s.size();
    for (int i = 0; i < g - 1; i++)
        pref[i] = (ll)(al[s[i + 1].first].first - al[s[i].first].first) * (ll)s[i].second;
    for (int i = 1; i < g - 1; i++)
        pref[i] += pref[i - 1];
    for (int z = 0; z < q; z++)
    {
        idx[z] = -1;
        cin >> k;
        k -= n;
        if (g == 1 || pref[g - 2] < k)
        {
            if (g > 1) k -= pref[g - 2];
            ans[z] = ((k - 1) % (ll)m);
            continue;
        }
        int p = lower_bound(pref, pref + (g - 1), k) - pref;
        if (p > 0) k -= pref[p - 1];
        idx[z] = (k - 1) % (ll)s[p].second;
        f[p].push_back(z);
    }
    for (int i = 0; i < g - 1; i++)
    {
        for (int t = s[i].first; t < s[i].second; t++)
            upd(0, 0, m, al[t].second);
        for (int t : f[i])
            ans[t] = gett(0, 0, m, idx[t]);
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] + 1 << "\n";
    return 0;
}