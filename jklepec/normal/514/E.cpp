#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

const int mod = 1e9 + 7, B = 105;
typedef long long ll;

int add(int x, int y) {
   x += y;
   if(x >= mod) x -= mod;
   return x;
}
int sub(int x, int y) {
   x -= y;
   if(x < 0) x += mod;
   return x;
}
int mul(int x, int y) {
   return (ll)x * y % mod;
}

int dp[B], ways[B], dp2[B];
int mat[B][B];
int nmt[B][B];
int samp[B][B];

void mnm() {
   rep(i, B) rep(j, B)  samp[i][j] = 0;
   rep(i, B) rep(j, B) rep(z, B) {
      samp[i][j] = add(samp[i][j], mul(mat[i][z], mat[z][j]));
   }
   memcpy(mat, samp, sizeof samp);
}
void mnn() {
   rep(i, B) rep(j, B) samp[i][j] = 0;
   rep(i, B) rep(j, B) rep(z, B) {
      samp[i][j] = add(samp[i][j], mul(nmt[i][z], mat[z][j]));
   }
   memcpy(nmt, samp, sizeof samp);
}

void mnozi(int exp) {
   memcpy(nmt, mat, sizeof mat);
   exp --;
   while(exp) {
      if(exp & 1)
         mnn();
      mnm();
      exp /= 2;
   }
}

int main() {
   dp[0] = dp2[0] = 1;
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n, x; cin >> n >> x;

   rep(i, n) {
      int y; cin >> y;
      ways[y] ++;
   }

   for(int i = 1; i <= 105; ++i) {
      for(int j = 1; j <= 105; ++j) {
         if(i - j < 0) continue;
         dp[i] = add(dp[i], mul(dp[i - j], ways[j]));
         dp2[i] = add(dp[i], dp2[i - 1]);
      }
   }

   if(x <= 100) {
      cout << dp2[x] << endl;
      return 0;
   }

   for(int i = 1; i <= 101; ++i) {
      for(int j = 1; j <= 100; ++j) {
         if(ways[j] == 0) continue;
         if(i - j > 0) {
            rep(z, 101) {
               mat[i - 1][z] = add(mat[i - 1][z], mul(mat[i - j - 1][z], ways[j]));
            }
         }else {
            mat[i - 1][i - j + 100] = add(mat[i - 1][i - j + 100], ways[j]);
         }
         if(i - j - 1 > 0) {
            rep(z, 101) {
               mat[i - 1][z] = add(mat[i - 1][z], mul(mat[i - j - 2][z], sub(0, ways[j])));
            }
         }else {
            mat[i - 1][i - j + 99] = sub(mat[i - 1][i - j + 99], ways[j]);
         }
      }
      if(i == 1)
         mat[i - 1][100] = add(mat[i - 1][100], 1);
      else
         rep(j, 101)
            mat[i - 1][j] = add(mat[i - 1][j], mat[i - 2][j]);
   }

   mnozi(x / 101);
   int sol = 0;

   rep(i, 101) {
      sol = add(sol, mul(dp2[i], nmt[x % 101][i]));
   }

   cout << sol;
}