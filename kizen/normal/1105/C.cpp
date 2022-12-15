#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)2e5+4, MOD = (LL)1e9+7;
LL N, l, r;
LL d[NS][3];
LL A, B, C;

int main(){
    scanf("%lld %lld %lld", &N, &l, &r);
    A = r/3-((l-1)/3);
    B = (r-1)/3-max((l-2), (LL)0)/3; if(l==1) ++B;
    C = (r-2)/3-max((l-3), (LL)0)/3; if(l<=2&&r>=2) ++C;
    d[1][0] = A, d[1][1] = B, d[1][2] = C;
    for(LL i=2;i<=N;++i){
        d[i][0] = ((d[i-1][0]*A+d[i-1][1]*C)%MOD+d[i-1][2]*B)%MOD;
        d[i][1] = ((d[i-1][0]*B+d[i-1][1]*A)%MOD+d[i-1][2]*C)%MOD;
        d[i][2] = ((d[i-1][0]*C+d[i-1][1]*B)%MOD+d[i-1][2]*A)%MOD;
    }
    printf("%lld", d[N][0]);
    return 0;
}