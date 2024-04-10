//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0

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
const ll MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = 500;
const int X = 120;

typedef bitset<X> bt;

int n, k, s;
vector<int> p[X];
int to[X][X];

vector<int> sum(vector<int> a, vector<int> b)
{
    vector<int> c(a.size());
    for (int i = 0; i < a.size(); i++)
        c[i] = b[a[i]];
    return c;
}

map<vector<int>, int> id;

bt kill(bt a, int x)
{
    //if (cs.find(make_pair(a, x)) != cs.end())
    //    return cs[make_pair(a, x)];
    bt st = a;
    while (true)
    {
        bt b = a;
        for (int i = 0; i < s; i++)
            if (b[i])
            {
                b[to[i][x]] = 1;
                b[to[x][i]] = 1;
            }
        for (int i = 0; i < s; i++)
            if (b[i])
                for (int j = 0; j < s; j++)
                    if (b[j])
                        b[to[i][j]] = 1;
        if (b == a)
            return b;
        a = b;
    }
}

#define hash kkekekekekekk

pair<ll, ll> hash(bt a)
{
    ll h1 = 0;
    for (ll i = 0; i < (s / 2); i++)
        h1 ^= ((ll)a[i] << i);
    ll h2 = 0;
    for (ll i = (s / 2); i < s; i++)
        h2 ^= ((ll)a[i] << (i - (s / 2)));
    return make_pair(h1, h2);
}

bt out(pair<ll, ll> a)
{
    bt b = 0;
    for (ll i = 0; i < (s / 2); i++)
        b[i] = (a.first >> i) & 1LL;
    for (ll i = (s / 2); i < s; i++)
        b[i] = (a.second >> (i - (s / 2))) & 1LL;
    return b;
}

map<pair<ll, ll>, pair<ll, ll>> cash;

bt make(bt a)
{
    pair<ll, ll> st = hash(a);
    if (cash.find(st) != cash.end())
        return out(cash[st]);
    bt b = 0;
    b[0] = 1;
    while (true)
    {
        bt fr = b;
        for (int i = 0; i < s; i++)
            if (b[i])
                for (int j = 0; j < s; j++)
                    if (a[j])
                        b[to[i][j]] = 1;
        if (fr == b)
        {
            cash[st] = hash(b);
            return b;
        }
    }
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector<int> u;
    for (int i = 0; i < k; i++)
        u.push_back(i);
    s = 0;
    do
    {
        p[s++] = u;
    } while (next_permutation(u.begin(), u.end()));
    for (int i = 0; i < s; i++)
        id[p[i]] = i;
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            to[i][j] = id[sum(p[i], p[j])];
    vector<pair<int, bt>> st;
    bt emp = 0;
    emp[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> v(k);
        for (int t = 0; t < k; t++)
        {
            int s;
            cin >> s;
            v[s - 1] = t;
        }
        st.push_back(make_pair(i, emp));
        int cid = id[v];
        for (auto& t : st)
            if (t.second[cid] == 0)
            {
                t.second[cid] = 1;
                t.second = make(t.second);
            }
        vector<pair<int, bt>> nw;
        for (auto& t : st)
        {
            if (!nw.empty() && nw.back().second == t.second)
                continue;
            nw.push_back(t);
        }
        st = nw;
        int ls = i + 1;
        for (int t = (int)st.size() - 1; t >= 0; t--)
        {
            ans += (ll)(ls - st[t].first) * st[t].second.count();
            ls = st[t].first;
        }
    }
    /*ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            bt at = emp;
            for (int x = i; x <= j; x++)
                at = kill(at, a[x]);
            ans += at.count();
        }*/
    cout << ans;
    return 0;
}