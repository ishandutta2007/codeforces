#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep1(i, n) for(int i = 1; i < n; ++i)
#define _ << " " <<

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const int MAXN = 2e5 + 5, M = 1e9 + 7, p1 = 105023, p2 = 15486277, p3 = 179425033;

int n, m, d;

set<int> s;
vector<point> v;

unordered_map<int, int> Y, f;

int a[MAXN];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   cin >> d >> n >> m;

   rep(i, m) {
      int x, y;
      cin >> x >> y;
      v.push_back(point(y, x));
      Y[x] = y;
      a[i] = x;
   }

   sort(a, a + m);
   sort(v.begin(), v.end());

   rep(i, m) {
      auto it = s.lower_bound(v[i].second);
      if(it != s.end())
         f[v[i].second] = *it;
      else
         f[v[i].second] = -1;
      s.insert(v[i].second);
   }

   ll sol = 0;
   int tmp = n;
   int last = 0;

   rep(i, m) {
      int x = a[i];
      if(x >= d)
         continue;

      tmp -= x - last;
      if(tmp < 0) {
         cout << -1;
         return 0;
      }

      int nxt = f[x];
      if(nxt == -1)
         nxt = d;

      if(nxt - x > tmp) {
         if(nxt - x > n) {
            sol += (ll)(n - tmp) * Y[x];
            tmp = n;
         }
         else {
            sol += (ll)(nxt - x - tmp) * Y[x];
            tmp = nxt - x;
         }
      }

      last = x;

   }

   if(tmp < d - last)
      cout << -1;
   else
      cout << sol;

}