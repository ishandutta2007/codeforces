#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[5005],N,M,i,j,k,l;
int D[5005];

double no;

int main(){
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++) scanf("%d%lf",A+i,&no);
    D[1] = 1;
    for (i=2; i<=N; i++){
        D[i] = 1;
        for (j=1; j<i; j++) if (A[j]<=A[i]) D[i] = max(D[i],D[j]+1);
    }
    for (i=1; i<=N; i++) k = max(k,D[i]);
    printf("%d\n",N-k);
    return 0;
}