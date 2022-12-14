#include <bits/stdc++.h>

using namespace std;

long long N, h;
long long arr[1004], brr[1004];

int main(){
    scanf("%d %d", &N, &h);
    for(long long i=1;i<=N;++i) scanf("%lld", brr+i);
    long long val = 0, ans = 0;
    for(long long j=N;j>=1;--j){
        val = 0;
        for(long long i=1;i<=j;++i) arr[i] = brr[i];
        sort(arr+1, arr+j+1);
        for(long long i=2+j%2;i<=j;i+=2){
            val += arr[i];
        }
        if(j%2) val += arr[1];
        if(val<=h){
            printf("%lld\n", j); return 0;
        }
    }
    return 0;
}