#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
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
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
// mt19937_64 
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
 
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }
 
const int N = 5000 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline void ADD(int &x, const int &y) { (x += y) >= mod ? x -= mod : 0; }
inline void DEC(int &x, const int &y) { (x -= y) < 0 ? x += mod : 0; }
struct node {
   int v, c;
   node operator + (node b) const {
      if(v == b.v) return node{v, add(c, b.c)};
      return v < b.v ? b : *this;
   }
   node operator * (node b) const {
      return node{v + b.v, (int)((ll)c * b.c % mod)};
   }
} ans;
int n, m, s[N], f[N], h[N], x[N], y[N];
vector<int> p[N], v[N];
int main() {
   scanf("%d%d", &n, &m);
   rep(i, 1, n) scanf("%d", s + i), p[s[i]].pb(i);
   rep(i, 1, m) {
      scanf("%d%d", f + i, h + i);
      int sz = p[f[i]].size();
      if(h[i] > sz) {
         i --; m --; continue ;
      }
      x[i] = p[f[i]][h[i] - 1];
      y[i] = p[f[i]][sz - h[i]];
      v[f[i]].pb(i);
   }
   if(!m) { puts("0 1"); return 0; }
   ans = node{0, 1};
   rep(i, 1, n) if(v[i].size()) ans.v ++, ans.c = ans.c * (ll)v[i].size() % mod;
   // printf("%d & %d!\n", ans.v, ans.c);
   rep(i, 1, n) {
      node cur = {0, 1};
      rep(j, 1, n) {
         if(j == s[i]) {
            int z1 = 0, z2 = 0;
            int ans2 = 0;
            for(int id : v[j]) {
               if(x[id] == i) {
                  ADD(ans2, z2);
                  z1 ++;
               }
               if(y[id] > i) {
                  z2 ++;
                  ADD(ans2, z1);
                  if(x[id] == i) DEC(ans2, 1);
               }
            }
            if(ans2) {
               cur = cur * node{2, ans2};
            } else if(z1) {
               cur = cur * node{1, z1};
            } else {
               cur.v = cur.c = 0; break ;
            }
         } else {
            // puts("?");
            int z1 = 0, z2 = 0;
            int ans2 = 0;
            for(int id : v[j]) {
               if(x[id] <= i) {
                  ADD(ans2, z2);
                  z1 ++;
               }
               if(y[id] > i) {
                  z2 ++;
                  ADD(ans2, z1);
                  if(x[id] <= i) DEC(ans2, 1);
               }
            }
            if(ans2) {
               cur = cur * node{2, ans2};
            } else if(z1 || z2) {
               cur = cur * node{1, add(z1, z2)};
            }
         }
      }
      // printf("%d : cur = %d, %d\n", i, cur.v, cur.c);
      ans = ans + cur;
   }
   printf("%d %d\n", ans.v, ans.c);
   return 0;
}