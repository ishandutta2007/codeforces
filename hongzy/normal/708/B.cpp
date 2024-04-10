#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 5e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int a[2][2], num[N], c, n = -1, m = -1;
char s[N];
int main() {
   for(ll n = 0; n * (n - 1) / 2 <= (ll)1e9; n ++) {
      num[n] = n * (n - 1) / 2; c = n;
   }
   rep(i, 0, 1) rep(j, 0, 1) scanf("%d", &a[i][j]);
   rep(i, 0, c) if(num[i] == a[0][0]) n = i, i = c;
   rep(i, 0, c) if(num[i] == a[1][1]) m = i, i = c;
   if(a[0][1] || a[1][0]) {
      if(n == 0) n ++;
      if(m == 0) m ++;
   }
   if(n == -1 || m == -1 || a[0][1] + a[1][0] != (ll) n * m) {
      puts("Impossible"); return 0;
   }
   if((ll) a[0][0] + a[0][1] + a[1][0] + a[1][1] == 0) {
      puts("0");
      return 0;
   }
   if(m == 0) {
      rep(i, 1, n) s[i] = '0';
      puts(s + 1); return 0;
   }
   if(n == 0) {
      rep(i, 1, m) s[i] = '1';
      puts(s + 1); return 0;
   }
   int k = a[1][0] / m, r = a[1][0] % m;
   int c = n - (r > 0) - k;
   rep(i, 1, c) putchar('0');
   rep(i, 1, m) {
      putchar('1');
      if(i == r) putchar('0');
   }
   rep(i, 1, k) putchar('0');
   putchar('\n');
   return 0;
}