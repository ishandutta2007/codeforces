#include <cstdio>
#include <iostream>
#define MAXN 100050

using namespace std;

int n,d;
int s[MAXN];

long long solve() {
   long long sol=0;
   for(int i=0,j=0;i<n;i++) {
      while(j<n&&s[j]<=s[i]+d) j++;
      int g=j-i-1;
      sol+=(long long)g*(g-1)/2;
   }
   return sol;
}

int main(void)
{
   scanf("%d %d",&n,&d);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   cout << solve() << endl;
   return 0;
}