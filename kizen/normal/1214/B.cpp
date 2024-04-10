#include <bits/stdc++.h>

using namespace std;

int N, A, B;

int main(){
    scanf("%d %d %d", &A, &B, &N);
    int ans = 0;
    for(int i = 0; i <= N; ++i){
        if(i <= A && N - i <= B) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}