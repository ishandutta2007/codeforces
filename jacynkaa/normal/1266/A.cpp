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
main()
{
    _upgrade;
    int n;
    cin >> n;
    rep(i, n)
    {
        string S;
        cin >> S;
        bool zero = false;
        for (auto c : S)
            if (c == '0')
                zero = true;

        int suma = 0;
        for (auto c : S)
            suma += c - '0';
        int ile_parzystych = 0;
        for (auto c : S)
            ile_parzystych += ((c - '0') % 2 == 0) ? 1 : 0;
        cout << ((ile_parzystych > 1 && zero && suma % 3 == 0) ? "red" : "cyan") << endl;
    }
}