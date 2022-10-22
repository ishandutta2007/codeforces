#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define MaxN 100005

double sol;
vector<int> E[MaxN];

void dfs(int x, int dub = 1, int root = -1) {
   sol += (double)1 / (double)dub;
   for(auto y : E[x])
      if(y != root)
         dfs(y, dub + 1, x);
}

int main() {
   int n; scanf("%d", &n);
   for(int i = 1; i < n; ++i) {
      int x, y; scanf("%d%d", &x, &y);
      E[x].push_back(y);
      E[y].push_back(x);
   }
   dfs(1);
   printf("%f", sol);
   return 0;
}