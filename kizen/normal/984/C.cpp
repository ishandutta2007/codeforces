#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL INF = 1e18;
LL a, b, c;
LL arr[104], N;

LL gcd(LL x, LL y){
    return (y==0? x:gcd(y, x%y));
}

int main(){
//    freopen("input.txt", "r", stdin);

    LL t;
    scanf("%I64d", &t);
    while(t--){
        scanf("%I64d %I64d %I64d", &a, &b, &c);
        if(a==0) puts("Finite");
        else{
            N = 0;
            LL num = gcd(a, b);
            a/=num, b/=num;
            LL f = 1;
            while(b>1){
                num = gcd(b, c);
                if(num==1){
                    f = 0; puts("Infinite"); break;
                }
                LL nu = num;
                while(INF/nu>=num&&b%(nu*num)==0) nu*=num;
                while(nu>=num){
                    while(b%nu==0) b/=nu;
                    nu/=num;
                }
            }
            if(f) puts("Finite");
        }
    }

    return 0;
}