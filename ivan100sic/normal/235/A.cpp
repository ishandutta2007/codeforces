#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long N,i,j,k,a,b;

long long gcd(long long a,long long b){
    long long t;
    while (b>0){
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

long long lcm(long long a,long long b,long long c){
    long long d=a*b/gcd(a,b);
    return c*d/gcd(c,d);
}

int main(){
    scanf("%I64d",&N);
    for (i=max(1ll,N-100); i<=N; i++){
        for (j=i; j<=N; j++){
            for (k=j; k<=N; k++){
                b = lcm(i,j,k);
                if (b>a) a=b;
            }
        }
    }
    printf("%I64d\n",a);
    return 0;
}