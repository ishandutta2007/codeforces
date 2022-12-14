#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1004];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;++i) scanf("%d", arr+i);
    sort(arr, arr+N);
    long long ans = 0;
    for(int i=0;i<N-1;++i) ans += arr[i+1]-arr[i]-1;
    printf("%lld", ans);
    return 0;
}