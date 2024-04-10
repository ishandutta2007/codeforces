#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
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
#define what(x) cerr << #x << " is " << x << endl;
#define int long long
const int MAXN = 20;
const int MOD = 1e9 + 7;

int tab[1 << MAXN];
int pot[1 << MAXN];
int ile[1 << MAXN];
int n;

int odw(int x)
{
    return (1 << MAXN) - 1 - x;
}

int val(int x)
{
    // what(x);
    //what(ile[x]);
    //what(tab[x]);
    int a = (pot[tab[x]] - 1) % MOD;
    if ((MAXN - __builtin_popcount(x)) % 2)
        return MOD - a;
    return a;
}

void solve()
{
    cin >> n;
    pot[0] = 1;
    for (int i = 1; i < (1 << MAXN); i++)
        pot[i] = (pot[i - 1] * 2) % MOD;

    rep(i, n)
    {
        int a;
        cin >> a;
        tab[odw(a)]++;
        ile[odw(a)]++;
    }

    rep(k, MAXN) rep(j, 1 << MAXN)
    {
        if ((1 << k) & j)
            tab[j] = tab[j] + tab[j ^ (1 << k)];
    }

    int wynik = 0;
    rep(j, 1 << MAXN)
        wynik = (wynik + val(j)) % MOD;

    cout << (wynik) % MOD << endl;
}

main()
{
    _upgrade;
    solve();
}