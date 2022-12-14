#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL INF = (LL)1e9;
LL N, M, k;
LL A[2004], B[2004];
LL AL[2004], BL[2004];
int main(){
    scanf("%lld %lld", &N, &M);
    for(LL i=1;i<=N;++i) scanf("%lld", A+i);
    for(LL i=1;i<=M;++i) scanf("%lld", B+i);
    scanf("%lld", &k);
    for(LL i=0;i<2004;++i) AL[i] = BL[i] = INF;
    for(LL i=1;i<=N;++i){
        LL cnt = 0;
        for(LL j=i;j<=N;++j){
            cnt += A[j];
            AL[j-i+1] = min(AL[j-i+1], cnt);
        }
    }
    for(LL i=1;i<=M;++i){
        LL ccnt = 0;
        for(LL j=i;j<=M;++j){
            ccnt += B[j];
            BL[j-i+1] = min(BL[j-i+1], ccnt);
        }
    }
    LL ans = 0;
    for(LL i=0;i<2004;++i) for(LL j=0;j<2004;++j) if(AL[i]*BL[j]<=k) ans = max(ans, i*j);
    printf("%lld", ans);
    return 0;
}