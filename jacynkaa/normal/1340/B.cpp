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
#define num bitset<7>

const int MAXN = 10;

string S[MAXN] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
num tab[MAXN];
int res[3000][3000];

int ile(num &B, num &A)
{
   if ((A | B).count() != A.count())
      return 1000000;
   else
      return A.count() - B.count();
}
int32_t main()
{
   _upgrade;
   rep(i, MAXN)
       tab[i] = num(S[i]);

   int n, k;
   cin >> n >> k;

   vector<num> X(n);

   rep(i, n) cin >> X[i];

   reverse(all(X));

   rep(i, n) for (int j = 0; j <= k; j++)
   {
      for (int l = MAXN - 1; l >= -1; l--)
      {
         if (l == -1)
         {
            res[i][j] = -1;
            break;
         }

         int a = ile(X[i], tab[l]);
         if (a <= j)
         {
            if ((i != 0 && res[i - 1][j - a] != -1) || (i == 0 && a == j))
            {
               res[i][j] = l;
               break;
            }
         }
      }
   }
   for (int i = n - 1; i >= 0; i--)
   {
      cout << res[i][k];
      if (res[i][k] == -1)
         break;
      k -= ile(X[i], tab[res[i][k]]);
      //what(k);
   }

   cout << endl;
}