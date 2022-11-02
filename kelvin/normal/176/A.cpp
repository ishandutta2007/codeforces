#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAXPLANET 12
#define MAXN 105

using namespace std;

int nplanet,n,cap;
int buy[MAXPLANET][MAXN],sell[MAXPLANET][MAXN],rem[MAXPLANET][MAXN];

int s[MAXN],r[MAXN];

bool cmp(int a,int b) { return a>b; }

inline int solve() {
   int opt=0;
   for(int y=0;y<nplanet;y++) {
      for(int i=0;i<n;i++)
         r[i]=rem[y][i];
      for(int z=0;z<nplanet;z++) {
         if(y==z) continue;
         int poscnt=0;
         vector<int> arr;
         for(int i=0;i<n;i++) {
            s[i]=sell[z][i]-buy[y][i];
            for(int j=0;j<r[i];j++) {
               arr.push_back(s[i]);
               if(s[i]>0) poscnt++;
            }
         }
         int take=min(poscnt,cap),sum=0;
         nth_element(arr.begin(),arr.begin()+take,arr.end(),cmp);
         for(int i=0;i<take;i++)
            sum+=arr[i];
         opt=max(sum,opt);
      }
   }
   return opt;
}

int main(void)
{
   scanf("%d %d %d",&nplanet,&n,&cap);
   for(int i=0;i<nplanet;i++) {
      scanf("%*s");
      for(int j=0;j<n;j++)
         scanf("%d %d %d",buy[i]+j,sell[i]+j,rem[i]+j);
   }
   printf("%d\n",solve());
   return 0;
}