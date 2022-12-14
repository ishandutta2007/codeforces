#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, ans = 0;
    scanf("%d", &N);
    while(N--){
        int a, b;
        scanf("%d %d", &a, &b);
        ans = max(ans, a+b);
    }
    printf("%d", ans);
    return 0;
}