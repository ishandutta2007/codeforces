#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
char s[MAX];
int n,k;
int main(void) {
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    if (n-k>k-1) {
        REP(zz,k-1) printf("LEFT\n");
        FOR(i,1,n) {
            printf("PRINT %c\n",s[i]);
            if (i<n) printf("RIGHT\n");
        }
    }
    else {
        REP(zz,n-k) printf("RIGHT\n");
        FORD(i,n,1) {
            printf("PRINT %c\n",s[i]);
            if (i>1) printf("LEFT\n");
        }
    }
    return 0;
}