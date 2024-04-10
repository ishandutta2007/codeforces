#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
//#pragma GCC optimize (-O3)
//#define endl tutaj n
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
    string S;
    cin >> S;
    int x = S.size();
    int y = 0;
    for (char c : S)
        if (c == 'a')
            y++;
    int d = x - y;

    if (d % 2 == 1)
    {
        cout << ":(" << endl;
        exit(0);
    }
    int dlugosc_bez_a = d / 2;
    string D = "";
    string E = "";

    for (int i = 0; i < S.size(); i++)
    {
        char c = S[i];

        if (i < S.size() - dlugosc_bez_a)
        {
            if (c != 'a')
            {
                D.push_back(c);
            }
        }
        else
        {
            E.push_back(c);
            if (c == 'a')
            {
                cout << ":(" << endl;
                exit(0);
            }
        }
    }

    if (D != E)
    {
        cout << ":(" << endl;
        exit(0);
    }

    for (int i = 0; i < S.size(); i++)
    {

        if (i < S.size() - dlugosc_bez_a)
            cout << S[i];
    }
    cout << endl;
}