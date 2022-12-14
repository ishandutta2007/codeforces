#include <bits/stdc++.h>

using namespace std;

const long long NS = (long long)1e5+4;
long long N;
long long arr[NS];
long long val[NS], sum[NS];

int main(){
    scanf("%lld", &N);
    for(long long i=1;i<=N;++i) scanf("%lld", arr+i);
    sort(arr+1, arr+N+1);
    for(long long i=2;i<=N;++i) val[i] = arr[i]-arr[i-1]-1;
    long long Q; scanf("%lld", &Q);
    sort(val+1, val+N+1);
    for(long long i=2;i<=N;++i) sum[i] = val[i]+sum[i-1];
    while(Q--){
        long long l, r; scanf("%lld %lld", &l, &r);
        printf("%lld\n", arr[N]+r-l+1-arr[1]-(sum[N]-sum[lower_bound(val+1, val+N+1, r-l+1)-val-1]-(N-(lower_bound(val+1, val+N+1, r-l+1)-val)+1)*(r-l)));
    }
    return 0;
}