#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 1000050

using namespace std;

int len,pt;
char s[MAXL];

/*#define ZZ 0
#define OO 1
#define ZO 2
#define SS 3*/

inline int OR(int a,int b) {
   return (1<<max(a,b))|(a==1&&b==1?4:0);
}
inline int AND(int a,int b) {
   return (1<<min(a,b))|(a==1&&b==1?1:0);
}
inline int XOR(int a,int b) {
   if(a!=1&&b!=1) {
      if(a==b) return 1;
      else return 4;
   } else if(a==1&&b==1) {
      return 1|4;
   } else {
      return 2;
   }
}

#define _OR 0
#define _AND 1
#define _XOR 2

inline int calc(int a,int b,int op) {
   int r=0;
   for(int i=0;i<3;i++) {
      if(!(a&(1<<i))) continue;
      for(int j=0;j<3;j++) {
         if(!(b&(1<<j))) continue;
         if(op==_OR) r|=OR(i,j);
         if(op==_AND) r|=AND(i,j);
         if(op==_XOR) r|=XOR(i,j);
      }
   }
   return r;
}

int go() {
   if(s[pt]=='(') {
      ++pt;
      int v1=go();
      char op=s[pt++];
      int v2=go();
      ++pt;
      int opid;
      if(op=='|') opid=_OR;
      if(op=='&') opid=_AND;
      if(op=='^') opid=_XOR;
      return calc(v1,v2,opid);
   } else {
      char c=s[pt++];
      //printf("[%c]\n",s[pt]);
      if(c=='0') return 1;
      if(c=='1') return 4;
      /*?*/ return 2;
   }
}

bool solve() {
   pt=0;
   int res=go();
   //printf("<%d>\n",res);
   return (res&2)?1:0;
}

int main(void)
{
   scanf("%*d");
   scanf("%s",s);
   len=strlen(s);
   puts(solve()?"YES":"NO");
   return 0;
}