#include <stdio.h>
#include <algorithm>
#define MAXN 100050

using namespace std;

int il;
int in[MAXN];
typedef pair<int,int> pii;

int sn;
pii s[MAXN];

inline bool solve() {
   sn=0;
   std::sort(in,in+il);
   for(int i=0;i<il;i++) {
      if(!i||in[i]!=in[i-1]) s[sn++]=make_pair(in[i],1);
      else s[sn-1].second++;
   }
   for(int i=0;i<sn-1;i++)
      if(s[i].first!=s[i+1].first-1) return 0;
   for(int i=0;i<sn-1;i++) {
      if(s[i].second==0) return 0;
      if(s[i].second>s[i+1].second) return 0;
      s[i+1].second-=s[i].second;
   }
   if(s[sn-1].second!=0) return 0;
   return 1;
}

int main(void)
{
   scanf("%d",&il);
   for(int i=0;i<il;i++)
      scanf("%d",in+i);
   //puts(solve()?"YES":"NO");
   if(solve()) puts("YES");
   else puts("NO");
   return 0;
}