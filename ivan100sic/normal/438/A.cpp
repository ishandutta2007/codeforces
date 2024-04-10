#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[100005],N,M,i,j,x,y;
long long sol;

int main(){
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    for (i=1; i<=M; i++){
        scanf("%d%d",&x,&y);
        sol += min(A[x],A[y]);
    }
    printf("%lld\n",sol);
    return 0;
}