#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[55],i,j,k,N,K;

int main(){
    scanf("%d%d",&N,&K);
    if (K>N){
        printf("-1\n");
        return 0;
    }
    for (i=1; i<=N; i++) scanf("%d",A+i);
    sort(A+1,A+N+1);
    printf("%d %d\n",A[N-K+1],A[N-K+1]);
    return 0;
}