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

const int N = 363304 + 50;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}

int n, f, a[N];
ll ans[N];
int main() {
   scanf("%d", &n);
   rep(i, 0, n - 1) scanf("%d", a + i), f |= a[i] > 0;
   if(!f) {
      puts("YES");
      rep(i, 0, n - 1) printf("1%c", " \n"[i == n - 1]);
      return 0;
   }
   int p = -1;
   rep(i, 0, n - 1) if(a[i] < a[(i + 1) % n]) p = (i + 1) % n;
   if(p == -1) { puts("NO"); return 0; }
   puts("YES");
   ll la = ans[p] = a[p];
   rep(i, 1, n - 1) {
      int v = (p - i + n) % n, nxt = (v + n - 1) % n;
      //a[v] + k * la > a[nxt]
      ll k = max(0ll, 1 + (a[nxt] - a[v]) / la);
      la = ans[v] = a[v] + k * la;
   }
   rep(i, 0, n - 1) printf("%lld%c", ans[i], " \n"[i == n - 1]);
   return 0;
}