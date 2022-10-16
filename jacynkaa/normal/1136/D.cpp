#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#include <chrono>
#pragma GCC optimize("-O3")
using namespace __gnu_pbds;
using namespace std;

#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) // ,cin.tie(0), cout.tie(0)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)

#define int long long
const int stala = 1000000;

main()
{
    _upgrade;
    int n, m;
    cin >> n >> m;
    vector<int> osoby(n);
    unordered_map<int, int> M;
    M.reserve(m + 10);
    REP(i, n)
    cin >> osoby[i];
    int kob = osoby[n - 1];

    REP(i, m)
    {
        int a, b;
        cin >> a >> b;
        M[a * stala + b] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int poz = i;
        bool czy_dalej = true;
        while (poz < n - 1 && czy_dalej)
        {
            if (M[osoby[poz] * stala + osoby[poz + 1]] == 1)
            {
                swap(osoby[poz], osoby[poz + 1]);
                poz++;
                continue;
            }
            czy_dalej = false;
        }
    }
    REP(i, n)
    if (osoby[i] == kob)
    {
        cout << n - 1 - i << endl;
    }
}