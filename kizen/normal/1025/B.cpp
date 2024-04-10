#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)150004;
LL N;
LL arr[NS][3];

void chk(LL x){
    for(LL i=2;i<=N;++i){
        if(arr[i][0]%x&&arr[i][1]%x) return;
    }
    printf("%lld", x);
    exit(0);
}

int main(){
    scanf("%lld", &N);
    for(LL i=1;i<=N;++i) scanf("%lld %lld", arr[i], arr[i]+1);
    LL A = arr[1][0], B = arr[1][1];
    for(LL i=2;i*i<=A;++i) if(A%i==0){
        while(A%i==0) A/=i;
        chk(i);
    }
    if(A>1) chk(A);
    for(LL i=2;i*i<=B;++i) if(B%i==0){
        while(B%i==0) B/=i;
        chk(i);
    }
    if(B>1) chk(B);
    puts("-1");

    return 0;
}