#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int CrnoK[1005],BeloK[1005],X,Y,N,M,DC[1005],DB[1005];

char S[1005];

void ucitaj(){
    scanf("%d%d%d%d",&N,&M,&X,&Y);
    int i,j;
    for (i=1; i<=N; i++){
        scanf("%s",S+1);
        for (j=1; j<=M; j++){
            if (S[j]=='.') CrnoK[j]++; else BeloK[j]++;
        }
    }
    for (j=1; j<=M; j++){
        CrnoK[j] += CrnoK[j-1];
        BeloK[j] += BeloK[j-1];
    }
}

void resi(){
    int i,j;
    memset(DC,63,sizeof(DC));
    memset(DB,63,sizeof(DB));
    DC[0] = 0;
    DB[0] = 0;
    DC[X] = CrnoK[X];
    DB[X] = BeloK[X];
    for (i=X+1; i<=M; i++){
        for (j=i-X; j>=i-Y && j>=0; j--){
            DC[i] = min(DC[i] , DB[j] + CrnoK[i] - CrnoK[j]);
            DB[i] = min(DB[i] , DC[j] + BeloK[i] - BeloK[j]);
        }
    }
}

void debug(){
    for (int i=1; i<=M; i++) printf("%d %d\n",DC[i],DB[i]);
}

int main(){
    ucitaj();
    resi();
    //debug();
    printf("%d\n",min(DC[M],DB[M]));
    return 0;
}