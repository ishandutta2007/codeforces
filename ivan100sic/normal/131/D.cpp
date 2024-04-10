#include <cstdio>
#include <cstring>
using namespace std;

int St[9000],P1[9000],P2[9000],PA[9000],O[9000],C[9000],Dst[9000];
bool budzistek,V[9000];
int N,i,j,k,l,m,n,SH,rt;

void ucitajisredi(){
   long i,j;
   scanf("%d",&N);
   for (i=1; i<=N; i++){
      scanf("%d%d",&P1[i],&P2[i]);
      C[P1[i]]++;
      C[P2[i]]++;
   }
   PA[1]=1;
   for (i=2; i<=N+1; i++) PA[i]=PA[i-1]+C[i-1];
   memset(C,0,sizeof(C));
   for (i=1; i<=N; i++){
      O[PA[P1[i]]+C[P1[i]]]=P2[i];
      C[P1[i]]++;
      O[PA[P2[i]]+C[P2[i]]]=P1[i];
      C[P2[i]]++;
   }
   memset(Dst,255,sizeof(Dst));
}

void dfs(int x,int odakle){
   int i;
   if (V[x] && budzistek){
      budzistek=false;
      rt=x;
   }
   if (budzistek){
      SH++;
      St[SH]=x;
      V[x]=true;
      for (i=PA[x]; i<PA[x+1]; i++) if (O[i]!=odakle) dfs(O[i],x);
      if (budzistek){
         SH--;
      }
   }
}

void stackunwind(){
   while (true){
      Dst[St[SH]]=0;
      if (St[SH]==rt) break;
      SH--;
   }
}

void dfs2(int x,int d){
   int i;
   if (Dst[x]>0) return;
   if ((d==0)&&(Dst[x]==-1)) return;
   if ((Dst[x]==0)&&(d>0)) return;
   Dst[x]=d;
   for (i=PA[x]; i<PA[x+1]; i++) dfs2(O[i],d+1);
}

int main(){
   ucitajisredi();
   budzistek=true;
   dfs(1,1);
   stackunwind();
   for (i=1; i<=N; i++) dfs2(i,0);
   for (i=1; i<N; i++) printf("%d ",Dst[i]);
   printf("%d",Dst[N]);
   return 0;
}