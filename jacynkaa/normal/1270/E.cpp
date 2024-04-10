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

vector<int> indeksy[2][2];
int n;

void podziel_na_klasy(vector<pii> &V)
{
    rep(i, 2) rep(j, 2) indeksy[i][j].clear();
    rep(i, n) indeksy[V[i].st % 2][V[i].nd % 2].push_back(i);
}

void zmien(vector<pii> &V)
{
    for (auto &P : V)
    {
        P.st /= 2;
        P.nd /= 2;
    }
}

int OK()
{
    int licznik = 0;
    rep(i, 2) rep(j, 2) if (indeksy[i][j].size() > 0) licznik++;
    return licznik;
}

void ans()
{
    if (indeksy[0][1].size() + indeksy[1][0].size() == n)
    {
        cout << indeksy[0][1].size() << endl;

        for (int a : indeksy[0][1])
            cout << a + 1 << " ";
        cout << endl;
        return;
    }
    if (indeksy[1][1].size() + indeksy[0][0].size() == n)
    {
        cout << indeksy[0][0].size() << endl;

        for (int a : indeksy[0][0])
            cout << a + 1 << " ";
        cout << endl;
        return;
    }

    cout << indeksy[0][0].size() + indeksy[1][1].size() << endl;

    for (int a : indeksy[0][0])
        cout << a + 1 << " ";
    for (int a : indeksy[1][1])
        cout << a + 1 << " ";
    cout << endl;
    return;
}
main()
{
    _upgrade;

    cin >> n;
    vector<pii> V(n);
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        a += (1 << 25);
        b += (1 << 25);
        V[i] = {a, b};
    }
    podziel_na_klasy(V);
    while (OK() == 1)
    {
        cerr << "zmieniam" << endl;
        zmien(V);
        podziel_na_klasy(V);
    }
    ans();
}