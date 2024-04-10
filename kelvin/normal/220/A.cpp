#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100050

using namespace std;

int n;
int s[MAXN],a[MAXN];

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++) {
      scanf("%d",s+i);
      a[i]=s[i];
   }
   sort(a,a+n);
   int d=0;
   for(int i=0;i<n;i++)
      if(s[i]!=a[i]) d++;
   puts(d<=2?"YES":"NO");
   return 0;
}