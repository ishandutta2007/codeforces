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
    int n, t;
    cin >> n >> t;
    vector<pii> X;
    REP(i, n)
    {
        int s, d;
        cin >> s >> d;
        while (s < t)
            s = s + d;
        X.push_back(mp(-s, i));
    }
    cout << max_element(X.begin(), X.end())->nd + 1 << endl;
}