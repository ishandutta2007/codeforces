#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N;
int arr[NS];
int sum[2];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i) scanf("%d", arr+i), sum[i%2]+=arr[i];
    int ans = 0, val[2] = {0, 0};
    for(int i=1;i<=N;++i){
        sum[1] -= arr[i];
        swap(sum[0], sum[1]);
        if(val[0]+sum[0]==val[1]+sum[1]) ++ans;
        swap(val[0], val[1]);
        val[0] += arr[i];
    }
    printf("%d", ans);
    return 0;
}