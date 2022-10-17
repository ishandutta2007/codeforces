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
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;

const int MAXN = 1002;

int n, m;
bool visited[MAXN * MAXN];
char tab[MAXN][MAXN];
vector<int> G[MAXN * MAXN * 2];

void pre()
{
   rep(i, MAXN) rep(j, MAXN) tab[i][j] = '.';
   rep(i, MAXN * MAXN) visited[i] = 1;
}

void input()
{
   cin >> n >> m;
   rep(i, n) rep(j, m)
   {
      cin >> tab[i + 1][j + 1];
      // what(tab[i + 1][j + 1]);
   }
}

vector<pii> sasiedzi(pii A)
{
   return {{A.st + 1, A.nd}, {A.st - 1, A.nd}, {A.st, A.nd + 1}, {A.st, A.nd - 1}};
}

int num(pii A)
{
   return A.st + A.nd * MAXN;
}

bool OK()
{

   pii A = {0, 0};
   for (int i = 1; i <= n; i++)
   {
      int cnt = 0;
      for (int j = 1; j <= m; j++)
         cnt += (tab[i][j] == '#' && tab[i][j - 1] == '.');
      if (cnt > 1)
         return false;
      if (cnt == 0)
         A.st++;
   }

   for (int j = 1; j <= m; j++)
   {
      int cnt = 0;
      for (int i = 1; i <= n; i++)
         cnt += (tab[i][j] == '#' && tab[i - 1][j] == '.');
      if (cnt > 1)
         return false;
      if (cnt == 0)
         A.nd++;
   }

   return (A.st + A.nd) ? (A.nd * A.st) : true;
}

void makeG()
{
   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
      {
         //   what(tab[i][j]);
         if (tab[i][j] == '#')
         {
            for (auto P : sasiedzi({i, j}))
               G[num({i, j})].emplace_back(num(P));
            // what(i);
            //  what(j);
            visited[num({i, j})] = 0;
         }
      }
}

void dfs(int x)
{
   visited[x] = 1;
   for (int y : G[x])
      if (!visited[y])
         dfs(y);
}

int32_t main()
{
   _upgrade;
   pre();
   input();
   if (!OK())
   {
      cout << -1 << endl;
      exit(0);
   }
   makeG();
   int ans = 0;
   rep(i, MAXN * MAXN) if (!visited[i])
   {
      dfs(i);
      ans++;
   }
   cout << ans << endl;
}