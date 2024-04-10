#include<bits/stdc++.h>
#define REP(i, a) for(int i = 0; i < a; ++i)
using namespace std;

const int MaxN = 2e5;

typedef pair<int, int> point;

int dummy, m;
int ed[MaxN];

bool flag, bio[MaxN], IN[MaxN];

vector< int > E[MaxN];
deque< int > sol;

void dfs(int node) {
   bio[node] = IN[node] = true;
   if(node <= m)
      sol.push_front(node);
   for(auto x : E[node]) {
      if(IN[x])
         flag = true;
      else if(--ed[x] == 0)
         dfs(x);
   }
   IN[node] = false;
}

int main() {
   int n; scanf("%d%d", &n, &m);
   dummy = m;
   REP(i, n) {
      vector< point > a;
      REP(j, m) {
         int x; scanf("%d", &x);
         a.push_back(point(x, j + 1));
      }
      sort(a.begin(), a.end());
      int lo = 0, hi = ++dummy;
      for(int j = m - 1; j >= 0; --j) {
         if(a[j].first == -1)
            break;
         if(j - m + 1)
            if(a[j].first != a[j + 1].first)
               lo = hi,
               hi = ++dummy;
         if(lo) {
            E[lo].push_back(a[j].second);
            ed[a[j].second]++;
         }
         E[a[j].second].push_back(hi);
         ed[hi]++;
      }
   }
   flag = false;
   REP(i, dummy)
      if(!ed[i + 1] && !bio[i + 1])
         dfs(i + 1);
   if(!flag and sol.size() == m)
      for(auto x : sol)
         printf("%d ", x);
   else
      printf("-1");
   return 0;
}