#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL T;
LL N;
LL arr[(LL)1e6+4], brrN, brr[(LL)1e6+4];

int main(){
    scanf("%lld", &T);
    while(T--){
        scanf("%lld", &N);
        for(LL i=0;i<N;++i) scanf("%lld", arr+i);
        sort(arr, arr+N);
        brrN = 0;
        for(LL i=0;i<N-1;++i) if(arr[i]==arr[i+1]){
            brr[brrN++] = arr[i], ++i;
        }

        LL A = brr[0], B = brr[1], P = (brr[0]+brr[1])*(brr[0]+brr[1]), S = brr[0]*brr[1];
        for(LL i=1;i<brrN-1;++i){
            LL SS = brr[i]*brr[i+1], PP = (brr[i]+brr[i+1])*(brr[i]+brr[i+1]);
            if(SS*P>S*PP){
                A = brr[i], B = brr[i+1], S = SS, P = PP;
            }
        }
        printf("%lld %lld %lld %lld\n", A, B, A, B);
    }

    return 0;
}