#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
    LL N, T;
    scanf("%lld %lld", &N, &T);
    while(T--){
        LL x, j;
        scanf("%lld %lld", &x, &j);
        if(N%2==0){
            if(x%2){
                if(j%2) printf("%lld\n", (x-1)*N/2+j/2+1);
                else printf("%lld\n", N*N/2+(x-1)*N/2+j/2);
            }
            else{
                if(j%2==0) printf("%lld\n", (x-1)*N/2+j/2);
                else printf("%lld\n", N*N/2+(x-1)*N/2+j/2+1);
            }
        }
        else{
            if(x%2){
                if(j%2) printf("%lld\n", (x-1)*N/2+j/2+1);
                else printf("%lld\n", N*N/2+1+(x-1)*N/2+j/2);
            }
            else{
                if(j%2==0) printf("%lld\n", (x-2)*N/2+N/2+1+j/2);
                else printf("%lld\n", N*N/2+1+(x-2)*N/2+N/2+j/2+1);
            }
        }
    }

    return 0;
}