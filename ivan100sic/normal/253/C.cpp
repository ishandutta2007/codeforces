#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int D[105][100005];
int N,x0,y0,xe,ye,i,j,k,l,Dst;
int A[100005],Qx[10000005],Qy[10000005];
int qs,qe,newpts;

void obidji(int x,int y){
   if (x<1 || x>N) return;
   if (y<1) return;
   if (y>A[x]+1) y=A[x]+1;
   if (D[x][y] != -1) return;
   newpts++;
   D[x][y] = Dst;
   Qx[qe+newpts] = x;
   Qy[qe+newpts] = y;
}

void bfs(){
   D[x0][y0] = 0;
   qs=1;
   qe=1;
   newpts=1;
   Qx[1] = x0;
   Qy[1] = y0;
   Dst=0;
   while (newpts>0){
      newpts = 0;
      Dst++;
      for (i=qs; i<=qe; i++){
         obidji(Qx[i]+1 , Qy[i]);
         obidji(Qx[i]-1 , Qy[i]);
         obidji(Qx[i] , Qy[i]+1);
         obidji(Qx[i] , Qy[i]-1);
      }
      qs = qe+1;
      qe += newpts;
   }
}

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   scanf("%d",&N);
   memset(D,255,sizeof(D));
   for (i=1; i<=N; i++) scanf("%d",A+i);
   scanf("%d%d%d%d",&x0,&y0,&xe,&ye);
   bfs();
   printf("%d\n",D[xe][ye]);
   return 0;
}