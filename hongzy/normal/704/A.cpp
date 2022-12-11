#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair

typedef double db;
typedef long long ll;
typedef pair<int, int> pii;

const db pi = 2 * acos(-1);
const int N = 3e5 + 10;
const int mod = 1e9 + 7;

inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
int n, q, s[N], t[N], op[N], ans[N], cnt[N], last[N];
bool tag[N];
int main() {
   scanf("%d%d", &n, &q); int cur = 0;
   rep(i, 1, q) {
      scanf("%d%d", t + i, op + i);
      if(t[i] == 1) {
         cnt[op[i]] ++; cur ++; s[++ s[0]] = i;
      }
      if(t[i] == 2) {
         cur -= cnt[op[i]]; cnt[op[i]] = 0; last[op[i]] = i;
      }
      if(t[i] == 3) {
         per(j, op[i], 1) if(!tag[j]) {
            tag[j] = 1;
            if(last[op[s[j]]] < s[j]) {
               cnt[op[ s[j] ]] --; cur --;
            }
         } else break ;
      }
      ans[i] = cur;
   }
   rep(i, 1, q) printf("%d\n", ans[i]);
   return 0;
}