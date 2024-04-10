#include <stdio.h>
#include <string.h>
#define MAXL 505

const int inf=1000000000;

int rn,cn;
int gr[MAXL][MAXL];

int sum[MAXL][MAXL];
int val[MAXL][MAXL][4];

inline void pre() {
   memset(sum,0,sizeof(sum));
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         sum[i+1][j+1]=gr[i][j]+sum[i][j+1]+sum[i+1][j]-sum[i][j];
}

inline int get(int r1,int r2,int c1,int c2) {
   return sum[r2+1][c2+1]-sum[r1][c2+1]-sum[r2+1][c1]+sum[r1][c1];
}

inline int solve() {
   int opt=-inf;
   pre();
   for(int l=1;l<=rn&&l<=cn;l+=2) {
      int z=(l>>1);
      int zz=z&3;
      int nz=zz^2;
      for(int i=0;i+l<=rn;i++) {
         for(int j=0;j+l<=cn;j++) {
            if(l==1) val[i][j][zz]=gr[i][j];
            else val[i][j][zz]=get(i,i+l-1,j,j+l-1)
                               -get(i+1,i+l-2,j+1,j+l-2)
                               -gr[i+1][j]+(l>3?gr[i+2][j+1]:0)
                               +val[i+2][j+2][nz];
            if(l>1&&val[i][j][zz]>opt) opt=val[i][j][zz];
            //printf("%d %d %d(%d): %d<%d,%d>\n",i,j,l,zz,val[i][j][zz],nz,val[i+2][j+2][nz]);
         }
      }
   }
   return opt;
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         scanf("%d",gr[i]+j);
   printf("%d\n",solve());
   return 0;
}