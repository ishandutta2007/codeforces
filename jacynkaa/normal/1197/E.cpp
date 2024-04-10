
#include <bits/stdc++.h>
#include <math.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("-O3")
#define endl '\n'
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define int long long
#define double long double

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int MAXN = 5 * 1e5 + 199;
const int MOD = 1e9 + 7;

int in[MAXN];
int out[MAXN];
int dp[MAXN];
int wasted[MAXN];
vector<int> poIn;
vector<int> poOut;
int indeksOutPoczatek = 0;
int indeksOutKoniec = 0;
int currentMaxIn = -12345;

bool compIn(int a, int b)
{
    return in[a] < in[b];
}
bool compOut(int a, int b)
{
    return out[a] < out[b];
}

struct BB
{
    gp_hash_table<int, int, custom_hash> M1;
    gp_hash_table<int, int, custom_hash> M2;
    set<int> indeksy;

    void change(int p, int val)
    {
        if (M2[p] == 0 && M1[p] == 0)
            indeksy.insert(p);
        M1[p] = M1[p] + val;
        M2[p] = (M2[p] + val + MOD + MOD) % MOD;
        if (M2[p] == 0 && M1[p] == 0)
            indeksy.erase(p);
    }
    void get(int x)
    {
        if (!indeksy.empty())
        {
            wasted[x] = *indeksy.begin() + in[x];
            dp[x] = M2[*indeksy.begin()];
        }
        else
        {
            wasted[x] = in[x];
            dp[x] = 1;
        }
    }
    void clear()
    {
        M1.clear();
        M2.clear();
        indeksy.clear();
    }
};

main()
{

    _upgrade;
    int n;
    cin >> n;
    rep(i, n)
    {
        cin >> out[i] >> in[i];
        poIn.pb(i);
        poOut.pb(i);
    }

    BB blackbox;
    sort(all(poIn), compIn);
    sort(all(poOut), compOut);

    for (int a : poIn)
    {
        int x = poOut[indeksOutKoniec];
        while (out[x] <= in[a])
        {
            wasted[x] -= out[x];
            blackbox.change(wasted[x], dp[x]);
            currentMaxIn = max(currentMaxIn, in[x]);
            indeksOutKoniec++;
            x = poOut[indeksOutKoniec];
        }
        x = poOut[indeksOutPoczatek];
        while (out[x] <= currentMaxIn)
        {
            blackbox.change(wasted[x], -dp[x]);
            indeksOutPoczatek++;
            x = poOut[indeksOutPoczatek];
        }
        blackbox.get(a);
    }

    blackbox.clear();
    int x = poOut[indeksOutKoniec];
    while (indeksOutKoniec < n)
    {
        blackbox.change(wasted[x], dp[x]);
        indeksOutKoniec++;
        x = poOut[indeksOutKoniec];
    }
    blackbox.get(0);
    cout << dp[0] << endl;
}