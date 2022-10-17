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

int MOD = 998244353;
const int stala = 3e5;
int tab[3][stala];

vector<int> G[stala];
int n;

void dfs(int x)
{
    for (int y : G[x])
        dfs(y);
    if (G[x].size() == 0)
    {
        tab[2][x] = 1;
        return;
    }
    vector<int> sum(G[x].size() + 2, 1);
    vector<int> valid(G[x].size() + 2, 1);

    for (int i = 0; i < G[x].size(); i++)
    {
        sum[i + 1] = (tab[0][G[x][i]] + tab[1][G[x][i]] + 2 * tab[2][G[x][i]]) % MOD;
        valid[i + 1] = tab[0][G[x][i]] + tab[2][G[x][i]];
    }
    vector<int> valid_rev = valid;
    //reverse(valid_rev.begin(), valid_rev.end());

    for (int i = 1; i < valid.size(); i++)
        valid[i] = (valid[i] * valid[i - 1]) % MOD;

    for (int i = sum.size() - 2; i >= 0; i--)
    {
        sum[i] = (sum[i] * sum[i + 1]) % MOD;
        valid_rev[i] = (valid_rev[i] * valid_rev[i + 1]) % MOD;
    }

    tab[0][x] = valid[valid.size() - 1];

    for (int i = 0; i < G[x].size(); i++)
        tab[1][x] = (tab[1][x] + (valid[i]) * ((((tab[1][G[x][i]] + tab[2][G[x][i]])) * valid_rev[i + 2]) % MOD)) % MOD;

    int poprzedni = 0;

    for (int i = 0; i < G[x].size(); i++)
    {
        tab[2][x] = (tab[2][x] + poprzedni * (((tab[1][G[x][i]] + tab[2][G[x][i]]) * sum[i + 2]) % MOD)) % MOD;
        poprzedni = (poprzedni * (tab[0][G[x][i]] + tab[2][G[x][i]])) % MOD;
        poprzedni = (poprzedni + (valid[i] * (tab[1][G[x][i]] + tab[2][G[x][i]]))) % MOD;
    }
}

main()
{
    _upgrade;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        G[a].push_back(i);
    }
    dfs(1);
    //  for (int i = 1; i <= n; i++)
    //       cerr << i << ": " << tab[0][i] << " " << tab[1][i] << " " << tab[2][i] << endl;
    cout << (tab[0][1] + tab[2][1]) % MOD << endl;
}