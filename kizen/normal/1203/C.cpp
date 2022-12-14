#include <bits/stdc++.h>

using namespace std;

using LL = long long;
LL val;

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    LL N; scanf("%lld", &N); --N;
    scanf("%lld", &val);
    while(N--){
        LL a; scanf("%lld", &a);
        val = gcd(val, a);
    }
    LL ans = 0;
    for(LL i = 1; i * i <= val; ++i){
        if(val % i == 0){
            ++ans;
            if(i * i != val) ++ans;
        }
    }
    printf("%lld\n", ans);
    return 0;
}