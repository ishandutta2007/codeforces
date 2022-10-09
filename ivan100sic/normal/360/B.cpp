#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long D[2005];
long long A[2005],N,K,i,j,k;

int main(){
    scanf("%lld%lld",&N,&K);
    for (i=1; i<=N; i++) scanf("%lld",A+i);
    long long l,r,m,o;
    o=-1;
    l=0;
    r=4000000000ll;
    while (l<=r){
        m = (l+r)/2;
        D[1] = 1;
        for (i=2; i<=N; i++){
            D[i] = 1;
            for (j=1; j<i; j++){
                if (abs(A[i] - A[j]) <= m*(i-j)){
                    D[i] = max(D[i],D[j]+1);
                }
            }
        }
        k=0;
        for (i=1; i<=N; i++) k = max(k,D[i]);
        if (k >= N-K){
            o = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    printf("%lld\n",o);
    return 0;
}