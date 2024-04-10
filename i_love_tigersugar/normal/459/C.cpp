#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int d,n,k;
int res[MAX][MAX];
int cur[MAX];
void process(void) {
    scanf("%d%d%d",&n,&k,&d);
    FOR(i,1,d) cur[i]=1;
    FOR(j,1,n) {
        FOR(i,1,d) res[i][j]=cur[i];
        if (j==n) break;
        int t=d;
        while (t>=1 && cur[t]==k) t--;
        if (t<1) {
            printf("-1");
            return;
        }
        cur[t]++;
        FOR(l,t+1,d) cur[l]=1;
    }
    FOR(i,1,d) FOR(j,1,n) {
        printf("%d",res[i][j]);
        if (j<n) printf(" "); else printf("\n");
    }
}
int main(void) {
    process();
    return 0;
}