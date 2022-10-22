#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

const int MAXN = 3e4 + 5, MAXK = 205;

int a[MAXN];
int memo[MAXN][MAXK][4][2];

const int inf = 1e9 + 5;

int n, k;

int f(int i, int j, int x, int y) {
   if(j > i + 1) return -inf;
   if(j < 0) return -inf;
   if(i == -1) return (j == 0 && y == 0) ? 0 : -inf;
   if(memo[i][j][x][y] != -1) return memo[i][j][x][y];

   int add = 0;
   if(y == 1) {
      if(x == 0) {
         add -= 2 * a[i];
      }
      if(x == 3) {
         add += 2 * a[i];
      }
      if(j == k) {
         if(x == 1 || x == 3)
            add -= a[i];
         if(x == 0 || x == 2)
            add += a[i];
      }
      if(j == 1) {
         if(x == 1 || x == 0)
            add += a[i];
         if(x == 3 || x == 2)
            add -= a[i];
      }
   }

   int ret = f(i - 1, j, x, y);

   if(y == 0) {
      ret = max(ret, f(i - 1, j, x, 1));
   }

   if(x == 0 || x == 1) {
      if(y == 1) {
         ret = max(ret, f(i - 1, j - 1, 1, 1));
         ret = max(ret, f(i - 1, j - 1, 3, 1));
         ret = max(ret, f(i - 1, j - 1, 1, 0));
         ret = max(ret, f(i - 1, j - 1, 3, 0));
      }
   }
   if(x == 2 || x == 3) {
      if(y == 1) {
         ret = max(ret, f(i - 1, j - 1, 0, 1));
         ret = max(ret, f(i - 1, j - 1, 2, 1));
         ret = max(ret, f(i - 1, j - 1, 0, 0));
         ret = max(ret, f(i - 1, j - 1, 2, 0));
      }
   }

   return memo[i][j][x][y] = ret + add;
}

int main() {

   cin >> n >> k;
   rep(i, n) cin >> a[i];

   rep(i, MAXN) rep(j, MAXK) rep(x, 4) rep(y, 2) memo[i][j][x][y] = -1;

   int sol = -inf;
   rep(i, 4) sol = max(sol, f(n, k, i, 0));
   cout << sol;
}