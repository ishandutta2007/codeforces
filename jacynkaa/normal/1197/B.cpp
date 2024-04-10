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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()

main()
{

    _upgrade;
    int n;
    cin >> n;
    vector<int> X(n);
    rep(i, n)
    {
        cin >> X[i];
    }

    int j = 0;
    while (X[j + 1] > X[j] && j < n - 1)
        j++;
    while (X[j + 1] < X[j] && j < n - 1)
        j++;
    if (j == n - 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}