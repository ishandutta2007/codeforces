#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAXL 1050

class Unit {
   public:
      int x,h;
      Unit() {}
      Unit(int xi,int hi):x(xi),h(hi) {}
};

class Position {
   public:
      int r,c;
      long long val;
      Position() {}
      Position(int ri,int ci,long long vi):r(ri),c(ci),val(vi) {}
      const bool operator<(const Position &b) const {
         if(val!=b.val) return val<b.val;
         if(r!=b.r) return r<b.r;
         if(c!=b.c) return c<b.c;
      }
      void print() {
         std::cout << r+1  << " " << c+1 << " " << val << std::endl;
      }
};

int ar,ac,br,bc,vr,vc;
int ht[MAXL][MAXL];
long long sum[MAXL][MAXL];

int cmin[MAXL][MAXL],bmin[MAXL][MAXL];

int ql,qr;
Unit que[MAXL];

int pn;
Position pos[MAXL*MAXL];
bool used[MAXL][MAXL];

int sn;
Position sol[MAXL*MAXL];

inline void pre() {
   for(int i=0;i<=ar;i++)
      sum[i][0]=0;
   for(int j=0;j<=ac;j++)
      sum[0][j]=0;
   for(int i=0;i<ar;i++)
      for(int j=0;j<ac;j++)
         sum[i+1][j+1]=(long long)sum[i+1][j]+sum[i][j+1]-sum[i][j]+ht[i][j];
}

inline long long getsum(int i1,int i2,int j1,int j2) {
   return sum[i2+1][j2+1]-sum[i2+1][j1]-sum[i1][j2+1]+sum[i1][j1];
}

inline void sweep_col() {
   for(int j=0;j<ac;j++) {
      ql=qr=0;
      for(int i=0;i<ar;i++) {
         while(ql<qr&&que[ql].x<=i-br) ql++;
         while(ql<qr&&que[qr-1].h>=ht[i][j]) qr--;
         que[qr++]=Unit(i,ht[i][j]);
         if(i>=br-1) cmin[i-br+1][j]=que[ql].h;
      }
   }
}

inline void sweep_row() {
   for(int i=0;i<vr;i++) {
      ql=qr=0;
      for(int j=0;j<ac;j++) {
         while(ql<qr&&que[ql].x<=j-bc) ql++;
         while(ql<qr&&que[qr-1].h>=cmin[i][j]) qr--;
         que[qr++]=Unit(j,cmin[i][j]);
         if(j>=bc-1) bmin[i][j-bc+1]=que[ql].h;
      }
   }
}

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }
inline void output() {
   pn=0;
   for(int i=0;i<vr;i++) {
      for(int j=0;j<vc;j++) {
         used[i][j]=0;
         pos[pn++]=Position(i,j,getsum(i,i+br-1,j,j+bc-1)-(long long)bmin[i][j]*br*bc);
      }
   }
   sn=0;
   std::sort(pos,pos+pn);
   for(int pi=0;pi<pn;pi++) {
      int r=pos[pi].r;
      int c=pos[pi].c;
      if(used[r][c]) continue;
      int si=max(0,r-br+1),ti=min(vr,r+br);
      for(int i=si;i<ti;i++) {
         int sj=max(0,c-bc+1),tj=min(vc,c+bc);
         for(int j=sj;j<tj;j++)
            used[i][j]=1;
      }
      sol[sn++]=pos[pi];
   }
   printf("%d\n",sn);
   for(int i=0;i<sn;i++)
      sol[i].print();
}

inline void solve() {
   pre();
   sweep_col();
   sweep_row();
   output();
}

int main(void)
{
   scanf("%d %d %d %d",&ar,&ac,&br,&bc);
   vr=ar-br+1;
   vc=ac-bc+1;
   for(int i=0;i<ar;i++)
      for(int j=0;j<ac;j++)
         scanf("%d",ht[i]+j);
   solve();
   return 0;
}