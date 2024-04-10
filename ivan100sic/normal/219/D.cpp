#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200005
using namespace std;

int P1[MAXN],P2[MAXN],C[MAXN],O[2*MAXN],PA[MAXN];
bool I[2*MAXN];
int RedRoad[MAXN],Depth[MAXN];
int RedTotal,N,i,j,NN,Sol;

int Vr[MAXN],Out[MAXN];

void ucitajisredi(){
    scanf("%d",&N);
    int i,j;
    for (i=1; i<N; i++){
        scanf("%d%d",P1+i,P2+i);
        C[P1[i]]++;
        C[P2[i]]++;
    }
    PA[1] = 1;
    for (i=2; i<=N+1; i++) PA[i] = C[i-1] + PA[i-1];
    memset(C,0,sizeof(C));
    for (i=1; i<N; i++){
        O[C[P1[i]]+PA[P1[i]]] = P2[i];
        O[C[P2[i]]+PA[P2[i]]] = P1[i];
        I[C[P2[i]]+PA[P2[i]]] = true;
        C[P1[i]]++;
        C[P2[i]]++;
    }
}

void dfs(int x,int odakle){
    int i,j,k;
    for (i=PA[x]; i<PA[x+1]; i++){
        j = O[i];
        if (j!=odakle){
            Depth[j] = Depth[x] + 1;
            RedRoad[j] = RedRoad[x];
            if (I[i]){
                RedRoad[j]++;
                RedTotal++;
            }
            dfs(j,x);
        }
    }
}

int main(){
    ucitajisredi();
    dfs(1,1);
    Sol = N+1;
    for (i=1; i<=N; i++){
        Vr[i] = RedTotal - 2*RedRoad[i] + Depth[i];
        if (Vr[i] < Sol) Sol = Vr[i];
    }
    for (i=1; i<=N; i++){
        if (Vr[i]==Sol){
            NN++;
            Out[NN] = i;
        }
    }
    printf("%d\n",Sol);
    for (i=1; i<=NN; i++) printf("%d ",Out[i]);
    return 0;
}