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
const int MAXN = 1e5 + 10;

bool visisted[MAXN];
set<int> znajomi[MAXN];
set<int> nieznajomi[MAXN];
int n, m;
vector<int> N;
int odp = 0;

void genniezn(int x)
{
    rep(i, n) if (x != i && znajomi[x].find(i) == znajomi[x].end()) nieznajomi[x].insert(i);
}

void dfs(int x)
{
    visisted[x] = true;
    genniezn(x);
    while (!nieznajomi[x].empty())
    {
        int y = *nieznajomi[x].begin();
        visisted[y] = true;
        set<int> D;
        for (auto b : znajomi[x])
            if (znajomi[y].find(b) != znajomi[y].end())
                D.insert(b);
            else
                nieznajomi[x].insert(b);
        znajomi[x] = D;
        nieznajomi[x].erase(y);
    }
    odp++;
}

void input()
{
    cin >> n >> m;

    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        znajomi[a].insert(b);
        znajomi[b].insert(a);
    }
}

main()
{
    _upgrade;
    input();
    rep(i, n) if (!visisted[i]) dfs(i);
    cout << odp - 1 << endl;
}