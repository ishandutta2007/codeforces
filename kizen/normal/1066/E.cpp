#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)2e5+4;
LL N, M;
LL A[NS], B[NS];

int main(){
    scanf("%lld %lld", &N, &M);
    for(LL i=1;i<=N;++i) scanf("%1lld", A+i);
    for(LL i=1;i<=M;++i) scanf("%1lld", B+i), B[i] += B[i-1];
    LL val = 1, ans = 0;
    for(LL i=N;i>=1;--i) if(M-(N-i)>=1){
        if(A[i]) ans = (ans+val*B[M-(N-i)])%998244353;
        val = val*2%998244353;
    }
    printf("%lld\n", ans);
    return 0;
}