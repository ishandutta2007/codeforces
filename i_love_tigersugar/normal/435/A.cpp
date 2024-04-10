#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int main(void) {
    int n,m;
    scanf("%d%d",&n,&m);
    int res=1;
    int rem=m;
    REP(zz,n) {
        int v;
        scanf("%d",&v);
        if (rem<v) {
            rem=m;
            res++;
        }
        rem-=v;
    }
    printf("%d",res);
    return 0;
}