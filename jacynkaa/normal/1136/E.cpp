#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#include <chrono>
#pragma GCC optimize("-O3")
using namespace __gnu_pbds;
using namespace std;

#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) // ,cin.tie(0), cout.tie(0)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)

#define int long long

struct drzewo_przedzialowe
{
    int rozmiar;
    vector<int> modyfikator, S, L, P;

    int pot(int n)
    {
        int x = 1;
        while (n > x)
            x = x * 2;
        return x;
    }

    drzewo_przedzialowe(int x)
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

    void zmien(int p, int q, int o_ile_zmienic, int wezel = 1)
    {
        //  cout << p << " " << q << " " << o_ile_zmienic << endl;
        if (p > q)
            return;

        if (p == L[wezel] && q == P[wezel])
        {
            modyfikator[wezel] = modyfikator[wezel] + o_ile_zmienic;
            S[wezel] += (q - p + 1) * o_ile_zmienic;
            return;
        }
        zmien(p, min(P[2 * wezel], q), o_ile_zmienic, 2 * wezel);
        zmien(max(L[2 * wezel + 1], p), q, o_ile_zmienic, 2 * wezel + 1);

        S[wezel] = S[2 * wezel] + S[2 * wezel + 1] + modyfikator[wezel] * (P[wezel] - L[wezel] + 1);
    }
    int suma(int p, int q, int wezel = 1)
    {
        if (p > q)
            return 0;
        if (p == L[wezel] && q == P[wezel])
            return S[wezel];

        int X = modyfikator[wezel] * (q - p + 1);

        return suma(p, min(P[2 * wezel], q), 2 * wezel) + suma(max(L[2 * wezel + 1], p), q, 2 * wezel + 1) + X;
    }

    void wypisz()
    {
        for (int i = 1; i < rozmiar * 2; i++)
            cout << i << ": " << modyfikator[i] << " " << S[i] << endl;
    }
};

main()
{
    _upgrade;

    int n;
    cin >> n;
    vector<int> wartosci(n + 1, 1e18 + 1e7);
    vector<int> K(n + 1, 0);

    REP(i, n)
    cin >> wartosci[i];

    REP(i, n - 1)
    cin >> K[i];

    drzewo_przedzialowe D(n + 3);

    REP(i, n + 1)
    D.zmien(i, i, wartosci[i]);
    // D.wypisz();
    // return 1;
    set<int> S;

    REP(i, n + 1)
    S.insert(i);

    int q;
    cin >> q;
    REP(i, q)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 's')
        {

            cout << D.suma(a - 1, b - 1) << endl;
        }
        else
        {
            a--;
            S.insert(a);
            int obecny = a;
            int mod = b;
            while (mod > 0)
            {
                int x = *S.upper_bound(obecny);
                D.zmien(obecny, x - 1, mod);
                int q = D.suma(x - 1, x - 1) + K[x - 1];
                int r = D.suma(x, x);
                mod = q - r;
                obecny = x;
                S.erase(obecny);
            }
            S.insert(obecny);
        }

        // D.wypisz();
    }
}