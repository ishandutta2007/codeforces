#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 100060

using namespace std;

int n,k;
long long b;
int s[MAXN];
int cp[MAXN];

bool cmp(int a,int b) { return a>b; }

int solve() {
   for(int i=0;i<n;i++)
      cp[i]=s[i];
   sort(cp,cp+n-1,cmp);
   long long csum=0;
   int len=min(n-1,k);
   for(int i=0;i<len;i++)
      csum+=cp[i];
   if(csum<=b) return n;
   int minof=cp[len-1];
   int opt=n;
   for(int i=0;i<n;i++) {
      long long val;
      if(s[i]<minof) val=csum-minof+s[i];
      else val=csum;
      if(val>b) opt=min(opt,i);
   }
   return opt+1;
}

int main(void)
{
   scanf("%d %d",&n,&k);
   cin >> b;
   if(k>n) k=n;
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   printf("%d\n",solve());
   return 0;
}