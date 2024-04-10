#include <stdio.h>
#define MAXZ 1000500

const int mod = 1000000007;

int z,w;
int fac[MAXZ];
int invfac[MAXZ];

inline int inv(int a) {
   int a0=1,a1=0;
   int b=mod,b0=0,b1=1;
   while(b) {
      int q=a/b,t;
      t=b; b=a-b*q; a=t;
      t=b0; b0=a0-b0*q; a0=t;
      t=b1; b1=a1-b1*q; a1=t;
   }
   return a0<0?a0+mod:a0;
}

inline void pre() {
   fac[0]=1;
   for(int i=1;i<=z;i++)
      fac[i]=(long long)fac[i-1]*i%mod;
   invfac[z]=inv(fac[z]);
   for(int i=z-1;i>=0;i--)
      invfac[i]=(long long)invfac[i+1]*(i+1)%mod;
}

inline int perm(int a,int b) {
   if(b>a||b<0) return 0;
   return (long long)fac[a]*invfac[a-b]%mod;
}

inline int pow(int x,int p) {
   int s=1,m=x;
   while(p) {
      if(p&1) s=(long long)s*m%mod;
      m=(long long)m*m%mod;
      p>>=1;
   }
   return s;
}

inline int solve() {
   int maxl=z+w,minl=w+1;
   int sol=0;
   pre();
   //for(int i=0;i<=z;i++)
      //printf("%d %d\n",fac[i],invfac[i]);
   for(int l=minl;l<=maxl;l++) {
      int cnt;
      if(w*2>l+1) {
         int sl=l-w;
         int ml=2*w-l;
         //cnt=perm(z,sl)*perm(z,sl)*pow(z,ml-2)*(z*z-(z-sl)*(z-sl));
         cnt=(long long)perm(z,sl)*perm(z,sl)%mod*pow(z,ml-2)%mod*((long long)z*z%mod-(long long)(z-sl)*(z-sl)%mod+mod)%mod;
         //printf("(1) > %d\n",cnt);
      } else if(w*2==l+1) {
         int sl=w-1;
         int ml=1;
         //cnt=z*(perm(z,sl)*perm(z,sl)-perm(z-1,sl)*perm(z-1,sl));
         cnt=(long long)z*((long long)perm(z,sl)*perm(z,sl)%mod-(long long)perm(z-1,sl)*perm(z-1,sl)%mod+mod)%mod;
         //printf("(2) > %d\n",cnt);
      } else {
         int sl=w;
         int ml=l-2*w;
         int z2=z-ml;
         //cnt=perm(z,ml)*perm(z2,sl)*perm(z2,sl)-pern(z,ml+2)*perm(z2,sl-1)*perm(z2,sl-1);
         cnt=((long long)perm(z,ml)*perm(z2,sl)%mod*perm(z2,sl)%mod-
               (long long)perm(z,ml+2)*perm(z2-2,sl-1)%mod*perm(z2-2,sl-1)%mod+mod)%mod;
         //printf("(3) > %d\n",cnt);
      }
      sol=(sol+cnt)%mod;
   }
   return sol;
}

int main(void)
{
   while(scanf("%d %d",&z,&w)==2) {
      printf("%d\n",solve());
   }
   return 0;
}