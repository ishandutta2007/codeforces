#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[5005],N,i,j,C[5005];

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    for (i=1; i<=N; i++) C[A[i]]++;
    for (i=1; i<=N; i++) if (C[i]==0) j++;
    printf("%d\n",j);
    return 0;
}