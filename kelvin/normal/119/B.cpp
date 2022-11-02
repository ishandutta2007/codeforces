#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 200

using namespace std;

const int inf=1000000000;

int k,n,per,m,mins,maxs,all;
int s[MAXN];
bool used[MAXN]={0};

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

int main(void)
{
   scanf("%d %d",&n,&k);
   per=n/k;
   all=k*per;
   for(int i=0;i<n;i++)
      scanf("%d",&s[i]);
   scanf("%d",&m);
   mins=inf;
   maxs=0;
   for(int i=0;i<m;i++) {
      int x,sum=0;
      for(int j=0;j<per;j++) {
         scanf("%d",&x);
         x--;
         used[x]=1;
         sum+=s[x];
      }
      mins=min(sum,mins);
      maxs=max(sum,maxs);
   }
   //printf("%d %d\n",mins,maxs);
   vector<int> a;
   a.clear();
   for(int i=0;i<n;i++)
      if(!used[i]) a.push_back(s[i]);
   sort(a.begin(),a.end());
   if(a.size()>=n-all+per) {
      int s1=0,s2=0;
      for(int i=0;i<per;i++) {
         s1+=a[i];
         s2+=a[a.size()-i-1];
      }
      mins=min(s1,mins);
      maxs=max(s2,maxs);
   }
   printf("%.12lf %.12lf\n",(double)mins/per,(double)maxs/per);
   return 0;
}