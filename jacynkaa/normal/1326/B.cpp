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
#define int long long
int32_t main() {
   _upgrade;

   int n;
   cin >> n;
   vector<int> T(n);
   rep(i, n) cin >> T[i];
   vector<int> res(n);
   int mak = 0;
   rep(i, n) {
      res[i] = T[i] + mak;
      mak = max(mak, res[i]);
      cout << res[i] << " ";
   }
   cout << endl;
}