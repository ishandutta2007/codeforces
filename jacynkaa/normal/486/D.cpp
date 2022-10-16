#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#include <chrono>
using namespace __gnu_pbds;
using namespace __gnu_pbds;
using namespace std;
//#pragma GCC optimize (-O3)
//#define endl tutaj

#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
#define int long long

vector<vector<int>> G;
vector<int> wartosci;
vector<int> rozmiar_poddrzewa;
vector<bool> odwiedzony;
int n, d;
int obecny = -1;
int wynik = 0;
int mod = 1000000007;
int obecny_wynik;

void dfs(int x)
{
    odwiedzony[x] = true;
    // cout << obecny << ": " << x << endl;
    for (auto y : G[x])
    {
        //cout << y << " ";
        if (odwiedzony[y] == false && ((wartosci[y] > wartosci[obecny] && wartosci[y] <= wartosci[obecny] + d) || (wartosci[y] == wartosci[obecny] && y > obecny)))
        {
            dfs(y);
            rozmiar_poddrzewa[x] = (rozmiar_poddrzewa[x] * (rozmiar_poddrzewa[y] + 1)) % mod;
        }
    }
    //  cout << endl;
}
void akcja(int x)
{
    obecny = x;
    rozmiar_poddrzewa.clear();
    odwiedzony.clear();
    odwiedzony.resize(n + 10, false);
    rozmiar_poddrzewa.resize(n + 10, 1);
    dfs(x);
    wynik = (rozmiar_poddrzewa[x] + wynik) % mod;
    //cout << "wynik dla " << x << " to: " << rozmiar_poddrzewa[x] << endl;
}

void wczytaj()
{
    cin >> d >> n;
    G.resize(n + 10);
    wartosci.resize(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> wartosci[i];
    REP(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    for (int i = 1; i <= n; i++)
        akcja(i);
}

main()
{
    _upgrade;
    wczytaj();
    cout << wynik << endl;
}