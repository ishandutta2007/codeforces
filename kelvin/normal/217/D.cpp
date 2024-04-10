#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXMOD 125
#define MAXN 10050

const int maxtake=6; // 2^7>MAXMOD
const int solmod=1000000007;

using namespace std;

int mod,n,mid;
int fuel[MAXN];
int cnt[MAXMOD]={0};

int sol;
bool srec[MAXMOD];
int an,arr[MAXMOD];

/*int zn[MAXMOD],zz[MAXMOD][MAXMOD];
*/

inline int modit(int x) {
   return x<mod?x:x-mod;
}
inline int modsol(int x) {
   return x<solmod?x:x-solmod;
}

void dfs(int x,int way,int taken) {
   //printf("<%d %d %d>\n",x,way,taken);
   if(x>mid||taken>=maxtake) {
      sol=modsol(sol+way);
      return;
   }
   // no x
   dfs(x+1,way,taken);
   // take x
   //zn[x]=0;
   bool fail=0;
   for(int i=0;i<an;i++) {
      int m=modit(arr[i]+x);
      if(srec[m]) {
         fail=1;
         break;
      }
   }
   /*for(int i=0;i<mod;i++) {
      if(!srec[i]) continue;
      int m=modit(i+x);
      if(srec[m]) {
         fail=1;
         break;
      }
      zz[x][zn[x]++]=m;
   }*/
   if(!fail) {
      /*for(int i=0;i<zn[x];i++)
         srec[zz[x][i]]=1;*/
      for(int i=0;i<an;i++) {
         int m=modit(arr[i]+x);
         srec[m]=1;
         arr[an+i]=m;
      }
      an+=an;
      dfs(x+1,way*(long long)cnt[x]%solmod,taken+1);
      /*for(int i=0;i<zn[x];i++)
         srec[zz[x][i]]=0;*/
      int nn=an>>1;
      for(int i=nn;i<an;i++)
         srec[arr[i]]=0;
      an=nn;
   }
}

int solve() {
   mid=mod/2; // 1~mid
   for(int i=mid+1;i<mod;i++) {
      cnt[mod-i]+=cnt[i];
      cnt[i]=0;
   }
   memset(srec,0,sizeof(srec));
   srec[0]=1;
   an=1; arr[0]=0;
   sol=0;
   dfs(1,1,0);
   return sol;
}

int main(void)
{
   scanf("%*d %d %d",&mod,&n);
   for(int i=0;i<n;i++) {
      scanf("%d",fuel+i);
      cnt[fuel[i]%mod]++;
   }
   printf("%d\n",solve());
   return 0;
}