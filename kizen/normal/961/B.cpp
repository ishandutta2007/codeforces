#include <bits/stdc++.h>
using namespace std;

const int NS = (1e5)+4;
int N, k;
int arr[NS], awk[NS];
int l[NS], r[NS], hap[NS];

int main(){
    scanf("%d %d", &N, &k);
    int i;
    for(i=0;i<N;i++) scanf("%d", arr+i);
    for(i=0;i<N;i++) scanf("%d", awk+i);
    for(i=0;i<N;i++) l[i] = (i==0? arr[0]*awk[0]:l[i-1]+arr[i]*awk[i]);
    for(i=N-1;i>=0;i--) r[i] = (i==N-1? arr[N-1]*awk[N-1]:arr[i]*awk[i]+r[i+1]);
    int gap = 0;
    for(i=N-1;i>=N-k+1;i--) gap+=arr[i];
    for(i=N-k;i>=0;i--) hap[i] = gap = gap+arr[i]-arr[i+k];
    int ans = 0;
    for(i=0;i<N-k+1;i++) ans = max(ans, l[i-1]+hap[i]+r[i+k]);
    printf("%d", ans);

    return 0;
}