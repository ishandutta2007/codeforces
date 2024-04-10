#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
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
int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {

      int n;
      cin >> n;
      if (n == 1) {
         cout << -1 << endl;
         continue;
      }
      cout << 8;
      rep(i, n - 1) cout << 9;
      cout << endl;
   }
}