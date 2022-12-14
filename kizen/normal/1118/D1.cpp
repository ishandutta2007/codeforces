#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N, M;
int arr[NS];

int main(){
    scanf("%d %d", &N, &M);
    long long sum = 0;
    for(int i=0;i<N;++i) scanf("%d", arr+i), sum += arr[i];
    if(sum<M){
        puts("-1"); return 0;
    }
    sort(arr, arr+N), reverse(arr, arr+N);
    int s = 1, e = N, mid;
    while(s<e){
        mid = (s+e)/2;
        sum = 0;
        for(int i=0;i<N;++i) sum += max(0, arr[i]-i/mid);
        if(sum<M) s = mid+1;
        else e = mid;
    }
    printf("%d", s);
    return 0;
}