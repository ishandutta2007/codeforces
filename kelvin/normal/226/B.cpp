#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 100050

using namespace std;

int n,qn;
int s[MAXN];
long long sum[MAXN];
int qa[MAXN];

long long ans[MAXN];
bool vis[MAXN];

bool cmp(int a,int b) {
   return a>b;
}

void pre() {
   sort(s,s+n);
   sum[0]=0;
   for(int i=0;i<n;i++)
      sum[i+1]=sum[i]+s[i];
}

long long solve(int b) {
   if(!vis[b]) {
      long long a=0;
      long long f=1,x=1;
      while(f<=n) {
         //cout << n-f << " " << sum[n-f] << endl;
         a+=sum[n-f];
         x*=b;
         f+=x;
      }
      vis[b]=1;
      ans[b]=a;
   }
   return ans[b];
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   pre();
   scanf("%d",&qn);
   for(int i=0;i<qn;i++) {
      scanf("%d",qa+i);
      cout << solve(qa[i]) << " ";
   }
   puts("");
   return 0;
}