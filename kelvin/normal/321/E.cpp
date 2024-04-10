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
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
#define PR printf
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RIII(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define PRI(x) printf("%d\n",x)
#define PRII(x,y) printf("%d %d\n",x,y)
#define DPRI(x) fprintf(stderr,"<"#x"=%d>\n",x)
#define DPRII(x,y) fprintf(stderr,"<"#x"=%d, "#y"=%d>\n",x,y)
#define DPRIII(x,y,z) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d>\n",x,y,z)
#define DPRS(x) fprintf(stderr,"<"#x"=%s>\n",x)
#define DPRMSG(x) fprintf(stderr,#x"\n")
#define DPRPII(x) fprintf(stderr,"<"#x"=(%d,%d)>\n",x.F,x.S)
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
   T a0=1,a1=0,b0=0,b1=1; if(a<0) { a=-a; a0=-1; } if(b<0) { b=-b; b1=-1; }
   while(b) { T t,q=a/b; t=b; b=a-b*q; a=t; t=b0; b0=a0-b0*q; a0=t; t=b1; b1=a1-b1*q; a1=t; }
   return MP(a0,a1);
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

#define MAXN 4050
const int inf=1000000000;

int n,k;
char c[MAXN][MAXN];
int ac[MAXN][MAXN];
int dp[MAXN][MAXN];
short last[MAXN][MAXN];

int solve() {
   for(int j=0;j<n;j++) {
      ac[j+1][j+1]=inf;
      ac[j][j+1]=0;
      int s=0;
      for(int i=j-1;i>=0;i--) {
         s+=c[i][j];
         ac[i][j+1]=ac[i][j]+s;
      }
   }
   //
   dp[0][0]=0;
   last[0][0]=0;
   for(int i=1;i<=n;i++)
      dp[i][0]=inf;
   for(int j=1;j<=k;j++)
      dp[0][j]=inf;
   for(int i=1;i<=n;i++) {
      for(int j=min(i,k);j>0;j--) {
         if(i==j) {
            dp[i][i]=dp[i-1][i-1]+ac[i-1][i];
            last[i][i]=i-1;
            continue;
         }
         dp[i][j]=inf;
         int m1=last[i-1][j];
         int m2=last[i][j+1];
         if(j+1>k) m2=i-1;
         for(int m=m1;m<=m2;m++) {
            int val=dp[m][j-1]+ac[m][i];
            if(val<dp[i][j]) {
               dp[i][j]=val;
               last[i][j]=m;
            }
         }
      }
   }
   return dp[n][k];
}

char in[50000];
int main(void) {
   RII(n,k);
   gets(in);
   for(int i=0;i<n;i++) {
      gets(in);
      char *pt=strtok(in," ");
      for(int j=0;j<n;j++) {
         c[i][j]=atoi(pt);
         pt=strtok(NULL," ");
         //RI(c[i][j]);
      }
   }
   PRI(solve());
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread