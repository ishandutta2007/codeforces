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
const int INF = 2e9 + 7;
const int mod = 1e9 + 7;

set<int> S;
int main() {
   int x, q, L = -INF, R = INF, c = 0, ans = 1;
   S.insert(L); S.insert(R);
   scanf("%d", &q);
   char op[20];
   while(q --) {
      scanf("%s%d", op, &x);
      if(op[1] == 'D') {
         S.insert(x);
         if(L <= x && x <= R) {
            c ++;
         }
      } else {
         c = 0;
         if(x < L || x > R) {
            puts("0"); return 0;
         }
         if(x != L && x != R) {
            ans = (ans + ans) % mod;
         }
         S.erase(x);
         auto it = S.lower_bound(x);
         R = *it; L = * --it;
      }
   }
   ans = ans * (c + 1ll) % mod;
   printf("%d\n", ans);
   return 0;
}