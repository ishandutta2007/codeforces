#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define MAXL 1000050

using namespace std;

typedef pair<char,int> pci;

int len;
char s[MAXL+2];

inline void solve() {
   int carry=0;
   vector<pci> sol;
   for(int i=0;i<=len;i++) {
      //printf("%d ",i);
      s[i]+=carry;
      if(s[i]>=2) {
         carry=1;
         continue;
      } else carry=0;
      if(!s[i]) continue;
      if(s[i+1]) {
         sol.push_back(make_pair('-',i));
         carry=1;
      } else {
         sol.push_back(make_pair('+',i));
         carry=0;
      }
   }
   //puts("!");
   printf("%d\n",sol.size());
   for(int i=0;i<sol.size();i++)
      printf("%c2^%d\n",sol[i].first,sol[i].second);
}

int main(void)
{
   scanf("%s",s);
   len=strlen(s);
   for(int i=0;i<len-i-1;i++)
      swap(s[i],s[len-i-1]);
   for(int i=0;i<len;i++)
      s[i]-='0';
   s[len]=s[len+1]=0;
   solve();
   return 0;
}