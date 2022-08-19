#include <cstdio>

long long mod = 1e9 + 7;
int main(){
    int a,b;
    long long r = 0;
    scanf("%d %d",&a,&b);
    for (int i=1; i<=b-1; i++) {
        long long piv1 = 1ll * a * (a+1) / 2;
        long long piv2 = 1ll * i * b;
        piv1 %= mod;
        piv2 %= mod;
        piv1 *= piv2;
        piv1 %= mod;
        piv1 += 1ll * i * a;
        piv1 %= mod;
        r += piv1;
    }
    int t = (int)(r % mod);
    printf("%d",t);
}