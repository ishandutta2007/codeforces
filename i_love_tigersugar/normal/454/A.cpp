#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int main(void) {
    int n,t;
    scanf("%d",&n);
    t=-1;
    REP(i,n) {
        if (i<=n/2) t=t+2; else t=t-2;
        REP(zz,(n-t)/2) printf("*");
        REP(zz,t) printf("D");
        REP(zz,(n-t)/2) printf("*");
        printf("\n");
    }
    return 0;
}