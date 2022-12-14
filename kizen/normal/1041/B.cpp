#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL A, B, X, Y;
LL gcd(LL l, LL r){
    if(r==0) return l;
    return gcd(r, l%r);
}

int main(){
    scanf("%lld %lld %lld %lld", &A, &B, &X, &Y);
    LL val = gcd(X, Y);
    X/=val, Y/=val;
    printf("%lld", min(A/X, B/Y));
    return 0;
}