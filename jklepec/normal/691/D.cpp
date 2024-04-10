#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

const int MAXN = 1e6 + 5;

int nxt[MAXN];
int group[MAXN];

vector<int> avb[MAXN];

int f(int x) {
   if(group[x] == x) return x;
   return group[x] = f(group[x]);
}
void spoji(int x, int y) {
   x = f(x);
   y = f(y);
   if(x != y) group[x] = y;
}

int pos[MAXN], sol[MAXN];

int main() {
   int n, m; scanf("%d%d", &n, &m);

   rep(i, MAXN) group[i] = i;

   rep(i, n) {
      int x; scanf("%d", &x);
      pos[x] = i;
   }

   rep(i, m) {
      int x, y; scanf("%d%d", &x, &y);
      spoji(--x, --y);
   }

   rep(i, n) {
      avb[f(i)].push_back(i);
   }

   for(int i = n; i; --i) {
      int grp = f(pos[i]);
      sol[avb[grp][nxt[grp] ++]] = i;
   }

   rep(i, n) printf("%d ", sol[i]);
}