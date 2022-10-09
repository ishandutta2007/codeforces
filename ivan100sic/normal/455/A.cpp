#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long A[100005],N,i,j,k,l;
long long C[100005],D[100005];

int main(){
    scanf("%lld",&N);
    for (i=1; i<=N; i++){
        scanf("%lld",A+i);
        C[A[i]]++;
    }
    D[0] = 0;
    D[1] = C[1];
    for (i=2; i<=100000; i++){
        D[i] = max(D[i-2] + i*C[i] , D[i-1]);
    }
    printf("%lld\n",D[100000]);
    return 0;
}