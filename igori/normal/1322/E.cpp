#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

const int N = 500100;
const int INF = 1e9;
int n;
int a[N];
set<int> g1, g2, g12;
map<int, int> mm;
vector<int> tails[N + 2];

void Add(int p)
{
    g12.insert(p);
    auto it = g12.find(p);
    it--;
    int x = *it;
    it++;
    int y = *it;
    it++;
    int z = *it;
    mm[z - x]--;
    if (mm[z - x] == 0) mm.erase(z - x);
    mm[y - x]++;
    mm[z - y]++;
}

void Del(int p)
{
    auto it = g12.find(p);
    it--;
    int x = *it;
    it++;
    int y = p;
    it++;
    int z = *it;
    it--;
    mm[z - x]++;
    mm[y - x]--;
    if (mm[y - x] == 0) mm.erase(y - x);
    mm[z - y]--;
    if (mm[z - y] == 0) mm.erase(z - y);
    g12.erase(it);
}

int b[N];
vector<pair<int, int> > e;
int c[N];
int ans = 0;

struct q{
    int l, r, c;
};
vector<q> qs;

void LeftUpdate(auto &it, int i)
{
    int pos = *it;
    if (abs(pos) == INF) return;
    auto it2 = g2.upper_bound(pos);
    it--, it2--;
    if (*it == pos) it--;
    int L1 = *it, L2 = *it2;
    it++;
    if (L1 == -INF && L2 == -INF) return;
    //cout << pos << " > " << L1 << " " << L2 << endl;
    if (L1 > L2)
    {
        qs.push_back({L1 + 1, pos, e[i].first});
    }
    else
    {
        qs.push_back({(L2 + pos) / 2 + 1, pos, e[i].first});
    }
}

void RightUpdate(auto &it, int i)
{
    int pos = *it;
    if (abs(pos) == INF) return;
    it++;
    auto it2 = g2.upper_bound(pos);
    int R1 = *it, R2 = *it2;
    it--;
    if (R1 == INF && R2 == INF) return;
    //cout << pos << " < " << R1 << " " << R2 << endl;
    if (R1 < R2)
    {
        qs.push_back({pos + 1, R1, e[i].first});
    }
    else
    {
        qs.push_back({pos + 1, (R2 + pos) / 2, e[i].first});
    }
}

signed main()
{
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    #endif // ONLINE_JUDGE
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        e.push_back({a[i], i});
    }
    a[0] = a[1], a[n + 1] = a[n];
    e.push_back({a[0], 0});
    e.push_back({a[n + 1], n + 1});
    sort(all(e));
    b[n + 1] = 2;
    for (int i = 0; i <= n; i++)
    {
        b[i] = 2;
        g2.insert(i);
        g12.insert(i);
    }
    g1.insert(-INF);
    g2.insert(-INF);
    g1.insert(INF);
    g2.insert(INF);
    g12.insert(-INF);
    g12.insert(INF);
    vector<int> kek;
    for (auto e : g12) kek.push_back(e);
    for (int i = 0; i + 1 < kek.size(); i++) mm[kek[i + 1] - kek[i]]++;
    for (int i = 0; i < n + 2; i++)
    {
        int p = e[i].second;
        //cout << "computing " << e[i].fi << " " << e[i].se << endl;
        if (p - 1 >= 0 && b[p - 1] == 2)
            g2.erase(p - 1), Del(p - 1);
        if (p <= n && b[p + 1] == 2)
            g2.erase(p), Del(p);
        if (p - 1 >= 0 && b[p - 1] == 1)
            g1.insert(p - 1), Add(p - 1);
        if (p <= n && b[p + 1] == 1)
            g1.insert(p), Add(p);
        auto it = g1.lower_bound(p);
        LeftUpdate(it, i);
        if (*it == p) RightUpdate(it, i);
        //cout << "Does operations from " << *it << " > " << p << " > ";
        it--;
        //cout << *it << endl;
        if (*it == p - 1) LeftUpdate(it, i);
        RightUpdate(it, i);
        b[p] = 1;
        if (i + 1 < n + 2 && e[i].first != e[i + 1].first)
        {
            auto it = mm.end();
            it--;
            it--;
            it--;
            ans = max(ans, (*it).first);
        }
    }
    for (int i = 0; i < qs.size(); i++)
    {
        qs[i].l = max(qs[i].l, 1);
        qs[i].r = min(qs[i].r, n);
        tails[qs[i].l].push_back(i + 1);
        tails[qs[i].r].push_back(-i - 1);
    }
    set<int> scan;
    for (int i = 1; i <= n; i++)
    {
        for (auto e : tails[i]) if (e > 0) scan.insert(e);
        int x = *scan.begin();
        x--;
        c[i] = qs[x].c;
        for (auto e : tails[i]) if (e < 0) scan.erase(-e);
    }
    cout << (ans - 1) / 2 << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << c[i] << " ";
    }
}