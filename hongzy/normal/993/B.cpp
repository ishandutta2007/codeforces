#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;
 
const int N = 40 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, m;
pii a[N], b[N];
int main() {
   scanf("%d%d", &n, &m);
   rep(i, 1, n) {
      scanf("%d%d", &a[i].fs, &a[i].sc);
      if(a[i].fs > a[i].sc) swap(a[i].fs, a[i].sc);
   }
   rep(i, 1, m) {
      scanf("%d%d", &b[i].fs, &b[i].sc);
      if(b[i].fs > b[i].sc) swap(b[i].fs, b[i].sc);
   }
   bool fail = 0;
   int num = -1;
   rep(i, 1, n) {
      set<int> S;
      rep(j, 1, m) {
         if(a[i] == b[j]) continue ;
         if(a[i].fs == b[j].fs || a[i].fs == b[j].sc) {
            S.insert(a[i].fs);
         } else if(a[i].sc == b[j].fs || a[i].sc == b[j].sc) {
            S.insert(a[i].sc);
         }
      }
      if(S.size() >= 2) {
         fail = 1; break ;
      }
      if(!S.size()) continue ;
      if(num == -1) num = *S.begin();
      else if(num != *S.begin()) num = 0;
   }
   if(!fail) {
      rep(j, 1, m) {
         set<int> S;
         rep(i, 1, n) {
            if(a[i] == b[j]) continue ;
            if(a[i].fs == b[j].fs || a[i].sc == b[j].fs) {
               S.insert(b[j].fs);
            } else if(a[i].fs == b[j].sc || a[i].sc == b[j].sc) {
               S.insert(b[j].sc);
            }
         }
         if(S.size() >= 2) {
            fail = 1; break ;
         }
         if(!S.size()) continue ;
         if(num == -1) num = *S.begin();
         else if(num != *S.begin()) num = 0;
      }
   }
   printf("%d\n", fail ? -1 : num);
   return 0;
}