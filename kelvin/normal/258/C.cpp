#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define MAXN 100050

using namespace std;

const int mod=1000000007;
const int maxval=100500;

int n,maxs;
int s[MAXN];
vector<int> fac[maxval];
int acc[maxval];

inline int modit(int x) {
   if(x<0) x+=mod;
   if(x>=mod) x-=mod;
   return x;
}

inline int power(int x,int p) {
   int s=1,m=x;
   while(p) {
      if(p&1) s=(long long)s*m%mod;
      m=(long long)m*m%mod;
      p>>=1;
   }
   return s;
}

int solve() {
   for(int i=0;i<n;i++)
      acc[s[i]]++;
   for(int i=1;i<maxval;i++)
      acc[i]+=acc[i-1];
   for(int i=1;i<=maxs;i++) {
      for(int j=i;j<=maxs;j+=i)
         fac[j].push_back(i);
   }
   int sol=0;
   for(int m=1;m<=maxs;m++) {
      //int top=acc[m];
      int all=1;
      int bad=1;
      //printf(">> m=%d\n",m);
      //int pa=0;
      vector<int> seq;
      seq.reserve(fac[m].size()+1);
      for(int i=0;i<fac[m].size();i++)
         seq.push_back(acc[maxval-1]-acc[fac[m][i]-1]);
      seq.push_back(0);
      for(int i=0;i<fac[m].size();i++) {
         //int a=acc[fac[m][i]]-pa;
         //pa=acc[fac[m][i]];
         int a=seq[i]-seq[i+1];
         //int ba=a;
         //if(i+1==fac[m].size()) ba=0;
         //if(i+2==fac[m].size()) ba+=acc[m];
         //printf("fac[%d][%d] = %d, %d %d %d\n",m,i,fac[m][i],(int)fac[m].size(),power(i+1==fac[m].size()?i:i+1,a)%mod,a);
         //printf("fac[%d][%d] = %d, a=%d\n",m,i,fac[m][i],a);
         //(i+1)^a
         all=(long long)all*power(i+1,a)%mod;
         //bad=(long long)bad*power(i+1,ba)%mod;
         bad=(long long)bad*power(i+1==fac[m].size()?i:i+1,a)%mod;
      }
      //printf("%d: %d - %d\n",m,all,bad);
      sol=modit(sol+all-bad);
   }
   return sol;
}

int main(void)
{
   scanf("%d",&n);
   maxs=0;
   for(int i=0;i<n;i++) {
      scanf("%d",s+i);
      maxs=max(maxs,s[i]);
   }
   printf("%d\n",solve());
   return 0;
}