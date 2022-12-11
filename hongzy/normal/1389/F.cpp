#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct Node {
   int op, l, r;
} a[N];
multiset<int> s[2];
int n, ans;
int main() {
   scanf("%d", &n); ans = n;
   for(int i = 1; i <= n; i ++) {
      scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].op);
      a[i].op --;
   }
   sort(a + 1, a + n + 1, [&](Node x, Node y) { return x.r < y.r || (x.r == y.r && x.l < y.l); });
   for(int i = 1; i <= n; i ++) {
      set<int> :: iterator it = s[a[i].op ^ 1].lower_bound(a[i].l);
      if(it == s[a[i].op ^ 1].end()) {
         s[a[i].op].insert(a[i].r);
      } else {
         ans --;
         s[a[i].op ^ 1].erase(it);
      }
   }
   printf("%d\n", ans);
   return 0;
}