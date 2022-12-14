#include <bits/stdc++.h>

using namespace std;

int N, arr[104];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i) scanf("%d", arr+i);
    int ans = 0;
    for(int i=2;i<N;++i) if(!arr[i]&&arr[i-1]&&arr[i+1]){
        ++ans, arr[i+1] = 0;
    }
    printf("%d", ans);
    return 0;
}