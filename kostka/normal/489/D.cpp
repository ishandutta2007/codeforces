#include "bits/stdc++.h"

using namespace std;

const int MAXN = 3007;
vector <int> G[MAXN], O[MAXN];

long long res;

void count(int a, int b)
{
   if(G[a].size() == 0 || O[b].size() == 0)
      return;
   int i = 0, j = 0, x = 0;
   //cerr << "CH " << G[a].size() << " " << O[b].size() << "\n";
   while(true)
   {
      //cerr << i << " " << j << "\n";
      while(i<G[a].size() && G[a][i]<O[b][j])
         i++;
      while(j<O[b].size() && G[a][i]>O[b][j])
         j++;
      if(i==G[a].size() || j==O[b].size())
         break;
      if(G[a][i] == O[b][j])
      {
         i++;
         j++;
         x++;
      }
   }
   res += 1LL*x*(x-1)/2;
}

int main()
{
   int n, m;
   scanf("%d%d", &n, &m);
   while(m--)
   {
       int a, b;
       scanf("%d%d", &a, &b);
       G[a].push_back(b);
       O[b].push_back(a);
   }
   for(int i=1; i<=n; i++)
   {
      sort(G[i].begin(), G[i].end());
      sort(O[i].begin(), O[i].end());
   }
   for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
         if(i!=j)
            count(i,j);
   printf("%I64d\n", res);
}