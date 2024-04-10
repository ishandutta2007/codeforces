#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 1050

using namespace std;

int rn,cn,qn;
int s[MAXN][MAXN];
int ri[MAXN],ci[MAXN];

int main(void)
{
   scanf("%d %d %d",&rn,&cn,&qn);
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         scanf("%d",s[i]+j);
   for(int i=0;i<rn;i++)
      ri[i]=i;
   for(int j=0;j<cn;j++)
      ci[j]=j;
   for(int t=0;t<qn;t++) {
      char ch[3];
      int o1,o2;
      scanf("%s %d %d",ch,&o1,&o2);
      o1--; o2--;
      if(ch[0]=='r') {
         swap(ri[o1],ri[o2]);
      } else if(ch[0]=='c') {
         swap(ci[o1],ci[o2]);
      } else {
         printf("%d\n",s[ri[o1]][ci[o2]]);
      }
   }
   return 0;
}