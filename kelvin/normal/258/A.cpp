#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define MAXN 100050

using namespace std;

char s[MAXN];

void solve() {
   bool hz=0;
   int pz;
   int l=strlen(s);
   for(int i=l-1;i>=0;i--) {
      if(s[i]=='0') {
         hz=1;
         pz=i;
      }
   }
   if(!hz) {
      s[l-1]=0;
      puts(s);
   } else {
      for(int i=0;i<l;i++)
         if(i!=pz) printf("%c",s[i]);
      puts("");
   }
}

int main(void)
{
   scanf("%s",s);
   solve();
   return 0;
}