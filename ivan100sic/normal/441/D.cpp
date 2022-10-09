#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[3005],N,M;

int cyc;
int Ck[3005];

void make_cyc(){
    int i,j;
    memset(Ck,0,sizeof(Ck));
    cyc = 0;
    for (i=1; i<=N; i++) if (Ck[i]==0){
        cyc++;
        Ck[i] = cyc;
        j = A[i];
        while (Ck[j]==0){
            Ck[j] = cyc;
            j = A[j];
        }
    }
    //for (i=1; i<=N; i++) printf("%d %d\n",i,Ck[i]);
}

int main(){
    int i,j,k;
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    scanf("%d",&M);
    M = N-M;
    make_cyc();
    printf("%d\n",abs(cyc-M));
    while (M!=cyc){
        if (cyc > M){
            //spoji neka dva ciklusa (1 i nesto)
            for (i=2; i<=N; i++) if (Ck[i]!=Ck[1]) break;
            swap(A[1],A[i]);
            printf("1 %d ",i);
        } else {
            //razbi jedan ciklus
            for (i=1; i<=N; i++) if (A[i]!=i) break;
            for (j=1; j<=N; j++) if (j!=i && Ck[j]==Ck[i]) break;
            swap(A[i],A[j]);
            printf("%d %d ",i,j);
        }
        make_cyc();
        //break;
    }
    return 0;
}