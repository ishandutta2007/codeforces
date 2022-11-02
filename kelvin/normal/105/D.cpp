#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <utility>
#define MAXL 305
#define MAXN (MAXL*MAXL)

using namespace std;

class Pyramid {
   public:
      int r,c,color,id;
      Pyramid() {}
      Pyramid(int ri,int ci,int cc): r(ri),c(ci),color(cc) {}
      const bool operator<(const Pyramid &b) const {
         return id<b.id;
      }
};

class Node {
   public:
      Node *r;
      Node() { r=this; }
      Node *rep() {
         if(r!=this) r=r->rep();
         return r;
      }
};
inline void merge(Node *v,Node *u) {
   v=v->rep();
   u=u->rep();
   u->r=v;
}

const int adj[4][2]={0,1, 1,0, 0,-1, -1,0};
typedef pair<int,int> pii;
map<pii,int> xmap;

int ccc,colorn;
int colorset[MAXN*2];
map<int,int> cmap;

int rn,cn,sr,sc;
int bg[MAXL][MAXL];
int fl[MAXL][MAXL];

vector<Pyramid> pyr[MAXN*2];
int blank[MAXN*2];

queue<Pyramid> pq;
long long paint;
Node vs[MAXN*2];

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline void gen() {
   int ttt=MAXL*MAXL*4;
   int t,i,j,d,r,c;
   xmap.clear();
   r=c=0;
   xmap[make_pair(0,0)]=0;
   t=1;
   for(i=2;;i+=2) {
      r=c=-i/2;
      for(d=0;d<4;d++) {
         for(j=0;j<i;j++) {
            r+=adj[d][0];
            c+=adj[d][1];
            xmap[make_pair(r,c)]=t++;
         }
      }
      if(t>=ttt) break;
   }
}

inline void init() {
   int i,j;
   paint=0;
   while(!pq.empty()) pq.pop();
   pq.push(Pyramid(sr,sc,fl[sr][sc]));
   fl[sr][sc]=-1;
   for(i=0;i<colorn;i++) {
      blank[i]=0;
      vs[i].r=vs+i;
      pyr[i].clear();
   }
   for(i=0;i<rn;i++) {
      for(j=0;j<cn;j++) {
         if(fl[i][j]>=0) {
            pyr[bg[i][j]].push_back(Pyramid(i,j,fl[i][j]));
         } else {
            blank[bg[i][j]]++;
         }
      }
   }
}

inline void process(int r,int c,int fc,int bc) {
   int i,sz;
   bc=vs[bc].rep()-vs;
//   printf("%d %d %d %d\n",r,c,fc,bc);
   if(!bc) return;
   if(bc==fc) return;
   paint+=blank[bc];
   paint+=pyr[bc].size();
   vs[fc].r=vs+fc;
   merge(vs+fc,vs+bc);
   sz=pyr[bc].size();
   for(i=0;i<sz;i++)
      pyr[bc][i].id=xmap[make_pair(pyr[bc][i].r-r,pyr[bc][i].c-c)];
   sort(pyr[bc].begin(),pyr[bc].end());
   for(i=0;i<sz;i++)
      pq.push(pyr[bc][i]);
   blank[fc]+=blank[bc]+pyr[bc].size();
   blank[bc]=0;
   pyr[bc].clear();
}

inline long long solve() {
   int r,c,x;
   init();
   while(pq.size()) {
      r=pq.front().r;
      c=pq.front().c;
      x=pq.front().color;
      pq.pop();
      process(r,c,x,bg[r][c]);
   }
   return paint;
}

int main(void)
{
   int i,j;
   gen();
   scanf("%d %d",&rn,&cn);
   ccc=0;
   for(i=0;i<rn;i++) {
      for(j=0;j<cn;j++) {
         scanf("%d",bg[i]+j);
         colorset[ccc++]=bg[i][j];
      }
   }
   for(i=0;i<rn;i++) {
      for(j=0;j<cn;j++) {
         scanf("%d",fl[i]+j);
         if(fl[i][j]>=0) colorset[ccc++]=fl[i][j];
      }
   }
   scanf("%d %d",&sr,&sc);
   sr--;
   sc--;
   colorset[ccc++]=0;
   sort(colorset,colorset+ccc);
   colorn=0;
   cmap.clear();
   for(i=0;i<ccc;i++)
      if(cmap.find(colorset[i])==cmap.end()) cmap[colorset[i]]=colorn++;
   for(i=0;i<rn;i++)
      for(j=0;j<cn;j++)
         bg[i][j]=cmap[bg[i][j]];
   for(i=0;i<rn;i++)
      for(j=0;j<cn;j++)
         if(fl[i][j]>=0) fl[i][j]=cmap[fl[i][j]];
   long long sol=solve();
   cout << sol << endl;
   return 0;
}