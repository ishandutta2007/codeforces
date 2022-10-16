#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#include <chrono>
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
//mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
//struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
//gp_hash_table<long long, int, custom_hash> safe_hash_table; -szybsza hashmapa

const int MAXN = 3e5;

struct drzewo_przedzialowe //drzewo przedzial-przedzial dodaj-dodaj
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

    void zmien(int p, int q, int o_ile_zmienic, int wezel = 1) //dodaje o_ile_zmienic na przedziale [p,q]
    {
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
    int suma(int p, int q, int wezel = 1) //zwraca sume na przedziale [p,q]
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

int liczba_inwersji[MAXN];
int pozycja[MAXN];
int tab[MAXN];
int pierwsze[MAXN];
int n;

void pre()
{
    cin >> n;
    for (int i = 1; i < MAXN; i++)
        pierwsze[i] = pierwsze[i - 1] + i;
    rep(i, n)
    {
        cin >> tab[i];
        tab[i]--;
        pozycja[tab[i]] = i;
    }
    drzewo_przedzialowe I(MAXN);

    for (int i = n - 1; i >= 0; i--)
    {
        liczba_inwersji[tab[i]] = I.suma(0, tab[i]);
        I.zmien(tab[i], tab[i], 1);
    }
}

void solve()
{
    int odp = 0;
    drzewo_przedzialowe D(MAXN);
    indexed_set S;
    rep(i, n)
    {
        odp += liczba_inwersji[i];

        S.insert(pozycja[i]);
        D.zmien(pozycja[i], pozycja[i], pozycja[i]);
        int x = *S.find_by_order(S.size() / 2);
        int ile_mniejszych = (S.size() / 2);
        int ile_wiekszych = S.size() - (S.size() / 2 + 1);

        int O = odp + ile_wiekszych * (-x) + ile_mniejszych * x - D.suma(0, x - 1) + D.suma(x + 1, n + 2) - pierwsze[ile_mniejszych] - pierwsze[ile_wiekszych];
        cout << O << " ";
    }
    cout << endl;
}

main()
{
    pre();
    solve();
}