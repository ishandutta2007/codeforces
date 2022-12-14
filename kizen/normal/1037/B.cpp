#include <bits/stdc++.h>

using namespace std;

#define FOR(i, N) for(int i=0;i<(N);++i)

const int NS = (int)2e5+4;
int N, k;
int arr[NS];

int main(){
    scanf("%d %d", &N, &k);
    FOR(i, N) scanf("%d", arr+i);
    sort(arr, arr+N);

    long long ans = 0;
    FOR(i, N/2+1) if(arr[i]>k) ans += arr[i]-k, arr[i] = k;
    for(int i=N/2;i<N;++i) if(arr[i]<k) ans += k-arr[i], arr[i] = k;
    printf("%lld", ans);

    return 0;
}