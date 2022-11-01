#include <stdio.h>

#define fo(i,n) for (i=0;i<n;i++)
#define sq(a) ((a)*(a))
int x[25], y[25], n, dp[1<<24], bt0[1<<24], bt1[1<<24];

int main() {
    int i, j, k;
    scanf("%d%d%d",x+24,y+24,&n);
    fo(i,n)
        scanf("%d%d",x+i,y+i);
    fo(i,1<<n)
        if (i) {
            dp[i]=1<<30;
            k = -1;
            fo(j,n)
                if ((i>>j)&1)
                    k = j;
            fo(j,n)
                if ((i>>j)&1) {
                    int v = dp[i&(~(1<<j))&(~(1<<k))] +
                        sq(x[k]-x[24]) +
                        sq(y[k]-y[24]) +
                        sq(x[j]-x[24]) +
                        sq(y[j]-y[24]) +
                        sq(x[j]-x[k]) +
                        sq(y[j]-y[k]);
                    if (dp[i] > v) {
                        dp[i] = v;
                        bt0[i] = j;
                        bt1[i] = k;
                    }
                }
        }
    printf("%d\n", dp[(1<<n)-1]);
    i=(1<<n)-1;
    printf("0");
    while (i) {
        printf(" %d", bt0[i]+1);
        if (bt0[i] != bt1[i]) printf(" %d", bt1[i]+1);
        printf(" 0");
        i &= (~(1<<bt0[i]))&(~(1<<bt1[i]));
    }
    printf("\n");
    return 0;
}