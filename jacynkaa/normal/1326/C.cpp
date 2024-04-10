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
const int MOD = 998244353;

int32_t main() {
   _upgrade;
   int n, k;
   cin >> n >> k;
   vector<int> P(n);
   rep(i, n) cin >> P[i];
   vector<int> tmp;
   rep(i, n) if (P[i] >= n - k + 1) tmp.push_back(i);
   what(sz(tmp));

   int res2 = 1;
   int res1 = 0;
   rep(j, k) {
      if (j != 0)
         res2 = (res2 * (tmp[j] - tmp[j - 1])) % MOD;
      // what(tmp[j]);
      res1 += P[tmp[j]];
   }
   cout << res1 << " " << res2 << endl;
}