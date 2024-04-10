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

const int MAXN = (int)(3e5);

vector<int> G[MAXN];
vector<int> Gp[MAXN];

int mini[MAXN];
int maksi[MAXN];
int visited[MAXN];
bool cycle = false;
vector<int> kolejnosc;
int n, m;

void dfs_gen(int x)
{
   visited[x] = 1;
   for (int y : G[x])
   {
      if (visited[y] == 0)
         dfs_gen(y);
      if (visited[y] == 1)

         cycle = true;
   }
   visited[x] = 2;
   kolejnosc.push_back(x);
}

void gen()
{
   rep(i, n) if (visited[i] == 0)
       dfs_gen(i);
}

void input()
{
   cin >> n >> m;
   rep(i, m)
   {
      int a, b;
      cin >> a >> b;
      G[--a].push_back(--b);
      Gp[b].push_back(a);
   }
   rep(i, n)
       mini[i] = maksi[i] = i;
}
void gen_tab()
{
   for (int a : kolejnosc)
   {
      for (int y : Gp[a])
         mini[y] = min(mini[y], mini[a]);
      // what(a);
   }
   reverse(all(kolejnosc));

   for (int a : kolejnosc)
      for (int y : G[a])
         maksi[y] = min(maksi[y], maksi[a]);
}

int32_t main()
{
   _upgrade;
   input();
   gen();
   if (cycle)
   {
      cout << -1 << endl;
      exit(0);
   }
   gen_tab();
   int ile = 0;
   rep(i, n) ile += (maksi[i] == i && mini[i] == i);
   cout << ile << endl;
   rep(i, n) cout << ((maksi[i] == i && mini[i] == i) ? "A" : "E");
   cout << endl;
}