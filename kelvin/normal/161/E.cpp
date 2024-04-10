#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXL 6
#define MAXVAL 100050

using namespace std;

int p10[]={1,10,100,1000,10000,100000};

int pn=0,pr[MAXVAL];
bool np[MAXVAL]={0};

int px,len,sol;
int mat[6][6];

int dp[10000];

inline void gen() {
   np[0]=np[1]=1;
   for(int i=2;i<MAXVAL;i++) {
      if(np[i]) continue;
      pr[pn++]=i;
      if(i>400) continue;
      for(int j=i*i;j<MAXVAL;j+=i)
         np[j]=1;
   }
}

inline int rowval(int r,int vlen=MAXL) {
   int ret=0;
   for(int i=0;i<len;i++)
      ret=ret*10+(i<vlen?mat[r][i]:0);
   return ret;
}

inline int get() {
   int h=mat[3][1]*1000+mat[3][2]*100+mat[4][1]*10+mat[4][2];
   if(dp[h]<0) {
      dp[h]=0;
      for(int i=0;i<10;i++) {
         mat[3][3]=i;
         for(int j=0;j<10;j++) {
            mat[3][4]=mat[4][3]=j;
            if(np[rowval(3)]) continue;
            for(int k=0;k<10;k++) {
               mat[4][4]=k;
               if(np[rowval(4)]) continue;
               dp[h]++;
            }
         }
      }
   }
   return dp[h];
}

void dfs(int r) {
   if(len==5&&r==3) {
      sol+=get();
      return;
   }
   if(r==len) {
      sol++;
      return;
   }
   int st=rowval(r,r);
   int ed=st+p10[len-r];
   int *si=lower_bound(pr,pr+pn,st);
   int *ei=lower_bound(pr,pr+pn,ed);
   //printf("<%d: %d %d>\n",r,*si,*ei);
   for(int *pi=si;pi<ei;pi++) {
      int tmp=*pi;
      for(int i=len-1;i>=r;i--) {
         mat[r][i]=mat[i][r]=tmp%10;
         tmp/=10;
      }
      dfs(r+1);
   }
}

inline int solve() {
   int tmp=px;
   len=0;
   while(tmp) {
      tmp/=10;
      len++;
   }
   tmp=px;
   memset(mat,0,sizeof(mat));
   memset(dp,-1,sizeof(dp));
   for(int i=0;i<len;i++) {
      mat[0][len-i-1]=mat[len-i-1][0]=tmp%10;
      tmp/=10;
   }
   sol=0;
   dfs(1);
   return sol;
}

int main(void) 
{
   int t;
   gen();
   scanf("%d",&t);
   while(t--) {
      scanf("%d",&px);
      printf("%d\n",solve());
   }
   return 0;
}