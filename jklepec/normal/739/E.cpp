#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
typedef double lf;
typedef long long ll;

int readint() {
   int ret = 0, d;
   d = getchar();
   while (d < 48 || d > 57)
      d = getchar();
   do {
      ret = ret * 10 + d - 48;
      d = getchar();
   } while (d > 47 && d < 58);
   return ret;
}

const int MAXN = 2e3 + 5;

lf dp[MAXN];
int prijelaz[MAXN];

int n, A, B;
lf a[MAXN], b[MAXN];

lf glob;
int globA, globB;

int dajA(lf x, lf y) {

   FOR(i, 1, n + 1) {
      dp[i] = dp[i - 1];
      prijelaz[i] = 0;
      if(dp[i - 1] + a[i] - y > dp[i]) {
         dp[i] = dp[i - 1] + a[i] - y;
         prijelaz[i] = 1;
      }
      if(dp[i - 1] + b[i] - x > dp[i]) {
         dp[i] = dp[i - 1] + b[i] - x;
         prijelaz[i] = 2;
      }
      if(dp[i - 1] + a[i] + b[i] - a[i] * b[i] - y - x > dp[i]) {
         dp[i] = dp[i - 1] + a[i] + b[i] - a[i] * b[i] - y - x;
         prijelaz[i] = 3;
      }
   }
   int i = n;
   globA = 0;
   globB = 0;
   for(; i; --i) {
      if(prijelaz[i] > 1) globB ++;
      if(prijelaz[i] % 2) globA ++;
   }

   return globA;
}

int dajB(lf x) {
   lf lo = 0, hi = 1;
   REP(i, 25) {
      lf mid = (lo + hi) / 2;
      int izracun = dajA(x, mid);
      if(izracun == A) {
         lo = mid;
         break;
      }
      if(izracun < A)
         hi = mid;
      if(izracun > A)
         lo = mid;
   }
   glob = dp[n] + lo * A;
   return globB;
}

int main() {

   n = readint();
   A = readint();
   B = readint();
   REP(i, n) a[i + 1] = (lf) readint() + (lf) readint() / 1000;
   REP(i, n) b[i + 1] = (lf) readint() + (lf) readint() / 1000;

   lf lo = 0, hi = 1;
   REP(i, 25) {
      lf mid = (lo + hi) / 2;
      int izracun = dajB(mid);
      if(izracun > B)
         lo = mid;
      else if(izracun < B)
         hi = mid;
      else {
         lo = mid;
         break;
      }
   }

   printf("%.6f", glob + lo * B);
}