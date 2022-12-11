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

template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

const int N = 2e5 + 50;
const int V = 5e6 + N;

int n, q, a[N], ans[1049658 + 10];
vector<pii> v[1049658 + 10];
int work(int n) {
   int res = 1;
   for(int i = 2; i * i <= n; i ++) {
      if(n % i == 0) {
         int c = 0;
         while(n % i == 0) n /= i, c ^= 1;
         if(c & 1) res *= i;
      }
   }
   if(n > 1) res *= n;
   return res;
}
int p[V], pc, cnt[V];
bool tag[V];
void sieve(int n) {
   rep(i, 2, n) {
      if(!tag[i]) p[++ pc] = i, cnt[i] = 1;
      for(int j = 1; j <= pc && p[j] * i <= n; j ++) {
         tag[i * p[j]] = 1; cnt[i * p[j]] = cnt[i] + 1;
         if(i % p[j] == 0) break ;
      }
   }
}
int f[V][12], g[20];
int main() {
   scanf("%d%d", &n, &q);
   rep(i, 1, n) scanf("%d", a + i), a[i] = work(a[i]);
   sieve(*max_element(a + 1, a + n + 1));
   rep(i, 1, q) {
      int l, r;
      scanf("%d%d", &l, &r);
      v[r].eb(l, i);
   }
   rep(i, 1, n) {
      for(int d = 1; d * d <= a[i]; d ++) if(a[i] % d == 0) {
         int c = cnt[a[i] / d];
         rep(j, 0, 11 - c) chkmax(g[c + j], f[d][j]);
         c = cnt[d];
         rep(j, 0, 11 - c) chkmax(g[j + c], f[a[i] / d][j]);
      }
      for(auto qs: v[i]) {
         rep(j, 0, 11) if(g[j] >= qs.fs) {
            ans[qs.sc] = j; break ;
         }
      }
      for(int d = 1; d * d <= a[i]; d ++) if(a[i] % d == 0) {
         f[d][cnt[a[i] / d]] = f[a[i] / d][cnt[d]] = i;
      }
   }
   rep(i, 1, q) printf("%d\n", ans[i]);
   return 0;
}