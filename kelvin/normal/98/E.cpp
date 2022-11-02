#include <stdio.h>
#define MAXN 1050

const double eps=1e-10;
inline double abs(double x) {return x>=0.0?x:0.0-x;}
int n,m;
double dp[MAXN][MAXN];

inline void relax(double &x,double val) { if(val>x) x=val; }
inline double max(double a,double b) { return a>b?a:b; }
inline double min(double a,double b) { return a<b?a:b; }

inline void pre() {
   int i,j,s;
   double a,b,c,d,p;
   dp[0][0]=1.0;
   for(i=0;i<MAXN;i++)
      dp[i][0]=1.0;
   for(j=0;j<MAXN;j++)
      dp[0][j]=(double)1.0/(j+1);
   for(s=2;s<=MAXN+MAXN;s++) {
      for(i=1;i<s&&i<MAXN;i++) {
         j=s-i;
         if(j<1||j>=MAXN) continue;
         a=1.0;
         b=(double)j/(j+1)*(1.0-dp[j-1][i]);
         c=1.0-dp[j][i-1];
         d=(double)1/(j+1)+(double)j/(j+1)*(1.0-dp[j-1][i]);
         dp[i][j]=0.0;
         if(abs(a+d-b-c)>eps) {
            p=(d-b)/(a-b-c+d);
            relax(dp[i][j],p*a+(1-p)*b);
         }
         relax(dp[i][j],min(a,c));
         relax(dp[i][j],min(b,d));
         relax(dp[i][j],(double)1/(j+1));
      }
   }
}

int main(void)
{
   int i,j;
   pre();
   while(scanf("%d %d",&n,&m)==2) {
      printf("%.11lf %.11lf\n",dp[n][m],1.0-dp[n][m]);
   }
   return 0;
}