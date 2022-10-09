#include <cstdio>
#include <cstring>
#include <algorithm>
#define HOFF 1131779
using namespace std;

int P1[1000005],P2[1000005],PA[1000005],C[1000005],O[2000005],N,M,i,j,k,l;
int P1w[3000005],P2w[3000005],PAw[3000005],Cw[3000005],Ow[6000005];
long long Hash[1000005],Hashw[1000005],sol,streak;

void ucitajisredi(){
   scanf("%d%d",&N,&M);
   int i,j,k;
   for (i=1; i<=M; i++){
      scanf("%d%d",&j,&k);
      C[j]++;
      C[k]++;
      P1[i]=j;
      P2[i]=k;
   }
   PA[1] = 1;
   for (i=2; i<=N+1; i++) PA[i] = PA[i-1] + C[i-1];
   memset(C,0,sizeof(C));
   for (i=1; i<=M; i++){
      O[C[P1[i]]+PA[P1[i]]] = P2[i];
      O[C[P2[i]]+PA[P2[i]]] = P1[i];
      C[P1[i]]++;
      C[P2[i]]++;
   }
   for (i=1; i<=N; i++){
      sort(O+PA[i] , O+PA[i+1]);
   }
}

void napravizaparove(){
   int i,j,k,l;
   for (i=1; i<=M; i++){
      Cw[P1[i]]++;
      Cw[P2[i]]++;
      P1w[i]=P1[i];
      P2w[i]=P2[i];
   }
   for (i=1; i<=N; i++){
      P1w[i+M] = i;
      P2w[i+M] = i;
      Cw[i]++;
   }
   PAw[1] = 1;
   for (i=2; i<=N+1; i++) PAw[i] = PAw[i-1] + Cw[i-1];
   memset(Cw,0,sizeof(Cw));
   for (i=1; i<=M+N; i++){
      Ow[Cw[P1w[i]]+PAw[P1w[i]]] = P2w[i];
      if (P1w[i]!=P2w[i]) Ow[Cw[P2w[i]]+PAw[P2w[i]]] = P1w[i];
      Cw[P1w[i]]++;
      if (P1w[i]!=P2w[i]) Cw[P2w[i]]++;
   }
   for (i=1; i<=N; i++){
      sort(Ow+PAw[i] , Ow+PAw[i+1]);
   }
}

void hesiraj(){
   int i,j,k;
   for (i=1; i<=N; i++){
      for (j=PA[i]; j<PA[i+1]; j++){
         Hash[i]*=HOFF;
         Hash[i]+=O[j];
      }
   }
}

void hesirajw(){
   int i,j,k;
   for (i=1; i<=N; i++){
      for (j=PAw[i]; j<PAw[i+1]; j++){
         Hashw[i]*=HOFF;
         Hashw[i]+=Ow[j];
      }
   }
}

void resi(){
   int i,j,k;
   sort(Hash+1,Hash+N+1);
   Hash[0] = -779777797777779ll;
   for (i=1; i<=N; i++){
      if (Hash[i]==Hash[i-1]) streak++; else streak=0;
      sol+=streak;
   }
   for (i=1; i<=M; i++){
      if (Hashw[P1[i]] == Hashw[P2[i]]) sol++;
   }
}

void debug(){
   for (i=1; i<=N; i++) printf("%I64d\n",Hash[i]);
   for (i=1; i<=N; i++) printf("%d %d\n",i,PAw[i]);
}

int main(){
   ucitajisredi();
   napravizaparove();
   hesiraj();
   hesirajw();
   resi();
   //debug();
   printf("%I64d\n",sol);
   return 0;
}