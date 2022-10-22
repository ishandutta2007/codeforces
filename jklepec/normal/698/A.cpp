#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

const int MAXN = 105, mod = 1e9 + 7, B = 1337;

typedef long long ll;
typedef pair<int, int> point;

int add(int x, int y) {
   x += y;
   if(x >= mod) return x - mod;
   return x;
}
int sub(int x, int y) {
   x -= y;
   if(x < 0) return x + mod;
   return x;
}
int mul(int x, int y) {
   return (ll) x * y % mod;
}

int dp[3][MAXN];

int a[MAXN], b[MAXN];

int main() {
   int n; cin >> n;

   rep(i, n) {
      int x; cin >> x; x ++;
      if(x % 2 == 0) b[i] = 1;
      if(x == 3 || x == 4) a[i] = 1;
   }

   dp[0][0] = 1;
   dp[1][0] = 1 - a[0];
   dp[2][0] = 1 - b[0];

   for(int i = 1; i < n; ++i) {
      dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
      dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
      dp[0][i] = min(dp[1][i - 1], min(dp[0][i - 1], dp[2][i - 1])) + 1;
      if(!a[i]) {
         dp[1][i] ++;
      }
      if(!b[i]) {
         dp[2][i] ++;
      }
   }

   cout << min(min(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]);
}