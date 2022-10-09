#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int P1[100005],P2[100005],PA[100005],C[100005],O[200005];
int A[100005];
int N,M,Z;

inline int getint(){
   char c;
   int r=0;
   while (true){
      c=getchar();
      if (c>40) break;
   }
   while (true){
      r*=10;
      r+=c-48;
      c=getchar();
      if (c<40) break;
   }
   return r;
}

void ucitajisredi(){
    int i,j;
    N=getint();
    M=getint();
    for (i=1; i<=M; i++){
        P1[i]=getint();
        P2[i]=getint();
        C[P1[i]]++;
        C[P2[i]]++;
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
    for (i=1; i<=N; i++) A[i]=getint();
}

queue <int> Q;
bool Sel[100005];

void resi(){
    int i,j,k;
    for (i=1; i<=N; i++) if (A[i]==0) Q.push(i);
    while (!Q.empty()){
        j = Q.front();
        Q.pop();
        if (A[j]!=0) continue;
        Sel[j]=true;
        Z++;
        for (k=PA[j]; k<PA[j+1]; k++){
            A[O[k]]--;
            if (A[O[k]]==0) Q.push(O[k]);
        }
    }
    printf("%d\n",Z);
    for (i=1; i<=N; i++) if (Sel[i]) printf("%d ",i);
}

int main(){
    ucitajisredi();
    resi();
    return 0;
}