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
   int n, m;
   cin >> n >> m;
   vector<int> X(m);
   vector<int> res(m);

   rep(i, m) cin >> X[i];

   int A = accumulate(all(X), 0ll);

   if (A < n)
   {
      cerr << "za malo: " << A << endl;
      cout << -1 << endl;
      exit(0);
   }

   rep(i, m) res[i] = i + 1;
   rep(i, m) if (res[i] + X[i] > n + 1)
   {
      cerr << "za duzo: " << i << endl;
      cout << -1 << endl;
      exit(0);
   }
   vector<int> maksymalny(m, 1);
   for (int i = 1; i < m; i++)
      maksymalny[i] = min(n - X[i] + 1, maksymalny[i - 1] + X[i - 1]);
   rep(i, m)
       what(maksymalny[i]);
   for (int i = m - 2; i > 0; i--)
      maksymalny[i] = min(maksymalny[i], maksymalny[i + 1] - 1);
   rep(i, m) cout << maksymalny[i] << " ";
   cout << endl;
}