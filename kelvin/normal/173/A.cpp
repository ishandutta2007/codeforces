#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAXL 1050

using namespace std;

int res[7]={0,-1,1,0,-1,1,0};

inline int id(char c) {
   if(c=='R') return 0;
   if(c=='S') return 1;
   return 2;
}
inline int cmp(char a,char b) {
   return res[id(a)+3-id(b)];
}

int main(void)
{
   int n,al,bl,m;
   char a[MAXL],b[MAXL];
   int c1[MAXL*MAXL],c2[MAXL*MAXL];
   scanf("%d",&n);
   scanf("%s %s",a,b);
   al=strlen(a);
   bl=strlen(b);
   m=al*bl;
   c1[0]=c2[0]=0;
   for(int i=0;i<m;i++) {
      int r=cmp(a[i%al],b[i%bl]);
      c1[i+1]=c1[i]+(r==-1?1:0);
      c2[i+1]=c2[i]+(r==1?1:0);
   }
   int s1=n/m*c1[m]+c1[n%m];
   int s2=n/m*c2[m]+c2[n%m];
   printf("%d %d\n",s1,s2);
   return 0;
}