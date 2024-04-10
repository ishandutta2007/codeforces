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
#define DPRIIII(x,y,z,w) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d "#w"=%d>\n",x,y,z,w)
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

#define MAXL 3020

// DisjointSet {{{
class DisjointSet {
   public:
      int n;
      int *rep,*bias;
      DisjointSet(int _n):n(_n) {
         rep=new int[n];
         bias=new int[n];
         for(int i=0;i<n;i++) {
            rep[i]=i;
            bias[i]=0;
         }
      }
      ~DisjointSet() {
         delete [] rep;
         delete [] bias;
      }
      int getrep(int v) {
         if(rep[v]!=v) {
            int x=getrep(rep[v]);
            bias[v]+=bias[rep[v]];
            rep[v]=x;
         }
         return rep[v];
      }
      int getbias(int v) {
         getrep(v);
         return bias[v];
      }
      bool merge(int v,int u,int b) {
         int vb=getbias(v);
         int ub=getbias(u);
         v=getrep(v);
         u=getrep(u);
         if(v==u) return 0;
         rep[u]=v;
         bias[u]=vb+b-ub;
         return 1;
      }
};
// }}}

const int adj[8][2]={-1,-1,-1,0,-1,1, 0,-1,0,1, 1,-1,1,0,1,1};

int rn,cn,qn,vn;
bool vis[MAXL][MAXL];
int tag[MAXL*MAXL],tagid=0;
int val[MAXL*MAXL];

inline int getid(int r,int c) { return r*cn+c; }
inline bool valid(int r,int c) { return r>=0&&r<rn; }

int main(void) {
   RIII(rn,cn,qn);
   vn=rn*cn;
   DisjointSet djs(vn);
   int sol=0;
   for(int qi=0;qi<qn;qi++) {
      int r,c;
      RII(r,c); r--; c--;
      vis[r][c]=1;
      int v=getid(r,c);
      ++tagid;
      bool ok=1;
      for(int i=0;i<8;i++) {
         int nr=r+adj[i][0];
         int nc=c+adj[i][1];
         int bi=adj[i][1];
         if(nc<0) nc+=cn;
         if(nc>=cn) nc-=cn;
         if(!valid(nr,nc)) continue;
         if(!vis[nr][nc]) continue;
         int u=getid(nr,nc);
         //int vb=djs.getbias(v);
         int ub=djs.getbias(u);
         int re=djs.getrep(u);
         if(tag[re]<tagid) {
            tag[re]=tagid;
            val[re]=ub-bi;
         }
         if(val[re]!=ub-bi) {
            ok=0;
            break;
         }
         //DPRIIII(r,c,nr,nc);
         //DPRIII(vb,ub,bi);
         /*if(djs.getrep(v)==djs.getrep(u)&&ub!=vb+bi) {
            ok=0;
            break;
         }*/
      }
      if(!ok) {
         vis[r][c]=0;
         continue;
      }
      //DPRII(r,c);
      sol++;
      for(int i=0;i<8;i++) {
         int nr=r+adj[i][0];
         int nc=c+adj[i][1];
         int bi=adj[i][1];
         if(nc<0) nc+=cn;
         if(nc>=cn) nc-=cn;
         if(!valid(nr,nc)) continue;
         if(!vis[nr][nc]) continue;
         int u=getid(nr,nc);
         djs.merge(v,u,bi);
      }
   }
   PRI(sol);
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread