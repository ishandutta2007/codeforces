#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int n, p, a[N], L, R, pre[N], t[N];
inline int MOD(int x) { return (x % p + p) % p; }
int main() {
   scanf("%d%d", &n, &p);
   for(int i = 1; i <= n; i ++) scanf("%d", a + i);
   R = *max_element(a + 1, a + n + 1);
   L = max(R - n + 1, *min_element(a + 1, a + n + 1));
   for(int i = 1; i <= n; i ++) pre[max(1, a[i] - L + 1)] ++;
   for(int i = 1; i <= R - L + 1 + n; i ++) pre[i] += pre[i - 1];
   for(int i = L; i < L + n; i ++) t[MOD(i - pre[i - L + 1])] ++;
   vector<int> ans;
   for(int x = L; x <= R; x ++) {
      if(!t[MOD(x)]) {
         ans.push_back(x);
      }
      t[MOD(x - pre[x - L + 1])] --;
      t[MOD((x + n) - pre[(x + n) - L + 1])] ++;
   }
   printf("%lu\n", ans.size());
   for(int v : ans) printf("%d ", v);
   putchar('\n');
   return 0;
}