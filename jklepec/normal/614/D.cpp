#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

typedef pair<long long, int> point;

typedef long long llint;

llint n, A, cf, cm, m;

llint dp[MAXN];
llint dp_min[MAXN];
llint val[MAXN];

point a[MAXN];

llint sol;
llint print[MAXN];

llint xx, yy;

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> A >> cf >> cm >> m;
   xx = n;
   yy = -1;
   a[n].first = A;
   a[n].second = n;
   for(llint i = 0; i < n; ++i) {
      llint x; cin >> x;
      a[i].first = x;
      a[i].second = i;
      print[i] = x;
   }
   sort(a, a + n);
   for(llint i = n - 1; i >= 0; --i)
      dp[i] = dp[i + 1] + A - a[i].first;
   for(llint i = 1; i < n; ++i)
      dp_min[i] = dp_min[i - 1] + (a[i].first - a[i - 1].first) * i;
   for(llint i = n; i >= 1; --i) {
      llint uzeto = n - i;
      if(dp[i] > m)
         break;
      llint coins = m - dp[i];
      if(coins == 0) {
         if(cf * uzeto + a[0].first * cm > sol) {
            sol = cf * uzeto + a[0].first * cm;
            xx = i;
            yy = -1;
         }
         continue;
      }
      llint tmp = uzeto * cf;
      llint lo = 0, hi = i - 1;
      while(lo < hi) {
         llint mid = (lo + hi + 1) >> 1;
         if(dp_min[mid] > coins)
            hi = mid - 1;
         else
            lo = mid;
      }
      tmp += a[lo].first * cm;
      coins -= dp_min[lo];
      tmp += min(coins / (lo + 1), A - a[lo].first) * cm;
      if(tmp > sol) {
         sol = tmp;
         xx = i;
         yy = lo;
      }
      sol = max(sol, tmp);
   }
   if(m >= dp[0]) {
      cout << n * cf + A * cm << endl;
      for(int i = 0; i < n; ++i)
         cout << A << " ";
      return 0;
   }else {
      llint coins = m;
      for(int i = n - 1; i >= xx; --i) {
         coins -= A - a[i].first;
         print[a[i].second] = A;
      }
      for(int i = 0; i <= yy; ++i) {
         coins -= a[yy].first - a[i].first;
         print[a[i].second] = a[yy].first;
      }
      for(int i = 0; i <= yy; ++i) {
         print[a[i].second] += min(coins / (yy + 1), A - a[yy].first);
      }
   }
   cout << sol << endl;
   for(int i = 0; i < n; ++i)
      cout << print[i] << " ";
   return 0;
}