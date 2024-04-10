#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[100005],N,K,i,j,k;

bool eq=true;

int main(){
    scanf("%d%d",&N,&K);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    k = A[K];
    for (j=K+1; j<=N; j++) if (A[j]!=k) eq=false;
    j = K;
    while (A[j-1]==k) j--;
    if (eq) printf("%d\n",j-1); else printf("-1\n");
    return 0;
}