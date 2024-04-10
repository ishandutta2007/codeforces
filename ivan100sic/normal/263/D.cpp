#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int P1[100005],P2[100005],PA[100005],C[100005],O[200005];
int N,M,K;

void ucitaj(){
    scanf("%d%d%d",&N,&M,&K);
    int i,j,k;
    for (i=1; i<=M; i++){
        scanf("%d%d",P1+i,P2+i);
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
}

int Stek[100005],SH;
int D[100005];

void ispisi(int l,int r){
    int i,j;
    printf("%d\n",r-l+1);
    for (i=l; i<=r; i++) printf("%d%c",Stek[i],i==r?'\n':' ');
    exit(0);
}


void dfs(int x,int depth){
    SH++;
    Stek[SH] = x;
    D[x] = depth;
    int i,j;
    for (i=PA[x]; i<PA[x+1]; i++){
        j = O[i];
        if (D[j]==0){
            dfs(j,depth+1);
        } else {
            if (D[x] - D[j] >= K){
                ispisi(D[j],D[x]);
            }
        }
    }
}

int main(){
    ucitaj();
    dfs(1,1);
}