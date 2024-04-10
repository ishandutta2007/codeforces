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

struct drzewo_przedzialowe //drzewo przedzial-przedzial dodaj-dodaj
{
    int rozmiar;
    vector<int> S, modyfikator, L, P;

    int pot(int n)
    {
        int x = 1;
        while (n > x)
            x = x * 2;
        return x;
    }

    drzewo_przedzialowe(int x) //x-rozmiar drzewa
    {
        rozmiar = pot(x);
        modyfikator.resize(2 * rozmiar, 0);
        L.resize(2 * rozmiar);
        S = modyfikator;
        P = L;

        for (int i = rozmiar; i < 2 * rozmiar; i++)
            L[i] = P[i] = i - rozmiar;

        for (int i = rozmiar - 1; i > 0; i--)
        {
            L[i] = L[2 * i];
            P[i] = P[2 * i + 1];
        }
    }

    void zmien(int p, int ile) //dodaje o_ile_zmienic na przedziale [p,q]
    {
        p = p + rozmiar;
        while (p > 0)
        {
            S[p] = max(S[p], ile);
            p = p / 2;
        }
    }
    int suma(int p, int q, int wezel = 1) //zwraca sume na przedziale [p,q]
    {
        if (p > q)
            return 0;
        //cerr << p << " " << q << endl;
        if (p == L[wezel] && q == P[wezel])
            return S[wezel];

        return max(suma(p, min(P[2 * wezel], q), 2 * wezel), suma(max(L[2 * wezel + 1], p), q, 2 * wezel + 1));
    }

    void wypisz()
    {
        for (int i = 1; i < rozmiar * 2; i++)
            cerr << i << ": " << modyfikator[i] << " " << S[i] << endl;
    }
};

const int MAXN = 2e5 + 1e4;
int val[MAXN];
int czas[MAXN];
int n, q;

main()
{
    _upgrade;
    cin >> n;
    rep(i, n)
            cin >>
        val[i];
    cin >> q;
    drzewo_przedzialowe D(q + 10);

    rep(i, q)
    {
        int a, p, x;
        cin >> a;
        if (a == 1)
        {
            cin >> p >> x;
            p--;
            val[p] = x;
            czas[p] = i;
        }
        else
        {
            cin >> x;
            D.zmien(i, x);
        }
    }
    //exit(0);
    // D.wypisz();
    //exit(0);
    rep(i, n)
            cout
        << max(val[i], D.suma(czas[i], q + 1)) << " ";
    cout << endl;
}