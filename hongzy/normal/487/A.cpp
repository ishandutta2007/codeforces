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

const int N = 4e5 + 10;
int HP_Y, ATK_Y, DEF_Y;
int HP_M, ATK_M, DEF_M;
int h, a, d;
ll ans = 1e9;
ll DF(ll x, ll y) {
   return (x + y - 1) / y;
}
int main() {
   scanf("%d%d%d", &HP_Y, &ATK_Y, &DEF_Y);
   scanf("%d%d%d", &HP_M, &ATK_M, &DEF_M);
   scanf("%d%d%d", &h, &a, &d);
   rep(j, 0, 300) rep(k, 0, 300) {
      int ATK = ATK_Y + j, DEF = DEF_Y + k;
      if(ATK - DEF_M <= 0) continue ;
      ll mHP = ATK_M - DEF <= 0 ? HP_Y : (ATK_M - DEF) * DF(HP_M, ATK - DEF_M) + 1;
      ans = min(ans, max(0ll, mHP - HP_Y) * h + j * a + k * d);
   }
   printf("%lld\n", ans);
   return 0;
}