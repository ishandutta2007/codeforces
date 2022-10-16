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

vector<int> dzieci[1000000];
int operacje[1000000];
int val[1000000];
int n, k;

void dfs(int x)
{
    for (auto y : dzieci[x])
        dfs(y);
    if (dzieci[x].size() == 0)
    {
        val[x] = 1;
        return;
    }

    if (operacje[x] == 0)
        for (auto y : dzieci[x])
            val[x] += val[y];
    else
    {
        val[x] = 12345678;
        for (auto y : dzieci[x])
            val[x] = min(val[x], val[y]);
    }
}

void wczytywanie()
{
    cin >> n;
    REP(i, n)
    cin >> operacje[i + 1];
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        dzieci[a].push_back(i);
    }
    REP(i, n)
    if (dzieci[i + 1].size() == 0)
        k++;
    dfs(1);
}

main()
{
    _upgrade;
    wczytywanie();
    //REP(i, n)
    //cerr << val[i + 1] << endl;
    cout << k - val[1] + 1 << endl;
}