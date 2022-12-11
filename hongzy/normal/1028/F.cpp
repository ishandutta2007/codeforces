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

const int N = 2e5 + 50;

vector<pii> vec[N];
bool del[N];
map<ll, int> Map;
map<pii, int> ans;
int cnt;
int ID(ll r) {
   static int idx;
   if(Map.count(r)) return Map[r];
   return Map[r] = ++ idx;
}
int gcd(int x, int y) {
   return !y ? x : gcd(y, x % y);
}
pii frac(pii x) {
   int z = gcd(x.fs, x.sc);
   return pii(x.fs / z, x.sc / z);
}
int main() {
   int q; scanf("%d", &q);
   int ty, x, y;
   while(q --) {
      scanf("%d%d%d", &ty, &x, &y);
      ll r = x * x + y * y, id = ID(r);
      if(ty == 1) {
         cnt ++;
         for(auto v : vec[id]) {
            ans[frac({v.fs + x, v.sc + y})] += 2;
         }
         ans[frac({x, y})] ++;
         vec[id].pb(pii(x, y));
      }
      if(ty == 2) {
         cnt --; pii t = frac({x, y});
         for(auto &v : vec[id]) if(v != mp(x, y)) {
            ans[frac({v.fs + x, v.sc + y})] -= 2;
         }
         vector<pii>::iterator it = vec[id].begin();
         while(*it != mp(x, y)) it ++;
         vec[id].erase(it);
         ans[t] --;
      }
      if(ty == 3) {
         printf("%d\n", cnt - ans[frac({x * 2, y * 2})]);
      }
   }
   return 0;
}