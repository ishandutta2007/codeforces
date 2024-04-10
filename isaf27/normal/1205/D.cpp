//#pragma GCC optimize("O3")
#ifdef ONPC
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00
#define y1 y11
#define int ll

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dxk[8] = {-1, -2, -1, 2, -2, 1, 1, 2};
const int dyk[8] = {-2, -1, 2, -1, 1, -2, 2, 1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = (int)sqrt(M);
const int X = 1010;

int n, kol[X];
vector<int> v[X];

void dfs_kol(int p, int pr)
{
    kol[p] = 1;
    for (int i : v[p])
        if (i != pr)
        {
            dfs_kol(i, p);
            kol[p] += kol[i];
        }
}

int centroid(int p, int pr)
{
    for (int i : v[p])
        if (i != pr && 2 * kol[i] > n)
            return centroid(i, p);
    return p;
}

int f[X];
vector<int> order;

void dfs_ord(int p, int pr)
{
    order.push_back(p);
    for (int i : v[p])
        if (i != pr)
            dfs_ord(i, p);
}

void dfs_ans(int p, int pr)
{
    for (int i : v[p])
        if (i != pr)
        {
            cout << i + 1 << " " << p + 1 << " " << f[i] - f[p] << "\n";
            dfs_ans(i, p);
        }
}

int32_t main() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    dfs_kol(0, -1);
    int c = centroid(0, -1);
    dfs_kol(c, -1);
    vector<pair<int, int>> to;
    for (int i : v[c])
        to.push_back(make_pair(kol[i], i));
    sort(to.rbegin(), to.rend());
    vector<int> a;
    vector<int> b;
    int sa = 0;
    int sb = 0;
    for (pair<int, int> t : to)
    {
        if (sa <= sb)
        {
            a.push_back(t.second);
            sa += t.first;
        }
        else
        {
            b.push_back(t.second);
            sb += t.first;
        }
    }
    f[c] = 0;
    order.clear();
    for (int x : a)
        dfs_ord(x, c);
    for (int i = 0; i < order.size(); i++)
        f[order[i]] = i + 1;
    order.clear();
    for (int x : b)
        dfs_ord(x, c);
    for (int i = 0; i < order.size(); i++)
        f[order[i]] = (i + 1) * (sa + 1);
    dfs_ans(c, -1);
    return 0;
}