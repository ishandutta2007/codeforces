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
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> N(n);
    vector<int> M(m);
    vector<vector<int>> plansza(n, vector<int>(m));
    REP(i, m)
    cin >> M[i];
    REP(i, n)
    cin >> N[i];
    REP(i, n)
    REP(j, m)
    {
        int a;
        cin >> a;
        plansza[i][j] = (a == 0) ? 0 : min(M[j], N[i]);
    }
    REP(i, n)
    {
        REP(j, m)
        {

            cout << plansza[i][j] << " ";
        }
        cout << endl;
    }
}