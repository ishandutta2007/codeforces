#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAXSEL 1050
#define MAXTYPE 1050
#define MAXSUM 1050

using namespace std;

double logx[MAXSUM];
double logfac[MAXSUM];

int sel,ntype;
vector<int> pr[MAXTYPE],allpr;

int eqi[MAXTYPE],alleq;
double dp[MAXTYPE][MAXSUM];
double ss[MAXTYPE][MAXSUM];

bool desc(int a,int b) { return a>b; }

void pre() {
   logfac[0]=0.0;
   for(int i=1;i<MAXSUM;i++) {
      logx[i]=log(i);
      logfac[i]=logfac[i-1]+logx[i];
   }
}

inline double logcomb(int a,int b) {
   return logfac[a]-logfac[b]-logfac[a-b];
}

double solve() {
   pre();
   sort(allpr.begin(),allpr.end(),desc);
   int thr=allpr[sel-1]; // >=thr
   int thc=0;
   for(int i=0;i<sel;i++)
      if(allpr[i]==thr) thc++;
   alleq=0;
   /*for(int i=0;i<ntype;i++) {
      eqi[i]=0;
      for(int j=0;j<pr[i].size();j++)
         if(pr[i][j]==thr) eqi[i]++;
      alleq+=eqi[i];
   }*/
   int csum=0;
   dp[0][0]=1.0;
   ss[0][0]=1.0;
   for(int i=0;i<ntype;i++) {
      int gt=0,eq=0;
      for(int j=0;j<pr[i].size();j++) {
         if(pr[i][j]>thr) gt++;
         if(pr[i][j]==thr) eq++;
      }
      for(int j=0;j<=csum;j++) {
         for(int k=0;k<=eq&&j+k<=thc;k++) {
            // p: all=pr[i].size(), gt, eq
            // C(eq,k)/C(pr[i].size(),gt+k)
            double p=exp(logcomb(eq,k)-logcomb(pr[i].size(),gt+k));
            dp[i+1][j+k]+=dp[i][j]*p;
            ss[i+1][j+k]+=ss[i][j];
         }
      }
      csum=min(thc,csum+eq);
   }
   //double pg=exp(logcomb(alleq,thc));
   //double sol=dp[ntype][thc]/pg;
   double sol=dp[ntype][thc]/ss[ntype][thc];
   return sol;
}

int main(void)
{
   scanf("%d %d",&sel,&ntype);
   for(int i=0;i<ntype;i++) {
      int pn;
      scanf("%d",&pn);
      pr[i].resize(pn);
      for(int j=0;j<pn;j++) {
         scanf("%d",&(pr[i][j]));
         allpr.push_back(pr[i][j]);
      }
   }
   printf("%.12lf\n",solve());
   return 0;
}