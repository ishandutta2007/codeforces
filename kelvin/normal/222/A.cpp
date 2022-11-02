#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100060

using namespace std;

int n,k;
int s[MAXN];

int solve() {
   k--;
   for(int i=k;i<n;i++)
      if(s[i]!=s[k]) return -1;
   int j;
   for(j=k-1;j>=0;j--)
      if(s[j]!=s[k]) break;
   return j+1;
}

int main(void)
{
   scanf("%d %d",&n,&k);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   printf("%d\n",solve());
   return 0;
}