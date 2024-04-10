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
#define pii pair<int, int>

typedef double db;
typedef long long ll;
const int N = 2e5 + 10;
const int mod = 1e9 + 9;
int n, cut[N], use[N], ans[N], und[N];
set<int> S;
pii a[N], b[N];
pair<pii, int> t[N];
int ID(int xx, int yy) {
   pii c = pii(xx, yy);
   int y = lower_bound(b + 1, b + n + 1, c) - b;
   return 1 <= y && y <= n && c == b[y] ? t[y].sc : -1;
}
void upd(int u) {
   if(u == -1 || use[u]) return ;
   int x = a[u].fs, y = a[u].sc;
   bool cut = 0; int z = 0;
   if(!cut && ~ (z = ID(x - 1, y + 1)) && und[z] == 1) cut = 1;
   if(!cut && ~ (z = ID(x, y + 1)) && und[z] == 1) cut = 1;
   if(!cut && ~ (z = ID(x + 1, y + 1)) && und[z] == 1) cut = 1;
   if(cut != ::cut[u]) {
      if(cut) S.erase(u), ::cut[u] = 1;
      else S.insert(u), ::cut[u] = 0;
   }
}
void del(int u) {
   int x = a[u].fs, y = a[u].sc, z;
   if(~ (z = ID(x - 1, y + 1))) und[z] --;
   if(~ (z = ID(x, y + 1))) und[z] --;
   if(~ (z = ID(x + 1, y + 1))) und[z] --;
   und[u] = 0;
   upd(ID(x - 2, y)); upd(ID(x - 1, y)); upd(ID(x + 1, y)); upd(ID(x + 2, y));
   if(y == 0) return ;
   upd(ID(x - 1, y - 1)); upd(ID(x, y - 1)); upd(ID(x + 1, y - 1));
}
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%d%d", &a[i].fs, &a[i].sc), t[i] = mp(a[i], i);
   sort(t + 1, t + n + 1);
   rep(i, 1, n) b[i] = t[i].fs;
   rep(i, 1, n) if(a[i].sc) {
      int x = ID(a[i].fs - 1, a[i].sc - 1);
      int y = ID(a[i].fs, a[i].sc - 1);
      int z = ID(a[i].fs + 1, a[i].sc - 1);
      und[i] = (x != -1) + (y != -1) + (z != -1);
      if(und[i] == 1) {
         x = x != -1 ? x : (y != -1 ? y : z);
         cut[x] = 1;
      }
   }
   rep(i, 1, n) if(!cut[i]) S.insert(i);
   rep(i, 1, n) {
      int z = 0;
      if(i & 1) {
         z = *-- S.end();
      } else {
         z = *S.begin();
      }
      use[z] = 1; S.erase(z); del(z); ans[i] = z - 1;
   }
   int z = 1, res = 0;
   per(i, n, 1) {
      // printf("%d!\n", ans[i]);
      (res += 1ll * z * ans[i] % mod) %= mod;
      z = 1ll * z * n % mod;
   }
   printf("%d\n", res);
   return 0;
}