#include <cstdio>
#include <algorithm>
#define MAXL 4050

const int mod=1000000007;

int fac[MAXL];

int w,h;
int gcd[MAXL][MAXL];
int dp[2][4][2][2][2];

void pre() {
   fac[1]=1;
   for(int i=2;i<MAXL;i++) {
      if(fac[i]) continue;
      fac[i]=i;
      for(int j=i*i;j<MAXL;j+=i)
         fac[j]=i;
   }
   for(int i=1;i<MAXL;i++) {
      gcd[0][i]=gcd[i][0]=i;
      for(int j=1;j<MAXL;j++) {
         if(i==1||j==1) gcd[i][j]=1;
         else {
            int f=fac[i];
            if(j%f==0) gcd[i][j]=gcd[i/f][j/f]*f;
            else gcd[i][j]=gcd[i/f][j];
         }
      }
   }
}

inline int modn(int x) {
   if(x<0) return x+mod;
   if(x>=mod) return x-mod;
   return x;
}
inline int addto(int &x,int val) {
   x=modn(x+val);
}

inline int disg() {
   int s=0;
   // 3
   addto(s,(w+1)*(h+1));
   // 2 & collinear
   for(int i=0;i<=w;i++) {
      for(int j=0;j<=h;j++) {
         if(!i&&!j) continue;
         int place=(w-i+1)*(h-j+1);
         int g=gcd[i][j];
         int tot=(long long)place*(g)*6%mod;
         addto(s,tot);
         if(i&&j) addto(s,tot);
      }
   }
   return s;
}

inline int pick(int a,int z) {
   if(z) return (a+1)>>1;
   else return (a>>1)+1;
}

int solve() {
   //int all=(long long)(w+1)*(w+1)*(w+1)%mod*(h+1)*(h+1)*(h+1)%mod;
   int all=0;
   for(int x1=0;x1<2;x1++)
      for(int x2=0;x2<2;x2++)
         for(int x3=0;x3<2;x3++)
            for(int y1=0;y1<2;y1++)
               for(int y2=0;y2<2;y2++)
                  for(int y3=0;y3<2;y3++)
                     if(!(x1*y2+x1*y3+x2*y1+x2*y3+x3*y1+x3*y2&1))
                        addto(all,(long long)pick(w,x1)*pick(w,x2)*pick(w,x3)%mod*pick(h,y1)*pick(h,y2)*pick(h,y3)%mod);
   int d=disg();
   int ret=(all-d+mod)%mod;
   //printf("<%d %d>\n",all,d);
   return ret;
}

int main(void)
{
   pre();
   scanf("%d %d",&w,&h);
   printf("%d\n",solve());
   return 0;
}