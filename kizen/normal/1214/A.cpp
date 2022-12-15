#include <bits/stdc++.h>

using namespace std;

int N, A, B;

int main(){
    scanf("%d %d %d", &N, &A, &B);
    int ans = (int)1e9;
    for(int j = 0; j * B <= N; j += 5){
        int i = (N - j * B) / A;
        if(N >= A * i + B * j) ans = min(ans, N - A * i - B * j);
    }
    printf("%d\n", ans);
    return 0;
}