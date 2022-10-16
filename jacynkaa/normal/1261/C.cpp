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

vector<vector<int>> tab;
vector<vector<int>> sp;
vector<vector<int>> promien;
int n, m;

int odp()
{
    int M = 1e6;
    rep(i, n + 2)
    {
        int ile = 0;
        rep(j, m + 2)
        {
            if (tab[i][j])
            {
                if (ile > 0)
                    M = min(M, ile);
                ile = 0;
            }
            else
                ile++;
        }
    }
    rep(j, m + 2)
    {
        int ile = 0;
        rep(i, n + 2)
        {
            if (tab[i][j])
            {
                if (ile > 0)
                    M = min(M, ile);
                ile = 0;
            }
            else
                ile++;
        }
    }
    // what(M);
    return M;
}

int get(int i, int j)
{
    if (i >= 0 && i < n + 2 && j >= 0 && j < m + 2)
        return sp[i][j];
    return 0;
}

bool OK(int i, int j, int prom)
{
    prom--;
    return (get(i + prom, j + prom) - get(i + prom, j - prom - 1) - get(i - prom - 1, j + prom) + get(i - prom - 1, j - prom - 1)) == 0;
}

void debug()
{
    rep(i, n + 2)
    {
        rep(j, m + 2) cout << tab[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    rep(i, n + 2)
    {
        rep(j, m + 2) cout << promien[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    rep(i, n + 2)
    {
        rep(j, m + 2) cout << sp[i][j] << " ";
        cout << endl;
    }
}

void pre()
{
    cin >> n >> m;
    tab.resize(n + 2, vector<int>(m + 2, 1));
    promien.resize(n + 2, vector<int>(m + 2, 0));
    rep(i, n)
    {
        string S;
        cin >> S;
        rep(j, m)
            tab[i + 1][j + 1] = (S[j] == 'X') ? 0 : 1;
    }
    sp = tab;
    rep(i, n + 2)
    {
        for (int j = 1; j < m + 2; j++)
            sp[i][j] += sp[i][j - 1];
    }
    rep(j, m + 2)
    {
        for (int i = 1; i < n + 2; i++)
            sp[i][j] += sp[i - 1][j];
    }

    rep(i, n + 2) rep(j, m + 2) if (tab[i][j] == 0)
    {
        promien[i][j] = max(promien[i - 1][j] - 1, 1);
        while (OK(i, j, promien[i][j] + 1))
            promien[i][j]++;
    }
}

main()
{
    _upgrade;
    pre();
    //debug();

    int a = (odp() + 1) / 2;
    cout << a - 1 << endl;
    rep(i, n)
    {
        rep(j, m) cout << ((promien[i + 1][j + 1] >= a) ? 'X' : '.');
        cout << endl;
    }
}