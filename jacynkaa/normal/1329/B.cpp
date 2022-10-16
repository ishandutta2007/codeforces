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
const int MAXN = 1e6;

int32_t main()
{
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--)
   {
      int d, m;
      cin >> d >> m;
      int cnt = 1;
      int x = 1;
      while (x <= d)
      {
         cnt *= min(x, d - x + 1) + 1;
         cnt %= m;
         x *= 2;
      }
      cnt = (cnt + m - 1) % m;
      cout << cnt << endl;
   }
}