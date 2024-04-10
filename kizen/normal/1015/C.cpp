#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)1e5+4;
LL N, M;
LL arr[NS][3];
vector < LL > num;

int main(){
    scanf("%lld %lld", &N, &M);
    for(LL i=0;i<N;++i) scanf("%lld %lld", arr[i], arr[i]+1);
    LL cnt = 0;
    for(LL i=0;i<N;++i) cnt += arr[i][0];
    for(LL i=0;i<N;++i) num.push_back(arr[i][0]-arr[i][1]);
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());

    if(cnt<=M){
        puts("0");
        return 0;
    }
    for(LL i=0;i<(LL)num.size();++i){
        cnt -= num[i];
        if(cnt<=M){
            printf("%lld", i+1);
            return 0;
        }
    }
    puts("-1");

    return 0;
}