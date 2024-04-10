#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int N,K,i,j,k,l;
long long A[1000005],sol;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++){
        scanf("%d",&j);
        if (j==2) K++;
    }
    if (N==K){
        sol=1;
        for (i=2; i<=N; i++){
            sol *= i;
            sol %= MOD;
        }
        printf("%lld\n",sol);
        return 0;
    }
    //izracunati A do N-K
    A[1] = 1;
    A[2] = 2;
    for (i=3; i<=N-K; i++) A[i] = (A[i-1] + (i-1)*A[i-2]) % MOD;
    sol = A[N-K];
    //domnozavamo
    for (i=N-K+1; i<=N; i++){
        sol *= i;
        sol %= MOD;
    }
    printf("%lld\n",sol);
    return 0;
}