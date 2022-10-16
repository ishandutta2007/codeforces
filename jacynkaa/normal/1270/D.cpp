#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
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

vector<int> V;
vector<int> wartosci;
vector<int> indeksy_ok;
vector<int> indeksy_zle;
int n, k;

pii ask(vector<int> &Z)
{
    cout << "? ";
    for (int z : Z)
        cout << z << " ";
    cout << endl;
    pii A;
    cin >> A.st >> A.nd;
    return A;
}

vector<int> get()
{
    vector<int> Q;
    rep(i, n)
    {
        if (V[i] == -1)
            Q.push_back(i + 1);
        if (Q.size() == k)
            return Q;
    }
    return {};
}

void pre()
{
    while (true)
    {
        auto P = get();
        if (P.size() == 0)
            return;
        else
        {
            auto tmp = ask(P);
            V[tmp.st - 1] = tmp.nd;
        }
    }
}

void debug()
{
    cerr << "OK" << endl;
    for (int a : indeksy_ok)
        cerr << a << " ";
    cerr << endl;
    cerr << "zle" << endl;
    for (int a : indeksy_zle)
        cerr << a << " ";
    cerr << endl;

    cerr << "wartosci" << endl;
    for (int a : V)
        cerr << a << " ";
    cerr << endl;
}

void wypelnij()
{
    rep(i, n) if (V[i] == -1)
        indeksy_zle.push_back(i + 1);
    else indeksy_ok.push_back(i + 1);

    //debug();
}

void odp(int x)
{
    cout << "! " << x << endl;
    exit(0);
}

void sol()
{
    int ile = 0;
    if (V[indeksy_ok[0] - 1] > V[indeksy_ok[1] - 1])
        swap(indeksy_ok[0], indeksy_ok[1]);
    rep(i, indeksy_zle.size())
    {
        auto X = indeksy_zle;
        X[i] = indeksy_ok[0];
        X.push_back(indeksy_ok[1]);
        auto P = ask(X);
        if (P.st == indeksy_ok[1])
        {
            //cerr << "halloo " << P.st << " " << indeksy_ok[0] << " " << indeksy_ok[1] << endl;
            ile++;
        }
    }
    odp(ile + 1);
}

main()
{
    cin >> n >> k;
    V.resize(n, -1);

    if (k == 1)
        odp(1);
    pre();
    wypelnij();
    sol();
}