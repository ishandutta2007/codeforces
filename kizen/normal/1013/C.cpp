#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)2e5+4;
const LL INF = (LL)1e18;
LL N;
LL arr[NS];
LL ans = INF;

int main(){
    scanf("%lld", &N), N*=2;
    for(LL i=0;i<N;++i) scanf("%lld", arr+i);
    sort(arr, arr+N);

    ans = min(ans, (arr[N/2-1]-arr[0])*(arr[N-1]-arr[N/2]));
    for(LL i=1;i<N/2;++i) ans = min(ans, (arr[i+N/2-1]-arr[i])*(arr[N-1]-arr[0]));
    printf("%lld", ans);

    return 0;
}