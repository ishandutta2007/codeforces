#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2005000

using namespace std;

int n;
char s[MAXN];
int a[MAXN*2];

int main(void)
{
   scanf("%s",s);
   n=strlen(s);
   int l=MAXN,r=MAXN;
   a[MAXN]=n;
   for(int i=n-2;i>=0;i--) {
      if(s[i]=='r') {
         a[--l]=i+1;
      } else {
         a[++r]=i+1;
      }
   }
   for(int i=l;i<=r;i++)
      printf("%d\n",a[i]);
   return 0;
}