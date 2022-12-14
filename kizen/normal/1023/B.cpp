#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL N, k;

int main(){
    scanf("%lld %lld", &N, &k);
    LL A, B;
    if(N>=k) A = 1, B = k-1;
    else{
        B = N, A = k-B;
    }
    if(A>=B) puts("0");
    else{
        printf("%lld", (B-A+1)/2);
    }

    return 0;
}