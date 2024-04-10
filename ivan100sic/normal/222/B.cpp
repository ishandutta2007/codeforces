#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int R[1005],C[1005],A[1005][1005],N,M,Q,i,j,k,l,a,b,c,x,y,t;
char S[105];

int main(){
    scanf("%d%d%d",&N,&M,&Q);
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++) scanf("%d",A[i]+j);
    }
    for (i=1; i<=N; i++) R[i] = i;
    for (i=1; i<=M; i++) C[i] = i;
    while (Q--){
        scanf("%s%d%d",S+1,&x,&y);
        if (S[1]=='g'){
            printf("%d\n",A[R[x]][C[y]]);
        } else
        if (S[1]=='r'){
            t = R[x];
            R[x] = R[y];
            R[y] = t;
        } else {
            t = C[x];
            C[x] = C[y];
            C[y] = t;
        }
    }
    return 0;
}