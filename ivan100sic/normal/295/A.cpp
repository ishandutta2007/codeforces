#include <cstdio>
#include <cstring>
#include <algorithm>
#define MN 100005
using namespace std;

long long A0[MN],B[MN],C[MN],X[MN],Y[MN],L[MN],R[MN],D[MN],N,M,K,i,j,k,l;

int main(){
    scanf("%I64d%I64d%I64d",&N,&M,&K);
    for (i=1; i<=N; i++) scanf("%I64d",A0+i);
    for (i=1; i<=M; i++){
        scanf("%I64d%I64d%I64d",L+i,R+i,D+i);
    }
    for (i=1; i<=K; i++){
        scanf("%I64d%I64d",X+i,Y+i);
    }
    for (i=1; i<=K; i++){
        B[X[i]]++;
        B[Y[i]+1]--;
    }
    for (i=1; i<=M; i++) B[i]+=B[i-1];
    for (i=1; i<=M; i++){
        D[i] *= B[i];
    }
    for (i=1; i<=M; i++){
        C[L[i]] += D[i];
        C[R[i]+1] -= D[i];
    }
    for (i=1; i<=N; i++) C[i] += C[i-1];
    for (i=1; i<=N; i++) printf("%I64d%c",C[i]+A0[i],i==N?'\n':' ');
    return 0;
}