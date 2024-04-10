#include <stdio.h>
#include <utility>
#include <algorithm>
#include <map>
#define MAXN 200050

using namespace std;

const int mod = 1000000007;

int len,bn;
pair<int,int> bs[MAXN];
map<int,int> dp,acc;

int main(void)
{
   int i,s,f;
   scanf("%d %d",&len,&bn);
   for(i=0;i<bn;i++)
      scanf("%d %d",&bs[i].second,&bs[i].first);
   sort(bs,bs+bn);
   dp[-1]=0;
   dp[0]=1;
   for(i=0;i<bn;i++) {
      f=bs[i].first;
      s=bs[i].second;
      if(dp.find(f)==dp.end()) {
         int tmp=(--dp.end())->second;
         dp[f]=tmp;
      }
//      printf("%d %d: %d %d\n",s, f,(--dp.lower_bound(f))->first,(--dp.lower_bound(s))->first);
      dp[f]+=(--dp.lower_bound(f))->second-(--dp.lower_bound(s))->second;
      if(dp[f]<0) dp[f]+=mod;
      if(dp[f]>=mod) dp[f]-=mod;
   }
//   for(map<int,int>::iterator it=dp.begin();it!=dp.end();it++)
//      printf("%d %d\n",it->first,it->second);
   if(dp.find(len)==dp.end()) puts("0");
   else {
      int res=dp[len]-(--dp.lower_bound(len))->second;
      if(res<0) res+=mod;
      if(res>=mod) res-=mod;
      printf("%d\n",res);
   }
   return 0;
}