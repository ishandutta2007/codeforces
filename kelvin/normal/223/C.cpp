#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 2050
#define MAXK 1000000500

using namespace std;
typedef pair<int,int> pii;

const int mod = 1000000007;

int n,k;
int s[MAXN];
int co[MAXN];

inline int inv(int a,int b) {
   int a0=1,a1=0,b0=0,b1=1;
   int origb=b;
   while(b) {
      int q=a/b,t;
      t=b; b=a-b*q; a=t;
      t=b0; b0=a0-b0*q; a0=t;
      t=b1; b1=a1-b1*q; a1=t;
   }
   if(a0<0) a0+=origb;
   //printf("inv %d = %d\n",a,a0);
   return a0;
}

void solve() {
   if(k==0) {
      for(int i=0;i<n;i++)
         printf("%d ",s[i]); puts("");
      return;
   }
   co[0]=1;
   for(int i=1;i<n;i++) {
      // *(k+i-1)/i
      int j=k+i-1;
      int invi=inv(i,mod);
      co[i]=(long long)co[i-1]*j%mod*invi%mod;
      //printf("co[%d]=%d\n",i,co[i]);
   }
   for(int i=0;i<n;i++) {
      int sum=0;
      for(int j=0;j<=i;j++)
         sum=(sum+(long long)co[i-j]*s[j])%mod;
      printf("%d ",sum);
   }
   puts("");
}

int main(void)
{
   scanf("%d %d",&n,&k);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   solve();
   return 0;
}