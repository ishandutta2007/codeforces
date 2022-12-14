#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)1e5+4;

LL N, T, k;
LL arr[NS];

int main(){
    scanf("%lld %lld %lld", &N, &T, &k);
    for(LL i=1;i<=N;++i) scanf("%lld", arr+i);
    LL ans = 0;
    for(LL i=1;i<=N;++i) if(arr[i]>k){
        ++ans;
        while(arr[i+1]>k) ++i;
    }
    while(T--){
        LL num, A, B;
        scanf("%lld", &num);
        if(num){
            scanf("%lld %lld", &A, &B);
            arr[A]+=B;
            if(arr[A]-B<=k&&arr[A]>k){
                if(arr[A-1]<=k&&arr[A+1]<=k) ++ans;
                if(arr[A-1]>k&&arr[A+1]>k) --ans;
            }
        }
        else{
            printf("%lld\n", ans);
        }
    }
    return 0;
}