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
int32_t main()
{
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--)
   {
      int n;
      cin >> n;
      vector<int> pos(n);
      vector<int> perm(n);
      //set<int> S;

      rep(i, n)
      {
         int a;
         cin >> a;
         --a;
         perm[i] = a;
         pos[a] = i;
         //S.insert(i);
      }
      int last = n;
      bool ok = true;
      int j = 0;
      while (ok && j < n)
      {
         int x = pos[j];
         for (int k = pos[j]; k < last; k++)
            if (perm[k] != j++)
            {
               ok = false;
               break;
            }
         last = x;
      }
      cout << (ok ? "Yes" : "No") << endl;
   }
}