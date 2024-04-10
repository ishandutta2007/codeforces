#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)1e5+4;
LL N;
LL A[NS], B[NS];

int main(){
    scanf("%lld", &N);
    for(LL i=0;i<N;++i) scanf("%lld %lld", A+i, B+i);
    sort(A, A+N), sort(B, B+N);
    LL ans = 0;
    for(LL i=0;i<N;++i) ans += max(A[i], B[i]);
    printf("%lld", ans+N);
    return 0;
}