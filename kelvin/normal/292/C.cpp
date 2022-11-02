// @author kelvin
// #includes {{{
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
// }}}
// #defines {{{
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define PRI(x) printf("%d\n",x);
#define PR printf
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
typedef pair<int,int> pii;
// }}}
// #functions {{{
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
template <class T>
T gcd(T a,T b) { a=abs(a); b=abs(b); while(b) { T t=b; b=a%b; a=t; } return a; }
template <class T>
pair<T,T> ext_gcd(T a,T b) {
   T a0=1,a1=0,b0=0,b1=1;
   if(a<0) { a=-a; a0=-1; }
   if(b<0) { b=-b; b1=-1; }
   while(b) {
      T t,q=a/b;
      t=b; b=a-b*q; a=t;
      t=b0; b0=a0-b0*q; a0=t;
      t=b1; b1=a1-b1*q; a1=t;
   }
   return MP(a0,a1);
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

#define MAXN 2000000

int zn,z[20];
int val2ind[200];

char str[15];
char sss[30];
int dpos[4];
int cc[200],cnt;
int pn;
string pal[MAXN];

inline int myatoi(char *s,int l) {
   if(l==1) return s[0]-'0';
   else if(l==2) return (s[0]-'0')*10+(s[1]-'0');
   else return (s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'0');
}

void dfs(int x,int q,int c,int l,int y) {
   if(x==l) {
      if(q!=4) return;
      if(c) return;
      if(cnt!=zn) return;
      sss[y-1]='\0';
      pal[pn++]=sss;
      //puts(sss);
      return;
   }
   if(q>3) return;
   int i1,i2;
   if(x<=l-x-1) {
      i1=0;
      i2=zn-1;
   } else {
      i1=i2=val2ind[str[l-x-1]];
   }
   for(int i=i1;i<=i2;i++) {
      //if(c==0&&z[i]==0) continue;
      sss[y]=str[x]=z[i];
      if(!cc[z[i]]) cnt++;
      cc[z[i]]++;
      // same
      if(c<2) dfs(x+1,q,c+1,l,y+1);
      // next
      int val=myatoi(str+x-c,c+1);
      if(val>=0&&val<=255&&(str[x-c]!='0'||c==0)) {
         sss[y+1]='.';
         dfs(x+1,q+1,0,l,y+2);
      }
      cc[z[i]]--;
      if(!cc[z[i]]) cnt--;
   }
}

void gen() {
   if(zn>=7) {
      puts("0");
      return;
   }
   pn=0;
   for(int l=4;l<=12;l++) {
      str[l]='\0';
      cnt=0;
      memset(cc,0,sizeof(cc));
      dfs(0,0,0,l,0);
   }
   printf("%d\n",pn);
   for(int i=0;i<pn;i++)
      cout << pal[i] << endl;
}

int main(void) {
   RI(zn);
   for(int i=0;i<zn;i++) {
      RI(z[i]); z[i]+='0';
      val2ind[z[i]]=i;
   }
   gen();
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread