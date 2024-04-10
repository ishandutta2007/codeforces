#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)1e5 + 4;

LL N, M, k;
LL arr[NS];

int main(){
    scanf("%lld %lld %lld", &M, &N, &k);
    for(LL i = 1; i <= N; ++i){
        scanf("%lld", arr + i);
    }
    LL ans = 0;
    for(LL i = 1; i <= N; ++i){
        ++ans;
        LL pos = (arr[i] - i) / k + 1;
        LL j = i;
        while(j < N && (arr[j + 1] - i) / k + 1 == pos){
            ++j;
        }
        i = j;
    }
    printf("%lld\n", ans);
    return 0;
}