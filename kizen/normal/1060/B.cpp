#include <bits/stdc++.h>

using namespace std;

int main(){
    long long N;
    long long A, B, ans = 0;
    scanf("%lld", &N);
    A = 0;
    while(A*10+9<=N) A = A*10+9;
    B = N-A;
    while(A) ans += A%10, A/=10;
    while(B) ans += B%10, B/=10;
    printf("%lld", ans);
    return 0;
}