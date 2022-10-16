#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int sum[MAX];
void process(void) {
    int n;
    scanf("%d",&n);
    int res=0;
    FOR(i,1,n) {
        int v;
        sum[i]=sum[i-1]^i;
        if (n/i%2) res^=sum[i-1];
        res^=sum[n%i];
        scanf("%d",&v);
        res^=v;
    }
    printf("%d",res);
}
int main(void) {
    process();
    return 0;
}