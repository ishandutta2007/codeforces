#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)3e5+3453;
LL N;
LL arr[4][NS];
LL sum[4][NS];
LL up[NS], down[NS], hap[NS];

int main(){
    scanf("%lld", &N);
    for(LL i=1;i<=2;++i) for(LL j=1;j<=N;++j) scanf("%lld", arr[i]+j);
    for(LL j=1;j<=N;++j){
        if(j%2){
            sum[1][j] = sum[1][j-1]+arr[1][j]*((j-1)*2);
            sum[2][j] = sum[1][j]+arr[2][j]*((j-1)*2+1);
        }
        else{
            sum[2][j] = sum[2][j-1]+arr[2][j]*((j-1)*2);
            sum[1][j] = sum[2][j]+arr[1][j]*((j-1)*2+1);
        }
    }
    for(LL i=N;i>=1;--i){
        hap[i] = arr[1][i]+arr[2][i]+hap[i+1];
    }
    for(LL i=N/2*2+1;i>=1;i-=2){
        LL pos = (i-1)*2;
        up[i] = up[i+2]-hap[i+2]*2+pos*arr[1][i]+(pos+1)*arr[1][i+1]+
                arr[2][i]*(N*2-1)+arr[2][i+1]*(N*2-2);
    }
    for(LL i=N/2*2;i>=1;i-=2){
        LL pos = (i-1)*2;
        down[i] = down[i+2]-hap[i+2]*2+arr[2][i]*pos+(pos+1)*arr[2][i+1]+
                arr[1][i]*(N*2-1)+arr[1][i+1]*(N*2-2);
    }

    LL ans = 0;
    for(LL i=0;i<=N;i+=2){
        ans = max(ans, sum[1][i]+up[i+1]);
    }
    for(LL i=1;i<=N;i+=2){
        ans = max(ans, sum[2][i]+down[i+1]);
    }
    printf("%lld", ans);

    return 0;
}