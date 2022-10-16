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

const int MAXN = (int)3e3;

vector<int> G[MAXN];
vector<int> kolejnosc[MAXN];
int C[MAXN];
int odp[MAXN];
int n;
int root;

void concat(vector<int> &A, vector<int> B)
{
    for (auto b : B)
        A.pb(b);
}

void koniec()
{
    cout << "NO" << endl;
    exit(0);
}

void dfs(int x)
{
    for (int y : G[x])
    {
        dfs(y);
        concat(kolejnosc[x], kolejnosc[y]);
    }
    if (kolejnosc[x].size() < C[x])
        koniec();
    kolejnosc[x].insert(kolejnosc[x].begin() + C[x], x);
}

void input()
{
    cin >> n;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (a > 0)
        {
            a--;
            G[a].push_back(i);
        }
        else
            root = i;

        cin >> C[i];
    }
}

main()
{
    _upgrade;
    input();
    dfs(root);
    cout << "YES" << endl;
    rep(i, n)
    {
        odp[kolejnosc[root][i]] = i + 2;
    }
    rep(i, n)
            cout
        << odp[i] << " ";
    cout << endl;
}