#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define MAXN 4050
#define MAXVAL 1200000

using namespace std;
typedef pair<int,int> pii;

int n;
int s[MAXN];
bool vis[MAXVAL];
int ind[MAXVAL];
int next[MAXN];

int solve() {
   int sol=1;
   /*for(int i=0;i<n;i++) {
      int x=s[i];
      int c=1;
      for(int j=i+1;j<n;j++)
         if(s[j]==x) c++;
      sol=max(sol,c);
   }*/
   for(int i=0;i<MAXVAL;i++)
      ind[i]=n;
   for(int i=n-1;i>=0;i--) {
      next[i]=ind[s[i]];
      ind[s[i]]=i;
   }
   for(int i=0;i<n;i++) {
      int x=s[i];
      if(vis[x]) continue;
      vis[x]=1;
      for(int j=i+1;j<n;j++) {
         int y=s[j];
         int ii=i,jj=j,c=2;
         while(ii<n&&jj<n) {
            while(ii<n&&ii<=jj)
               ii=next[ii];
            if(ii>=n) break;
            c++;
            while(jj<n&&jj<=ii)
               jj=next[jj];
            if(jj>=n) break;
            c++;
         }
         sol=max(sol,c);
      }
   }
   return sol;
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   printf("%d\n",solve());
   return 0;
}