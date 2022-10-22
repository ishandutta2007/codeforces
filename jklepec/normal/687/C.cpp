#include <iostream>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

const int MAXN = 505;
bool dp[MAXN][MAXN];

int main() {
   dp[0][0] = true;
   int n, k; cin >> n >> k;

   rep(i, n) {
      int x; cin >> x;
      for(int i = MAXN - 1; i + 1; --i) for(int j = MAXN - 1; j + 1; --j) {
         if(i - x >= 0 && dp[i - x][j]) dp[i][j] = true;
         if(j - x >= 0 && dp[i][j - x]) dp[i][j] = true;
      }
   }

   int uk = 0;
   rep(i, k + 1) {
      if(dp[i][k - i] || dp[k - i][i]) uk ++;
   }

   cout << uk << endl;
   rep(i, k + 1) {
      if(dp[i][k - i] || dp[k - i][i]) cout << i << " ";
   }
}