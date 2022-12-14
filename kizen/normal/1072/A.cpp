#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M, k;
    scanf("%d %d %d", &N, &M, &k);
    int ans = 0;
    while(k--){
        ans += N+N+M+M-4;
        N-=4, M-=4;
    }
    printf("%d", ans);
    return 0;
}