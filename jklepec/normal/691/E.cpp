#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(ll i = 0; i < n; ++i)

typedef unsigned long long ll;
const ll MAXN = 110, mod = 1e9 + 7;

int add(int x, int y) {
   x += y;
   if(x >= mod) return x - mod;
   return x;
}
int mul(int x, int y) {
   return (ll) x * y % mod;
}

int ret[MAXN][MAXN], mat[MAXN][MAXN], sol[MAXN][MAXN];
int n;

void mulm() {
   rep(i, n) rep(j, n) {
      ret[i][j] = 0;
      rep(k, n) ret[i][j] = add(ret[i][j], mul(mat[i][k], mat[k][j]));
   }
   memcpy(mat, ret, sizeof sol);
}
void muls() {
   rep(i, n) rep(j, n) {
      ret[i][j] = 0;
      rep(k, n) ret[i][j] = add(ret[i][j], mul(sol[i][k], mat[k][j]));
   }
   memcpy(sol, ret, sizeof sol);
}

ll a[MAXN];

void exp(ll k) {
   memcpy(sol, mat, sizeof mat);
   k --;
   while(k) {
      if(k % (ll) 2) muls();
      mulm();
      k /= 2;
   }
}

int main() {
   ll k; cin >> n >> k;
   rep(i, n) {
      cin >> a[i];
   }
   rep(i, n) rep(j, n) {
      ll val = (a[i] ^ a[j]), res = 0;
      while(val) {
         if(val % 2) res ++;
         val /= 2;
      }
      if(res % 3 == 0) mat[i][j] = 1;
   }
   if(k == 1) {
      cout << n;
      return 0;
   }
   exp(k - 1);
   ll out = 0;
   rep(i, n) rep(j, n) {
      out = add(sol[i][j], out);
   }
   cout << (out % mod + mod) % mod;
}