#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int C[100005],N,M;

void ucitajisredi(){
    scanf("%d%d",&N,&M);
    int i,p1,p2;
    for (i=1; i<=M; i++){
        scanf("%d%d",&p1,&p2);
        C[p1]++;
        C[p2]++;
    }
}

int main(){
    ucitajisredi();
    //ring je najlaksi
    bool nesto=true;
    int i,j,k;
    for (i=1; i<=N; i++) if (C[i]!=2) nesto=false;
    if (nesto){
        printf("ring topology\n");
        return 0;
    }
    nesto = true;
    for (i=1; i<=N; i++) if (C[i]==N-1) break;
    if (i==N+1) nesto=false;
    for (j=1; j<=N; j++) if (i!=j && C[j]!=1) nesto=false;
    if (nesto){
        printf("star topology\n");
        return 0;
    }
    k=2;
    for (i=1; i<=N; i++) if (C[i]>k) k=C[i];
    if (k==2){
        printf("bus topology\n");
        return 0;
    }
    printf("unknown topology\n");
    return 0;
}