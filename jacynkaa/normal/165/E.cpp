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
const int MAXN = 22;

int tab[1 << MAXN];
vector<int> liczby;
int n;

int odw(int x)
{
    return (1 << 22) - 1 - x;
}

void solve()
{
    cin >> n;
    liczby.resize(n);
    fill(tab, tab + (1 << MAXN), -1);
    rep(i, n)
    {
        cin >> liczby[i];
        tab[liczby[i]] = liczby[i];
    }
    rep(j, 1 << MAXN) rep(k, MAXN)
    {
        if ((1 << k) & j)
            tab[j] = max(tab[j], tab[j ^ (1 << k)]);
    }
    for (auto a : liczby)
        cout << tab[odw(a)] << " ";
    cout << endl;
}

main()
{
    _upgrade;
    solve();
}