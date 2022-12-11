#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define debug(x) printf("%s = %d\n", #x, (int) x)
#define pb push_back
#define ped fflush(stdout)
using namespace std;
typedef long long ll;
ll a[3];
int ord[3];
bool cmp(int x, int y) { return a[x] < a[y]; }
void solve() {
   rep(i, 0, 2) ord[i] = i;
   sort(ord, ord + 3, cmp);
   ll y = 2 * a[ord[2]] - a[ord[0]] - a[ord[1]];
   printf("%lld\n", y), ped;
   int t; scanf("%d", &t); -- t;
   if(t == -1) return ;
   if(t == ord[2]) { a[t] += y; return solve(); }
   y = a[ord[2]] - a[ ord[1] == t ? ord[0] : ord[1] ];
   printf("%lld\n", y), ped;
}
int main() {
   scanf("%lld%lld%lld", a, a + 1, a + 2);
   puts("First"), ped; solve();
   return 0;
}