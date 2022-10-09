#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int A[2005],Inv[2005],N,holes,ends,i,j,k;
long long D[2005];

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    for (i=1; i<=N; i++){
        if (A[i]!=-1) Inv[A[i]] = i;
    }
    for (i=1; i<=N; i++){
        if (Inv[i]!=0 && A[i]==-1) ends++; else
        if (Inv[i]==0 && A[i]==-1) holes++;
    }
    D[0] = 1;
    for (i=2; i<=ends; i++){
        D[0] *= i;
        D[0] %= MOD;
    }
    D[1] = (D[0] * ends) % MOD;
    for (i=2; i<=holes; i++){
        D[i] = D[i-1]*(ends+i-1)+D[i-2]*(i-1);
        D[i] %= MOD;
    }
    printf("%d\n",(int)(D[holes]));
    return 0;
}