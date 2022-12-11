#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <chrono>
#include <random>
#include <queue>
#include <cmath>
#include <ctime>
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

const int N = 1e5 + 10;
int a[N], n, g;
int qpow(int a, int b, int mod) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int phi(int n) {
   int ans = n;
   for(int i = 2; i * i <= n; i ++) {
      if(n % i == 0) {
         ans = ans / i * (i - 1);
         while(n % i == 0) n /= i;
      }
   }
   if(n > 1) ans = ans / n * (n - 1);
   return ans;
}
bool work() {
   vector<int> v; int x = n - 1;
   for(int d = 2; d * d <= x; d ++) {
      if(x % d == 0) {
         v.pb((n - 1) / d);
         while(x % d == 0) x /= d;
      }
   }
   if(x > 1) v.pb((n - 1) / x);
   for(g = 2; g < n; g ++) if(qpow(g, n - 1, n) == 1) {
      bool tag = 1;
      for(int y : v) if(qpow(g, y, n) == 1) {
         tag = 0; break ;
      }
      if(tag) return 1;
   }
   return 0;
}
int main() {
   scanf("%d", &n);
   if(n == 1) {
      puts("YES");
      printf("%d\n", 1);
      return 0;
   }
   if(n == 2) {
      puts("YES");
      printf("%d\n", 1);
      printf("%d\n", 2);
      return 0;
   }
   if(n == 4) {
      puts("YES");
      printf("%d\n", 1);
      printf("%d\n", 3);
      printf("%d\n", 2);
      printf("%d\n", 4);
      return 0;
   }
   if(!work()) {
      puts("NO"); return 0;
   }
   // printf("g = %d!\n", g);
   puts("YES");
   int x = 2, y = n - 2;
   a[1] = 1;
   rep(i, 2, n - 1) {
      if(i & 1) {
         a[i] = qpow(g, x, n), x += 2;
      } else {
         a[i] = qpow(g, y, n); y -= 2;
      }
   }
   a[n] = n;
   rep(i, 1, n) printf("%d\n", a[i]);
   // rep(i, 1, n) {
   //    if(i > 1) a[i] = 1ll * a[i - 1] * a[i] % n;
   //    printf("[%d]\n", a[i]);
   // }
   return 0;
}