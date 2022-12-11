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

const ll N = 10000;
ll dp[N + 10][6];
void print(vector<ll> &vec) {
   printf("%lu", vec.size());
   for(auto v: vec) printf(" %lld", v);
   putchar('\n'); fflush(stdout);
}
int main() {
   rep(i, 1, N) dp[i][1] = i;
   rep(i, 2, 5) {
      rep(j, 1, N) {
         ll t = j;
         rep(k, 1, j + 1) {
            if(t > N) {
               t += (j - k + 2) * (dp[N][i - 1] + 1);
               break ;
            }
            t += dp[t][i - 1] + 1;
         }
         dp[j][i] = t - j - 1;
      }
   }
   // printf("check: %lld\n", dp[1][5]);
   vector<ll> pos;
   ll l = 1;
   per(i, 5, 1) {
      pos.clear();
      ll st = min((ll) N, l);
      ll t = l;
      rep(j, 0, min(N, l)) {
         t += dp[min(t, N)][i - 1] + 1;
         if(j != min(N, l)) pos.pb(t - 1);
      }
      print(pos);
      int x; scanf("%d", &x);
      if(x == -1) break ;
      if(x) l = pos[x - 1] + 1;
   }
   return 0;
}