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
    int n;
    cin >> n;
    vector<int> X(n);
    REP(i, n)
    cin >> X[i];
    int mini = *min_element(X.begin(), X.end());
    int maxi = *max_element(X.begin(), X.end());
    for (int i = 0; i < n; i++)
    {
        if (X[i] != mini && X[i] != maxi)
        {
            break;
        }
        if (i == n - 1)
        {
            cout << "YES" << endl;
            exit(0);
        }
    }

    int srodek = (mini + maxi) / 2;
    if (mini % 2 != maxi % 2)
    {
        cout << "NO" << endl;
        exit(0);
    }
    for (int q : X)
    {
        if (q != srodek && q != mini && q != maxi)
        {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
}