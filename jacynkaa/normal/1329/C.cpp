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
#define int long long
#define cerr \
   if (0)    \
   cerr
const int MAXN = 5e6;

struct content
{
   int res, mini, maks;
};

int tab[MAXN];
int res[MAXN];
int g, h;

void clear()
{
   rep(i, 4 << h) tab[i] = 0;
   rep(i, 4 << h) res[i] = -1;
   for (int i = 1; i < (1 << g); i++)
      res[i] = 0;
}
void add(int x, int i)
{
   while ((i > ((1 << g) - 1) || res[i] != 0) && i > 0)
      i /= 2;
   what(i);
   what(res[2 * i]);
   what(res[2 * i + 1]);
   if (res[2 * i] * res[2 * i + 1] != 0)
   {
      cerr << i << endl;
      res[i] = x;
   }
}

void del(int x)
{
   tab[x] = 0;
   if (tab[2 * x] == 0 && tab[2 * x + 1] == 0)
      return;
   int a = 2 * x + ((tab[2 * x] > tab[2 * x + 1]) ? 0 : 1);
   swap(tab[a], tab[x]);
   del(a);
}

void getres(int x)
{
   if (x >= (1 << g))
      return;
   while (res[x] != tab[x])
   {
      what(res[x]);
      what(tab[x]);
      cout << x << " ";
      del(x);
   }
   getres(2 * x);
   getres(2 * x + 1);
}

int32_t main()
{
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--)
   {
      cin >> h >> g;
      what(g);
      what(h);
      clear();
      vector<pii> tree;
      for (int i = 1; i < (1 << h); i++)
      {
         int a;
         cin >> a;
         tab[i] = a;
         tree.emplace_back(a, i);
      }
      sort(all(tree));
      for (auto p : tree)
         add(p.st, p.nd);
      int x = 0;

      for (int i = 1; i < (1 << g); i++)
      {
         x += res[i];
         cerr << i << " " << res[i] << endl;
      }

      cout << x << endl;
      getres(1);

      cout << endl;
   }
}