#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[1005],N,M,K,i,j;

int main(){
    scanf("%d%d%d",&N,&M,&K);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    sort(A+1,A+N+1);
    reverse(A+1,A+N+1);
    if (K>=M){
        printf("%d\n",0);
        return 0;
    }
    for (i=1; i<=N; i++){
        K += A[i]-1;
        if (K>=M){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}