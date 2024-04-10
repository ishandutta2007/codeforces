#include <bits/stdc++.h>

using namespace std;

const long long NS = (long long)3e5+4;
long long N, k;
struct Data{
    long long a, b;
}arr[NS];
priority_queue < long long, vector < long long >, greater < long long > > pq;

int main(){
    scanf("%lld %lld", &N, &k);
    for(long long i=0;i<N;++i) scanf("%lld %lld", &arr[i].a, &arr[i].b);
    sort(arr, arr+N, [&](Data&A, Data&B){return A.b>B.b;});
    long long ans = 0, sum = 0;
    for(long long i=0;i<N;++i){
        sum += arr[i].a, pq.push(arr[i].a);
        if((int)pq.size()>k){
            sum -= pq.top(), pq.pop();
        }
        ans = max(ans, sum*arr[i].b);
    }
    printf("%lld\n", ans);
    return 0;
}