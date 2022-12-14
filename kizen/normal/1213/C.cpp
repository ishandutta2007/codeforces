#include <bits/stdc++.h>

using namespace std;

int T;
int chk[14];
using LL = long long;

int main(){
    scanf("%d", &T);
    while(T--){
        LL A, B;
        scanf("%lld %lld", &A, &B);
        LL gap = B * 2, CNT = 1;
        while(gap % 10 != B % 10){
            gap += B, ++CNT;
        }
        memset(chk, 0, sizeof(chk));
        LL val = B, cnt = 1, ans = 0;
        while(1){
            if(val > A) break;
            if(chk[val % 10]) break;
            chk[val % 10] = 1;
            ans += (val % 10) * (max((LL)0, (A - val) / (CNT * B)) + 1);
            val += B, ++cnt;
        }
        printf("%lld\n", ans);
    }
    return 0;
}