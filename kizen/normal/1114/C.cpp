#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)1e6+4;
LL N, b;
vector < pair < LL, LL > > arr;

int main(){
    scanf("%lld %lld", &N, &b);
    for(LL i=2;i*i<=b;++i) if(b%i==0){
        arr.push_back(make_pair(i, 0));
        while(b%i==0){
            ++arr[(int)arr.size()-1].second, b/=i;
        }
    }
    if(b>=2){
        if(!(int)arr.size()||arr[(int)arr.size()-1].first!=b) arr.push_back(make_pair(b, 1));
        else arr[(int)arr.size()-1].second++;
    }
    LL ans = (LL)1e18;
    for(LL i=0;i<(int)arr.size();++i){
        LL sum = 0;
        for(LL j=arr[i].first;j<=N;j*=arr[i].first){
            if(j%arr[i].first!=0) break;
            sum += N/j;
        }
        ans = min(ans, sum/arr[i].second);
    }
    printf("%lld", ans);
    return 0;
}