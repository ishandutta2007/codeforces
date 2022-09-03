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
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 2e9 + 239;
const ll MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = 2e5 + 239;
const int N = 2e3 + 239;
const int L = 19;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;
const int e = 8;

ll x[e][th];

ll dist(int i, int j)
{
    return (x[i][0] - x[j][0]) * (x[i][0] - x[j][0]) + (x[i][1] - x[j][1]) * (x[i][1] - x[j][1]) + (x[i][2] - x[j][2]) * (x[i][2] - x[j][2]);
}

int deg[e];

bool check()
{
    ll mn = INF;
    for (int i = 0; i < e; i++)
        for (int j = i + 1; j < e; j++)
            mn = min(mn, dist(i, j));
    if (mn == 0)
        return false;
    for (int i = 0; i < e; i++)
        deg[i] = 0;
    for (int i = 0; i < e; i++)
        for (int j = i + 1; j < e; j++)
            if (mn == dist(i, j))
                deg[i]++, deg[j]++;
    for (int i = 0; i < e; i++)
        if (deg[i] != 3)
            return false;
    map<ll, int> kol;
    for (int i = 0; i < e; i++)
        for (int j = i + 1; j < e; j++)
            kol[dist(i, j)]++;
    if (kol[2LL * mn] != 12)
        return false;
    if (kol[3LL * mn] != 4)
        return false;
    return true;
}

void gen(int b)
{
    if (b == e)
    {
        if (check())
        {
            cout << "YES\n";
            for (int i = 0; i < e; i++)
            {
                for (int t = 0; t < 3; t++)
                    cout << x[i][t] << " ";
                cout << "\n";
            }
            exit(0);
        }
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        next_permutation(x[b], x[b] + 3);
        gen(b + 1);
    }
}

int32_t main()
{
    #ifdef ONPC
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < e; i++)
        cin >> x[i][0] >> x[i][1] >> x[i][2];
    gen(0);
    cout << "NO";
    return 0;
}