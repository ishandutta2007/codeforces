//#pragma GCC optimize("O3")
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
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;

//random
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(5e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = (1 << 20) + 239;

int cnt[X], par[X], rg[X];
int n, a[M], b[M];

int fnd(int i)
{
    if (i == par[i])
        return i;
    return (par[i] = fnd(par[i]));
}

void merge(int s, int f)
{
    s = fnd(s);
    f = fnd(f);
    if (s == f)
        return;
    if (rg[s] > rg[f])
        swap(s, f);
    par[s] = f;
    if (rg[s] == rg[f])
        rg[f]++;
}

set<pair<int, int>> v[X];

void solve(int k)
{
    for (int i = 0; i < n; i++)
    {
        a[i] &= (1 << k) - 1;
        b[i] &= (1 << k) - 1;
        v[a[i]].insert(make_pair(b[i], 2 * i));
        v[b[i]].insert(make_pair(a[i], 2 * i + 1));
    }
    vector<pair<int, int>> ans;
    vector<pair<int, int>> st;
    st.push_back(make_pair(a[0], -1));
    while (!st.empty())
    {
        int x = st.back().first;
        if (v[x].empty())
        {
            ans.push_back(st.back());
            st.pop_back();
            continue;
        }
        pair<int, int> go = (*v[x].begin());
        v[x].erase(go);
        v[go.first].erase(make_pair(x, go.second ^ 1));
        st.push_back(go);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 1; i < (int)ans.size(); i++)
    {
        int id = ans[i].second;
        cout << (id + 1) << " " << ((id ^ 1) + 1) << " ";
    }
    cout << "\n";
#ifdef ONPC
    for (int i = 1; i < (int)ans.size(); i++)
    {
        int id = ans[i].second;
        if (id % 2 == 0)
            cout << a[id / 2] << " | " << b[id / 2] << " ";
        else
            cout << b[id / 2] << " | " << a[id / 2] << " ";
    }
    cout << "\n";
#endif
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int k = 20; k >= 0; k--)
    {
        for (int t = 0; t < (1 << k); t++)
        {
            cnt[t] = 0;
            par[t] = t;
            rg[t] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cnt[a[i] & ((1 << k) - 1)]++;
            cnt[b[i] & ((1 << k) - 1)]++;
            merge(a[i] & ((1 << k) - 1), b[i] & ((1 << k) - 1));
        }
        int need = fnd(a[0] & ((1 << k) - 1));
        bool ch = true;
        for (int i = 0; i < n && ch; i++)
        {
            ch &= (need == fnd(a[i] & ((1 << k) - 1)));
            ch &= (need == fnd(b[i] & ((1 << k) - 1)));
        }
        for (int t = 0; t < (1 << k) && ch; t++)
            if (cnt[t] & 1)
                ch = false;
        if (ch)
        {
            cout << k << "\n";
            solve(k);
            return 0;
        }
    }
    return 0;
}