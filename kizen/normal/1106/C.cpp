#include <bits/stdc++.h>

using namespace std;

const int NS = (int)3e5+4;
int N;
int arr[NS];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;++i) scanf("%d", arr+i);
    sort(arr, arr+N);
    long long ans = 0;
    for(int i=0;i<N/2;++i) ans += (long long)(arr[i]+arr[N-1-i])*(arr[i]+arr[N-1-i]);
    printf("%lld", ans);
    return 0;
}