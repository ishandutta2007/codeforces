#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)1e5+4;
LL N, k;
LL A[NS], B[NS], big[NS], num[NS];
priority_queue < LL, vector < LL >, greater < LL > > pq;

int main(){
    scanf("%lld %lld", &N, &k);
    for(LL i=1;i<=N;++i) scanf("%lld", A+i);
    for(LL i=1;i<=N;++i) scanf("%lld", B+i);
    for(LL i=1;i<=N;++i){
        if(B[i]>big[A[i]]) num[A[i]] = i;
        big[A[i]] = max(big[A[i]], B[i]);
    }
    for(LL i=1;i<=N;++i) if(num[A[i]]!=i) pq.push(B[i]);
    LL ans = 0;
    for(LL i=1;i<=k;++i) if(!num[i]){
        ans += pq.top(), pq.pop();
    }
    printf("%lld", ans);
    return 0;
}