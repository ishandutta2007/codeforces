#include <cstdio>
const int mod = 1e9 + 7;

int bino[2005][2005];

int main(){
    for (int i=0; i<=2000; i++) {
        bino[i][0] = 1;
        for (int j=1; j<=i; j++) {
            bino[i][j] = bino[i-1][j] + bino[i-1][j-1];
            bino[i][j] %= mod;
        }
    }
    int t, sum = 0;
    scanf("%d",&t);
    long long ret = 1;
    while (t--) {
        int u;
        scanf("%d",&u);
        sum += u;
        ret *= bino[sum - 1][u - 1];
        ret %= mod;
    }
    printf("%lld",ret);
}