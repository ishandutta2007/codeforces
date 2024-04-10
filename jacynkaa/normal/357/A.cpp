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
    int m, x, y;
    cin >> m;
    vector<int> M(m);
    REP(i, m)
    cin >> M[i];
    int sum = accumulate(M.begin(), M.end(), 0);
    cerr << sum << endl;
    cin >> x >> y;
    int val = 0;

    REP(i, m)
    {
        val += M[i];
        if (val > y)
        {
            cout << 0 << endl;
            exit(0);
        }
        if (val >= x && sum - val >= x && sum - val <= y)
        {
            cout << i + 2 << endl;
            exit(0);
        }
    }
    cout << 0 << endl;
}