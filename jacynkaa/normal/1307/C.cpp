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

main()
{

    _upgrade;
    string S;
    cin >> S;
    unordered_map<string, int> M;
    unordered_map<char, int> poj;
    for (char c : S)
    {
        string Q = "aa";
        Q[1] = c;
        for (auto P : poj)
        {
            Q[0] = P.st;
            M[Q] += P.nd;
        }
        poj[c]++;
    }
    int wynik = 0;
    for (auto P : M)
        wynik = max(wynik, P.nd);
    for (auto P : poj)
        wynik = max(wynik, P.nd);
    cout << wynik << endl;
}