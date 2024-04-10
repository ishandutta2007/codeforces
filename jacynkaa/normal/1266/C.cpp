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
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1)
    {
        cout << 0 << endl;
        exit(0);
    }
    if (c == 1)
    {
        rep(i, r) cout << i + 2 << endl;
        exit(0);
    }
    if (r == 1)
    {
        rep(i, c) cout << i + 2 << " ";
        cout << endl;
        exit(0);
    }
    rep(i, r)
    {
        rep(j, c) cout << (i + 1) * (r + j + 1) << " ";
        cout << endl;
    }
}