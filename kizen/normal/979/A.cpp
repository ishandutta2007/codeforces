#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL N;

int main(){
    scanf("%I64d", &N);
    N++;
    if(N%2&&N!=1){
        printf("%I64d", N);
    }
    else if(N==1) puts("0");
    else{
        printf("%I64d", N/2);
    }

    return 0;
}