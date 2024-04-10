#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl '\n'
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)

main()
{
    _upgrade;
    int n;
    cin >> n;
    string S;
    cin >> S;
    if (((n % 2) != 0) || S[0] == ')' || S[n - 1] == '(')
    {
        cout << ":(" << endl;
        exit(0);
    }
    int ile_zam = 0;
    int ile_otwar = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (S[i] == '(')
            ile_otwar++;
        if (S[i] == ')')
            ile_zam++;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (S[i] == '?')
        {
            if (ile_otwar < (n - 2) / 2)
            {
                S[i] = '(';
                ile_otwar++;
            }
            else
            {
                S[i] = ')';
            }
        }
    }
    int x = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (S[i] == '(')
            x++;
        else
            x--;
        if (x < 0)
        {
            cout << ":(" << endl;
            exit(0);
        }
    }
    if (x != 0)
    {
        cout << ":(" << endl;
        exit(0);
    }

    cout << "(";
    for (int i = 1; i < n - 1; i++)
        cout << S[i];
    cout << ")";
    cout << endl;
}