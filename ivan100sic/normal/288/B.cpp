#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007ll
using namespace std;

int N,K;
long long sol0[10] = {0,1,2,9,64,625,7776,117649,2097152};
long long a,b,c;

int main(){
    scanf("%d%d",&N,&K);
    a = sol0[K];
    b = N-K;
    if (N==K){
        printf("%lld\n",a);
        return 0;
    }
    b=1;
    for (int i=1; i<=N-K; i++){
        b *= (N-K);
        b %= MOD;
    }
    printf("%lld\n",(a*b)%MOD);
    return 0;
}