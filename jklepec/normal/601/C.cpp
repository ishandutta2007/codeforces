#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MaxN 105
#define MaxM 1005

#define d(x) double(x)

int sum;
int a[MaxN];
double dp[MaxN * MaxM], dpnew[MaxN * MaxM], ev[MaxN * MaxM];

vector<int> v;

int main() {
   int n, m; scanf("%d%d", &n, &m);
   for(int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      sum += a[i];
   }
   for(int j = 1; j <= m; ++j)
      if(a[0] != j)
         v.push_back(j);
   for(int i = 0; i < m - 1; ++i)
      dp[v[i]] = d(1);
   for(int i = 1; i < n; ++i) {
      double tmp = d(0);
      for(int j = 0; j < sum; ++j) {
         tmp += ev[j];
         dpnew[j] = tmp;
         ev[j + 1] += dp[j];
         ev[j + a[i]] -= dp[j];
         ev[j + a[i] + 1] += dp[j];
         ev[j + m + 1] -= dp[j];
      }
      for(int j = 0; j < sum; ++j) {
         dp[j] = dpnew[j] / (m == 1 ? d(1) : d(m - 1));
      }
      memset(ev, d(0), sizeof ev);
      memset(dpnew, d(0), sizeof dpnew);
   }
   double sol = d(0);
   for(int i = 0; i < sum; ++i)
      sol += dp[i];
   printf("%.10lf\n", sol + d(1));
   return 0;
}