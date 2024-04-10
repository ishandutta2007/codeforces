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

int tab[4];

int sum = 0;
vector<int> wynik;

bool check()
{
    // cerr << "halo" << endl;
    /*
    rep(i, sum)
            cerr
        << wynik[i] << " ";
    cerr << endl;
    */
    rep(i, sum - 1) if (abs(wynik[i] - wynik[i + 1]) != 1) return false;
    return true;
}

bool solve()
{
    cin >> tab[0] >> tab[1] >> tab[2] >> tab[3];
    rep(i, 4)
        sum += tab[i];

    if ((tab[0] + tab[2] > tab[3] + tab[1] + 1) || (tab[1] + tab[3] > tab[2] + tab[0] + 1))
        return false;

    wynik.resize(sum);
    if (tab[0] + tab[2] >= tab[1] + tab[3])
    {
        rep(i, tab[0] + tab[2])
            wynik[2 * i] = (tab[0] > i) ? 0 : 2;
        rep(i, tab[1] + tab[3])
            wynik[2 * i + 1] = (tab[1] > i) ? 1 : 3;
    }
    else
    {
        rep(i, tab[1] + tab[3])
            wynik[2 * i] = (tab[1] > i) ? 1 : 3;
        rep(i, tab[0] + tab[2])
            wynik[2 * i + 1] = (tab[0] > i) ? 0 : 2;
    }

    return check();
}

main()
{
    _upgrade;
    if (solve())
    {
        cout << "YES" << endl;
        for (int a : wynik)
            cout << a << " ";
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}