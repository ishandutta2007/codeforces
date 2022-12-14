#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL NS = (LL)2e5+4;
LL N;
LL arr[NS], ans[NS];

int main(){
    scanf("%lld", &N);
    for(LL i=1;i<=N/2;++i) scanf("%lld", arr+i);
    LL val = 0;
    for(LL i=1;i<=N/2;++i){
        if(i>1) val = max(val, arr[i]-ans[N-i+2]);
        ans[i] = val, ans[N-i+1] = arr[i]-val;
    }
    for(LL i=1;i<=N;++i) printf("%lld ", ans[i]);
    return 0;
}