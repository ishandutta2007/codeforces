#include <bits/stdc++.h>

using namespace std;

const long long NS = (long long)1e5+4;
long long N, k, A, B;
long long arr[NS];

long long sol(long long s, long long e){
    long long a = lower_bound(arr+1, arr+k+1, s)-arr;
    long long b = lower_bound(arr+1, arr+k+1, e+1)-arr;
    if(b-a==0) return A;
    if(s==e) return B*(b-a);
    long long rv = 0;
    rv = sol(s, (s+e)/2)+sol((s+e)/2+1, e);
    return min(rv, (long long)B*(b-a)*(e-s+1));
}

int main(){
    scanf("%lld %lld %lld %lld", &N, &k, &A, &B);
    for(long long i=1;i<=k;++i) scanf("%lld", arr+i);
    sort(arr+1, arr+k+1);
    printf("%lld", sol(1, 1<<N));
    return 0;
}