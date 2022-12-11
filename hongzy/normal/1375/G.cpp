#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define debug(x) printf("%s = %d\n", #x, (int) x)
#define pb push_back
using namespace std;
const int N = 2e5 + 10;
int n, c[2];
vector<int> G[N];
void dfs(int u, int fa = 0, int k = 0) {
   c[k] ++;
   for(int v : G[u]) if(v ^ fa) dfs(v, u, k ^ 1);
}
int main() {
   scanf("%d", &n);
   int u, v;
   rep(i, 1, n - 1) {
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
   }
   dfs(1);
   printf("%d\n", -1 + min(c[0], c[1]));
   return 0;
}