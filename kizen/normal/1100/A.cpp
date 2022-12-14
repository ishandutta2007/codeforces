#include <bits/stdc++.h>

using namespace std;

int N, k;
int arr[104];

int main(){
    scanf("%d %d", &N, &k);
    int sum = 0, val;
    for(int i=0;i<N;++i) scanf("%d", arr+i), sum+=arr[i];
    int ans = 0;
    for(int i=0;i<k;++i){
        val = sum;
        for(int j=i;j<N;j+=k) val-=arr[j];
        ans = max(ans, abs(val));
    }
    printf("%d", ans);
    return 0;
}