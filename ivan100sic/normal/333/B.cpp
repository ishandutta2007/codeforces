#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char A[1005][1005];
int RF[1005],CF[1005],N,M;
int i,j,x,y,k,sol,m4;

int main(){
    scanf("%d%d",&N,&M);
    for (i=2; i<N; i++) RF[i] = CF[i] = 1;
    for (i=1; i<=M; i++){
        scanf("%d%d",&x,&y);
        RF[x] = 0;
        CF[y] = 0;
    }
    for (i=1; i<=N/2; i++){
        m4 = RF[i] + RF[N-i+1] + CF[i] + CF[N-i+1];
        sol += m4;
    }
    if (N%2==1){
        sol += max(RF[(N+1)/2] , CF[(N+1)/2]);
    }
    printf("%d\n",sol);
    return 0;
}