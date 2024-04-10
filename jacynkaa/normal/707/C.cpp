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

#define int long long

main()
{
    _upgrade;
    int a;
    cin >> a;
    if (a == 1 || a == 2)
    {
        cout << -1 << endl;
        exit(0);
    }
    int x = 1;
    int y = 1;
    while (((a % 2) == 0) && (a != 4))
    {
        a = a / 2;
        x = x * 2;
        y = y * 2;
    }
    if (a == 4)
    {
        x = x * 3;
        y = y * 5;
    }
    else
    {
        a = a * a;
        x = x * (a / 2);
        y = y * (a / 2 + 1);
    }
    cout << x << " " << y << endl;
}