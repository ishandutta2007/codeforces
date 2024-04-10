#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int n,k;
int main(void) {
    scanf("%d%d",&n,&k);
    if (n==1) {
        if (k==0) printf("1"); else printf("-1");
        return 0;
    }
    if (n/2>k) {
        printf("-1");
        return 0;
    }
    int t=k-n/2+1;
    REP(i,2*(n/2-1)) printf("%d ",2*t+1+i);
    printf("%d %d ",t,2*t);
    if (n%2==1) printf("1000000000");
    return 0;
}