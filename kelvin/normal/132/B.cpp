#include <stdio.h>
#include <string.h>
#define MAXL 55
#define MAXT 50000500
#define MAXREC (MAXL*MAXL)

class Rectangle {
   public:
      int r1,r2,c1,c2;
      Rectangle() {}
      Rectangle(int _r1,int _r2,int _c1,int _c2):r1(_r1),r2(_r2),c1(_c1),c2(_c2) {}
};

int adj[4][2]={1,0, 0,1, -1,0, 0,-1};

int rn,cn,step;
char gr[MAXL][MAXL];

int recn;
int bp,dp,cp;
int recid[MAXL][MAXL];
Rectangle rec[MAXREC];

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline bool valid(int r,int c) { return r>=0&&r<rn&&c>=0&&c<cn; }

void fill(int r,int c,int id) {
   recid[r][c]=id;
   rec[id].r1=min(rec[id].r1,r);
   rec[id].r2=max(rec[id].r2,r);
   rec[id].c1=min(rec[id].c1,c);
   rec[id].c2=max(rec[id].c2,c);
   for(int i=0;i<4;i++) {
      int nr=r+adj[i][0];
      int nc=c+adj[i][1];
      if(!valid(nr,nc)) continue;
      if(gr[nr][nc]!=gr[r][c]) continue;
      if(recid[nr][nc]!=-1) continue;
      fill(nr,nc,id);
   }
}

inline void pre() {
   memset(recid,-1,sizeof(recid));
   recn=0;
   for(int i=0;i<rn;i++) {
      for(int j=0;j<cn;j++) {
         if(gr[i][j]=='0') continue;
         if(recid[i][j]==-1) {
            rec[recn].r1=rec[recn].r2=i;
            rec[recn].c1=rec[recn].c2=j;
            fill(i,j,recn++);
         }
      }
   }
}

inline char solve() {
   pre();
   bp=0;
   dp=1;
   cp=1;
   for(int t=0;t<step;t++) {
      //printf("<%d %d %d>\n",bp,dp,cp);
      Rectangle re=rec[bp];
      int r1=re.r1,r2=re.r2,c1=re.c1,c2=re.c2;
      int r,c;
      if(dp==0) {
         r=r2;
         if(cp==1) c=c2;
         else c=c1;
      } else if(dp==1) {
         c=c2;
         if(cp==1) r=r1;
         else r=r2;
      } else if(dp==2) {
         r=r1;
         if(cp==1) c=c1;
         else c=c2;
      } else if(dp==3) {
         c=c1;
         if(cp==1) r=r2;
         else r=r1;
      }
      //printf("[%d %d]\n",r,c);
      int nr=r+adj[dp][0];
      int nc=c+adj[dp][1];
      if(!valid(nr,nc)||gr[nr][nc]=='0') {
         if(cp==1) {
            cp=-1;
         } else {
            cp=1;
            dp=(dp+3)&3;
         }
      } else {
         bp=recid[nr][nc];
      }
   }
   return gr[rec[bp].r1][rec[bp].c1];
}

int main(void)
{
   scanf("%d %d",&rn,&step);
   for(int i=0;i<rn;i++)
      scanf("%s",gr[i]);
   cn=strlen(gr[0]);
   printf("%c\n",solve());
   return 0;
}