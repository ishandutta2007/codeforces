#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <bitset>
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
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
 
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
 
const int N = 400 + 10;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
int a, b, n, Map[N];
char s[N];
int main() {
   Map['U'] = 0; Map['D'] = 1; Map['L'] = 2; Map['R'] = 3;
   int cx = 0, cy = 0, x = 0, y = 0;
   scanf("%d%d%s", &a, &b, s + 1); n = strlen(s + 1);
   rep(i, 1, n) x += dx[Map[s[i]]], y += dy[Map[s[i]]];
   bool tag = 0;
   rep(i, 0, n) {
      if(i) cx += dx[Map[s[i]]], cy += dy[Map[s[i]]];
      bool cur = 1;
      //(cx + kx, cy + ky) = (a, b)
      if(x == 0 && cx != a) cur = 0;
      else if(y == 0 && cy != b) cur = 0;
      else {
         if(x && ((a - cx) % x || (a - cx) / x < 0)) cur = 0;
         else if(y && ((b - cy) % y || (b - cy) / y < 0)) cur = 0;
         else {
            if(x && y && (a - cx) / x != (b - cy) / y) cur = 0;
         }
      }
      if(cur) {
         tag = 1; break ;
      }
   }
   puts(tag ? "Yes" : "No");
   return 0;
}