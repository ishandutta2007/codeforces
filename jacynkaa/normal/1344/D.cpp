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
#define ll long long

const int MAXN = (int)1e5;

int tab[MAXN];
int n, k;

ll eval(ll x)
{
   return -3 * x * x - 3 * x - 1;
}

void input()
{
   cin >> n >> k;
   rep(i, n) cin >> tab[i];
}

int ile(int A, int val)
{
   if (val >= A)
      return 0;
   int p = 0;
   int q = A - 1;
   while (p != q)
   {
      int s = (p + q + 1) / 2;
      if (A + eval(s) > val)
         p = s;
      else
         q = s - 1;
   }
   return p + 1;
}

bool ok(int val)
{
   int z = 0;
   rep(i, n) z += ile(tab[i], val);
   return z >= k;
}

int32_t main()
{
   _upgrade;
   input();

   int p = -4e18;
   int q = 3e9;
   while (p != q)
   {
      int s = (p + q + 1) / 2;

      if (ok(s))
         p = s;
      else
         q = s - 1;
   }
   int val = p;

   vector<int> odp(n);
   rep(i, n) odp[i] = ile(tab[i], val);

   int a = accumulate(all(odp), 0ll);

   rep(i, n) if (a > k && ile(tab[i], val) != ile(tab[i], val + 1)) odp[i]--, a--;
   rep(i, n) cout << odp[i] << " ";

   cout << endl;

   // ll res = 0;
   // rep(i, n) res += odp[i] * (tab[i] - odp[i] * odp[i]);
   // cerr << res << endl;
}