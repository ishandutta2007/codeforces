#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)2e5+4;
LL N, k, s;
LL ans[NS];

int main(){
    scanf("%lld %lld %lld", &N, &k, &s);
    if((N-1)*k<s||s<k){
        puts("NO");
        return 0;
    }
    for(LL i=1;i<=k;++i) ans[i] = 1;
    s-=k;
    for(LL i=1;i<=k;++i){
        ans[i] += min(N-2, s);
        s-=min(N-2, s);
    }
    sort(ans+1, ans+k+1);
    reverse(ans+1, ans+k+1);
    puts("YES");
    LL pos = 1;
    for(LL i=1;i<=k;++i){
        if(i%2) pos += ans[i];
        else pos -= ans[i];
        printf("%lld ", pos);
    }

    return 0;
}