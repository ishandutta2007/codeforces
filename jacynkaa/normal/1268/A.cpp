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

const int MAXN = 1e6;

int liczba[MAXN];
int odp[MAXN];
int n, k;

bool ok()
{
    rep(i, n)
    {
        if (liczba[i] > odp[i])
            return false;
        if (liczba[i] < odp[i])
            return true;
    }
    return true;
}

void wypisz()
{
    cout << n << endl;
    rep(i, n) cout << odp[i];
    cout << endl;
    exit(0);
}

main()
{
    _upgrade;
    cin >> n >> k;
    string S;
    cin >> S;
    rep(i, n)
        liczba[i] = S[i] - '0';
    rep(i, n)
        odp[i] = liczba[i % k];
    if (ok())
        wypisz();

    int r = 1;
    for (int i = k - 1; i >= 0; i--)
    {
        liczba[i] += r;
        r = (liczba[i] > 9) ? 1 : 0;
        liczba[i] = liczba[i] % 10;
    }
    rep(i, n)
        odp[i] = liczba[i % k];
    wypisz();
}